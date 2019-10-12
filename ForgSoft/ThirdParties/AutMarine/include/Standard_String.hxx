#pragma once
#ifndef _Standard_String_Header
#define _Standard_String_Header

#include <string>

namespace AutLib
{
	typedef std::string Standard_String;
	
	inline std::wstring utf8toUtf16(const std::wstring & str)
	{
		std::wstring wsTmp(str.begin(), str.end());
		return std::move(wsTmp);
	}
}

using AutLib::Standard_String;

#endif // !_Standard_String_Header
