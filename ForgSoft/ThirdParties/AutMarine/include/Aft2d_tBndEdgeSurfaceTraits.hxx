#pragma once
#ifndef _Aft2d_tBndEdgeSurfaceTraits_Header
#define _Aft2d_tBndEdgeSurfaceTraits_Header

#include <Aft2d_BndEdgeSurfaceTraits.hxx>
#include <Geo2d_SizeFunction.hxx>
#include <Geo2d_MetricFunction.hxx>

namespace AutLib
{

	// Forward Declarations
	class TModel_parCurve;

	template<class CrvEntity, class SizeFun, class MetricFun>
	class Mesh_PlnCurve;

	struct Aft2d_tBndEdgeSurfaceTraits
	{
		typedef Aft2d_BndEdgeSurfaceTraits bndEdgeTraits;

		typedef Mesh_PlnCurve<TModel_parCurve, Geo2d_SizeFunction, Geo2d_MetricFunction> curveType;
		typedef void surfType;
	};
}

#endif // !_Aft2d_tBndEdgeSurfaceTraits_Header
