#include "stdafx.h"
#include "ltpcsharp.h"
#include <string>
#include <memory>
#include <locale>
#include <codecvt>
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
#include "../ltpinclude/parser_dll.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;

namespace ltpcsharp_native {

	public ref class Parser
	{
		void * wrapper = nullptr;
	public:
		Parser(String^path)
		{
			std::string converted_path = msclr::interop::marshal_as< std::string >(path);
			wrapper = parser_create_parser(converted_path.c_str());
			if (wrapper == nullptr)
			{
				throw gcnew ArgumentException("参数错误,初始化失败");
			}
		}

		~Parser()
		{
			parser_release_parser(wrapper);
			wrapper = nullptr;
		}
		!Parser()
		{
			parser_release_parser(wrapper);
			wrapper = nullptr;
		}



		int Parse([In] List<String^>^ words,
			[In] List<String^>^ postags,
			[Out] List<int>^% heads,
			[Out] List<String^>^% deprels)
		{

			auto cppwords = Help::CSharpToCpp(words);
			auto cpppostags = Help::CSharpToCpp(postags);

			std::vector<int> cppheads;
			std::vector<std::string> cppdeprels;

			int doret = parser_parse(wrapper, cppwords, cpppostags, cppheads, cppdeprels);

			heads = Help::CppToCSharp(cppheads);
			deprels = Help::CppToCSharp(cppdeprels);
			return doret;
		}


	};
}