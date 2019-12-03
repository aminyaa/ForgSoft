#pragma once
#ifndef _Aft2d_TBndEdgeTraits_Header
#define _Aft2d_TBndEdgeTraits_Header

#include <Aft2d_BndEdgeTraits.hxx>
#include <Geo2d_SizeFunction.hxx>

namespace AutLib
{

	// Forward Declarations
	class Pln_Curve;

	template<class CrvEntity, class SizeFun, class MetricFun>
	class Mesh_PlnCurve;

	struct Aft2d_TBndEdgeTraits
	{

		typedef Aft2d_BndEdgeTraits bndEdgeTraits;

		typedef Mesh_PlnCurve<Pln_Curve, Geo2d_SizeFunction, void> curveType;
		typedef void surfType;
	};
}

#endif // !_Aft2d_TBndEdgeTraits_Header
