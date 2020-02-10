#pragma once
#ifndef _Merge2d_PntFwd_Header
#define _Merge2d_PntFwd_Header

#include <Merge_PntAlg.hxx>

#include <vector>

namespace tnbLib
{

	// Forward Declarations
	class Pnt2d;

	template<class T>
	using Stl_Vector = std::vector<T>;

	template
		<
		class Point,
		template<class> class NodeVector,
		Merge_PntAlg Alg
		>
		class Merge_Pnt;

	typedef Merge_Pnt<Pnt2d, Stl_Vector, Merge_PntAlg_Mean>
		Merge2d_Pnt;
}

#endif // !_Merge2d_PntFwd_Header
