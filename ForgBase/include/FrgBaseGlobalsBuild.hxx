#pragma once
#ifndef _FrgBaseGlobalsBuild_Header
#define _FrgBaseGlobalsBuild_Header

# if defined(FORGBASE_LIB)
#  define FORGBASE_EXPORT __declspec(dllexport)
# else
#  define FORGBASE_EXPORT __declspec(dllimport)
# endif

#endif // !_FrgBaseGlobalsBuild_Header
