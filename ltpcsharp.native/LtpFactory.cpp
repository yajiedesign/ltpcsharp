#include "stdafx.h"
#include "ltpcsharp.h"
#include <string>
#include <memory>
#include <locale>
#include <codecvt>
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
#include "../ltpinclude/parser_dll.h"

#include "Segmentor.hpp"
#include "Postagger.hpp"
#include "Recognizer.hpp"
#include "Parser.hpp"
#include "Splitsnt.hpp"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;

namespace ltpcsharp_native {


	public ref class LtpFactory :LtpCsharp::Common::ILtpFactory
	{

	public:
		virtual	LtpCsharp::Common::ISegmentor ^CreateSegmentor(System::String ^path)
		{
			return gcnew ltpcsharp_native::Segmentor(path);
		}
		virtual	LtpCsharp::Common::ISegmentor ^CreateSegmentor(System::String ^path, System::String ^lexicon_file)
		{
			return gcnew ltpcsharp_native::Segmentor(path, lexicon_file);
		}
		virtual	LtpCsharp::Common::IPostagger ^CreatePostagger(System::String ^path)
		{
			return gcnew ltpcsharp_native::Postagger(path);
		}
		virtual	LtpCsharp::Common::IPostagger ^CreatePostagger(System::String ^path, System::String ^lexicon_file)
		{
			return gcnew ltpcsharp_native::Postagger(path, lexicon_file);
		}
		virtual	LtpCsharp::Common::IRecognizer ^CreateRecognizer(System::String ^path)
		{
			return gcnew ltpcsharp_native::Recognizer(path);
		}
		virtual	LtpCsharp::Common::IParser ^CreateParser(System::String ^path)
		{
			return gcnew ltpcsharp_native::Parser(path);
		}
		virtual	LtpCsharp::Common::ISplitsnt ^CreateSplitsnt()
		{
			return gcnew ltpcsharp_native::Splitsnt();
		}
	};
}