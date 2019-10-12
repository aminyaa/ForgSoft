#pragma once
#ifndef _Merge2d_Pnt_Header
#define _Merge2d_Pnt_Header

#include <Pnt2d.hxx>
#include <Stl_Vector.hxx>
#include <Merge_Pnt.hxx>

namespace AutLib
{
	typedef Merge_Pnt<Pnt2d, Stl_Vector, Merge_PntAlg_Mean>
		Merge2d_Pnt;
}

#endif // !_Merge2d_Pnt_Header
