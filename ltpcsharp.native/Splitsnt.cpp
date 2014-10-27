#include "stdafx.h"
#include <string>
#include <locale>
#include <codecvt>
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
#include "../ltpinclude/SplitSentence.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;

int SplitSentenceCpp(const std::string & paragraph,
	std::vector<std::string> & sentences){
	return SplitSentence(paragraph, sentences);
}

namespace ltpcsharp_native {

	public ref class Splitsnt
	{
	public:
		static int SplitSentence([In]  String^ paragraph, [Out] List<String^>^% sentences)
		{
			std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
			std::string converted_paragraph = conv.to_bytes(msclr::interop::marshal_as<std::wstring>(paragraph));
			std::vector<std::string> vsent;
			int SSret = SplitSentenceCpp(converted_paragraph, vsent);;
			for each (std::string svar in vsent)
			{
				std::wstring wideStr = conv.from_bytes(svar);
				sentences->Add(msclr::interop::marshal_as< String^ >(wideStr));
			}
			return SSret;
		}
	};
}