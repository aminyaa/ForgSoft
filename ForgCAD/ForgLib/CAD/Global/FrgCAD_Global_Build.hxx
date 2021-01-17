#pragma once
#ifndef _FrgCAD_Global_Build_Header
#define _FrgCAD_Global_Build_Header

# if defined(FORGCAD_LIB)
// Building Library
#  define FORGCAD_EXPORT __declspec(dllexport)
# else
// Reading Library
#  define FORGCAD_EXPORT __declspec(dllimport)
# endif

#endif // !_FrgCAD_Global_Build_Header
