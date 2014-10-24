#include "stdafx.h"
#include "ltpcsharp.h"
#include <string>
#include <memory>
#include <locale>
#include <codecvt>
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
#include "../ltpinclude/ner_dll.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;

namespace ltpcsharp {
	
	public ref class Recognizer
	{
		void * wrapper = nullptr;
	public:
		Recognizer(String^path)
		{
			std::string converted_path = msclr::interop::marshal_as< std::string >(path);
			wrapper = ner_create_recognizer(converted_path.c_str());
			if (wrapper == nullptr)
			{
				throw gcnew ArgumentException("参数错误,初始化失败");
			}
		}
		~Recognizer()
		{
			ner_release_recognizer(wrapper);
			wrapper = nullptr;
		}
		!Recognizer()
		{
			ner_release_recognizer(wrapper);
			wrapper = nullptr;
		}

		int Postag([In] List<String^>^ words,
			[In] List<String^>^ postags,
			[Out] List<String^>^% tags)
		{
			auto cppwords = Help::CSharpToCpp(words);
			auto cpppostags = Help::CSharpToCpp(postags);
			std::vector<std::string> cpptags;
			int doret = ner_recognize(wrapper, cppwords, cpppostags , cpptags);
			tags = Help::CppToCSharp(cpptags);
			return doret;
		}
	};
}