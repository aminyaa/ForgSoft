#pragma once
#ifndef _ForgGuiGlobalsBuild_Header
#define _ForgGuiGlobalsBuild_Header

# if defined(FORGGUI_LIB)
#  define FORGGUI_EXPORT __declspec(dllexport)
# else
#  define FORGGUI_EXPORT __declspec(dllimport)
# endif

#endif // !_ForgGuiGlobalsBuild_Header
