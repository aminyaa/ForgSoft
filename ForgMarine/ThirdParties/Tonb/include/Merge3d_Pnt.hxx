#pragma once
#ifndef _Merge3d_Pnt_Header
#define _Merge3d_Pnt_Header

#include <Pnt3d.hxx>
#include <Merge_Pnt.hxx>

#include <vector>

namespace tnbLib
{

	template<class T>
	using Stl_Vector = std::vector<T>;

	typedef Merge_Pnt<Pnt3d, Stl_Vector, Merge_PntAlg_Mean>
		Merge3d_Pnt;

}

#endif // !_Merge3d_Pnt_Header