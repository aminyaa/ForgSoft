#pragma once
#ifndef _Global_Macros_Header
#define _Global_Macros_Header

#define MAX(A,B) ((A)>(B) ? (A):(B))
#define MIN(A,B) ((A)<(B) ? (A):(B))

#define ABS(X)   ((X) < 0 ? -(X):(X))

#define MEAN(X1, X2)  0.5*((X1) + (X2))

#define PAUSE  system("pause")

#define NOT                     !
#define NOT_EQUAL               !=
#define IS_EQUAL                ==
#define OR                      ||
#define AND                     &&

#define _SPACE_                << "  " <<
#define _NEWLINE_              << "\n"
#define _GET_NEWLINE_(Stream)  Stream _NEWLINE_

#define MOVE(Object)    return std::move(Object)
#define ReMove(Object)  auto NewObject = Object; return std::move(NewObject);
#define SWAP(Object1, Object2) std::swap(Object1, Object2)

#define IF_NOT_INSIDE(X, _MinValue, _MaxValue)  \
   if(X<_MinValue || X>_MaxValue)

#define IF_NOT_INSIDE2(X1, X2, _MinValue1, _MaxValue1, _MinValue2, _MaxValue2)  \
   if(X1<_MinValue1 || X1>_MaxValue1 || X2<_MinValue2 || X2>_MaxValue2)

#define INSIDE(X, MinValue, MaxValue) (X >= MinValue && X <= MaxValue)

#define forThose(Index, FirstIndex, LastIndex) \
	for(Standard_Integer Index = FirstIndex; Index <= LastIndex; Index++)

#define forThose_Dec(Index, FirstIndex, LastIndex) \
	for(Standard_Integer Index = FirstIndex; Index >= LastIndex; Index--)

#define MaxIndexOf(Object)  \
  (Object).Size() - 1

#define Index_Of(INDEX) \
  INDEX - 1

#define Get_Const_Object(Object)  \
    const auto & Object

#define Get_Const_Pointer(Pointer) \
    const auto * Pointer

#define Get_Object(Object)  \
    auto & Object

#define Get_Pointer(Pointer) \
    auto * Pointer

#define Continue_If(Condition)  \
    if(Condition) continue;

#define Break_If(Condition)  \
    if (Condition) break;

#define Delete_Pointer(Pointer)  { if (Pointer) delete Pointer; Pointer = NULL;}

#define IsNULL(Pointer) Pointer == NULL

#define NULLify(Pointer) if(NOT IsNULL(Pointer)) Delete_Pointer(Pointer);

#define FreeAll(Array)  forThose(Index, 0, MaxIndexOf(Array)) NULLify(Array[Index]);

#define DisallowBitWiseCopy(TypeName)      \
  TypeName(const TypeName&) = delete;      \
  void operator=(const TypeName&) = delete;

#define M_STD         std::
#define M_AUT         AutLib::
#define M_CAD         AutLib::CadLib::
#define M_MESH        AutLib::MeshLib::
#define M_GEO         AutLib::GeoLib::
#define M_NUMER       AutLib::NumLib::
#define M_IO          AutLib::IoLib::
#define M_FV         AutLib::FvLib::

#define M_GEO_SPACE(TYPE) namespace AutLib{namespace GeoLib {class TYPE;}}
#define M_CAD_SPACE(TYPE) namespace AutLib{namespace CadLib {class TYPE;}}
#define M_MESH_SPACE(TYPE) namespace AutLib{namespace MeshLib {class TYPE;}}
#define M_FV_SPACE(TYPE) namespace AutLib{namespace FvLib{class TYPE;}}

#define PI              3.14159265358979323846
#define PI_2            1.57079632679489661923
#define PI_4            0.785398163397448309616 
#define MACHINE_ZERO    1.0E-12
#define EPS6            1.0E-6
#define EPS12           1.0E-12
#define CAD_TOLERANCE   1.0E-3
#define SQRT2           1.41421356237309504880169

#define M_ONE           -(Standard_Integer)1;

#endif // !_Global_Macros_Header
