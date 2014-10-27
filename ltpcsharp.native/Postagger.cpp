#include "stdafx.h"
#include "ltpcsharp.h"
#include <string>
#include <memory>
#include <locale>
#include <codecvt>
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
#include "../ltpinclude/postag_dll.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;

namespace ltpcsharp_native {
	
	public ref class Postagger
	{
		void * wrapper = nullptr;
	public:
		Postagger(String^path, String^ lexicon_file)
		{
			std::string converted_path = msclr::interop::marshal_as< std::string >(path);
			std::string converted_lexicon_file = msclr::interop::marshal_as< std::string >(lexicon_file);
			wrapper = postagger_create_postagger(converted_path.c_str(), converted_lexicon_file.c_str());
			if (wrapper == nullptr)
			{
				throw gcnew ArgumentException("参数错误,初始化失败");
			}
		}
		Postagger(String^path)
		{
			std::string converted_path = msclr::interop::marshal_as< std::string >(path);
			wrapper = postagger_create_postagger(converted_path.c_str());
			if (wrapper == nullptr)
			{
				throw gcnew ArgumentException("参数错误,初始化失败");
			}
		}
		~Postagger()
		{
			postagger_release_postagger(wrapper);
			wrapper = nullptr;
		}
		!Postagger()
		{
			postagger_release_postagger(wrapper);
			wrapper = nullptr;
		}

		int Postag([In] List<String^>^ words,
			[Out] List<String^>^% tags)
		{
			auto cppwords = Help::CSharpToCpp(words);
			std::vector<std::string> cpptags;
			int doret = postagger_postag(wrapper, cppwords, cpptags);
			tags = Help::CppToCSharp(cpptags);
			return doret;
		}
	};
}