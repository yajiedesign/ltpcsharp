#pragma once
#include "stdafx.h"
#include "ltpcsharp.h"
#include <string>
#include <memory>
#include <locale>
#include <codecvt>
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
#include "../ltpinclude/segment_dll.h"
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;

namespace ltpcsharp_native {

	ref class Segmentor :LtpCsharp::Common::ISegmentor
	{
		void * wrapper = nullptr;
	public:
		Segmentor(String^path, String^ lexicon_file)
		{
			std::string converted_path = msclr::interop::marshal_as< std::string >(path);
			std::string converted_lexicon_file = msclr::interop::marshal_as< std::string >(lexicon_file);
			wrapper = segmentor_create_segmentor(converted_path.c_str(), converted_lexicon_file.c_str());
			if (wrapper == nullptr)
			{
				throw gcnew ArgumentException("参数错误,初始化失败");
			}
		}
		Segmentor(String^path)
		{
			std::string converted_path = msclr::interop::marshal_as< std::string >(path);
			wrapper = segmentor_create_segmentor(converted_path.c_str());
			if (wrapper == nullptr)
			{
				throw gcnew ArgumentException("参数错误,初始化失败");
			}
		}

		~Segmentor()
		{
			segmentor_release_segmentor(wrapper);
			wrapper = nullptr;
		}
		!Segmentor()
		{
			segmentor_release_segmentor(wrapper);
			wrapper = nullptr;
		}

		virtual	int Segment([In]  String^ line, [Out]  List<String^>^% words)
		{
			std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
			std::string converted_line = conv.to_bytes(msclr::interop::marshal_as<std::wstring>(line));
			std::vector<std::string> vsent;
			int doret = segmentor_segment(wrapper, converted_line, vsent);
			words = Help::CppToCSharp(vsent);
			return doret;
		}


	};
}