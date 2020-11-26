#pragma once
#ifndef _FrgVisual_Global_Build_Header
#define _FrgVisual_Global_Build_Header

# if defined(FORGVISUAL_LIB)
// Building Library
#  define FORGVISUAL_EXPORT __declspec(dllexport)
# else
// Reading Library
#  define FORGVISUAL_EXPORT __declspec(dllimport)
# endif

#endif // !_FrgVisual_Global_Build_Header
