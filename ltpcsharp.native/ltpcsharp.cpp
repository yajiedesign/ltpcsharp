// 这是主 DLL 文件。

#include "stdafx.h"

#include "ltpcsharp.h"


namespace ltpcsharp_native {

	std::vector<std::string> Help::CSharpToCpp(List<String^>^ stringlist)
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
		std::vector<std::string> ret;
		for each (String^ csvar in stringlist)
		{
			std::string converted_str = conv.to_bytes(msclr::interop::marshal_as<std::wstring>(csvar));
			ret.push_back(std::move(converted_str));
		}
		return std::move(ret);
	}

	List<String^>^ Help::CppToCSharp(std::vector<std::string> stringlist)
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
		List<String^>^ ret = gcnew List<String^>();
		for each (std::string csvar in stringlist)
		{
			std::wstring wideStr = conv.from_bytes(csvar);
			ret->Add(msclr::interop::marshal_as< String^ >(wideStr));
		}
		return ret;
	}

	List<int>^ Help::CppToCSharp(std::vector<int> intlist)
	{
		List<int>^ ret = gcnew List<int>();
		for each (int csvar in intlist)
		{
			ret->Add(csvar);
		}
		return ret;
	}
}