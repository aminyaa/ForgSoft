#pragma once
#ifndef _Merge3d_PntFwd_Header
#define _Merge3d_PntFwd_Header

#include <Pnt3d.hxx>
#include <Stl_Vector.hxx>
#include <Merge_PntAlg.hxx>

namespace AutLib
{

	// Forward Declarations
	template
		<
		class Point,
		template<class> class NodeVector,
		Merge_PntAlg Alg
		>
		class Merge_Pnt;

	typedef Merge_Pnt<Pnt3d, Stl_Vector, Merge_PntAlg_Mean>
		Merge3d_Pnt;
}

#endif // !_Merge3d_PntFwd_Header
