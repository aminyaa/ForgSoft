#pragma once
#ifndef _FrgMarine_Global_Build_Header
#define _FrgMarine_Global_Build_Header

# if defined(FORGMARINE_LIB)
// Building Library
#  define FORGMARINE_EXPORT __declspec(dllexport)
# else
// Reading Library
#  define FORGMARINE_EXPORT __declspec(dllimport)
# endif

#endif // !_FrgMarine_Global_Build_Header
