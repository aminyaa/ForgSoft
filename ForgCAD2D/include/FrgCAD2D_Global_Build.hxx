#pragma once
#ifndef _FrgCAD2D_Global_Build_Header
#define _FrgCAD2D_Global_Build_Header

# if defined(FORGCAD2D_LIB)
// Building Library
#  define FORGCAD2D_EXPORT __declspec(dllexport)
# else
// Reading Library
#  define FORGCAD2D_EXPORT __declspec(dllimport)
# endif

#endif // !_FrgCAD2D_Global_Build_Header
