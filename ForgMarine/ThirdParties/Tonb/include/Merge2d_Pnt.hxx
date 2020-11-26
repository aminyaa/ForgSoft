#pragma once
#ifndef _Merge2d_Pnt_Header
#define _Merge2d_Pnt_Header

#include <Pnt2d.hxx>
#include <Merge_Pnt.hxx>

#include <vector>

namespace tnbLib
{

	template<class T>
	using Stl_Vector = std::vector<T>;

	typedef Merge_Pnt<Pnt2d, Stl_Vector, Merge_PntAlg_Mean>
		Merge2d_Pnt;
}

#endif // !_Merge2d_Pnt_Header