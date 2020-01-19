#pragma once
#ifndef _FrgBase_Global_Build_Header
#define _FrgBase_Global_Build_Header

# if defined(FORGBASE_LIB)
// Building Library
#  define FORGBASE_EXPORT __declspec(dllexport)
# else
// Reading Library
#  define FORGBASE_EXPORT __declspec(dllimport)
# endif

#endif // !_FrgBase_Global_Build_Header
