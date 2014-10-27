// ltpcsharp.h

#pragma once
#include <vector>
#include <string>
#include <memory>
#include <locale>
#include <codecvt>

#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Collections::Generic;

namespace ltpcsharp_native {

	ref class Help
	{
	public:
		static std::vector<std::string> CSharpToCpp(List<String^>^ stringlist);
		static List<String^>^ CppToCSharp(std::vector<std::string> stringlist);
		static List<int>^ CppToCSharp(std::vector<int> stringlist);
	};

}

