#pragma once
#ifndef _Aft2d_TBndNodeTraits_Header
#define _Aft2d_TBndNodeTraits_Header

#include <Aft2d_BndNodeTraits.hxx>
#include <Geo2d_SizeFunction.hxx>

namespace tnbLib
{

	// Forward Declarations
	class Pln_Curve;

	template<class CrvEntity, class SizeFun, class MetricFun>
	class Mesh_PlnCurve;

	struct Aft2d_TBndNodeTraits
	{

		typedef Aft2d_BndNodeTraits bndNodeTraits;

		typedef Mesh_PlnCurve<Pln_Curve, Geo2d_SizeFunction, void> curveType;
		typedef void surfType;
	};
}

#endif // !_Aft2d_TBndNodeTraits_Header