#pragma once
#ifndef _Aft2d_tBndEdgeSurfaceTraits_Header
#define _Aft2d_tBndEdgeSurfaceTraits_Header

#include <Aft2d_BndEdgeSurfaceTraits.hxx>
#include <Geo2d_SizeFunction.hxx>
#include <Geo2d_MetricFunction.hxx>

namespace tnbLib
{

	// Forward Declarations
	class TModel_ParaCurve;

	template<class CrvEntity, class SizeFun, class MetricFun>
	class Mesh_PlnCurve;

	template<class SizeFun, class MetricFun>
	class Geo_MetricPrcsr;

	struct Aft2d_tBndEdgeSurfaceTraits
	{
		typedef Aft2d_BndEdgeSurfaceTraits bndEdgeTraits;

		typedef Mesh_PlnCurve<TModel_ParaCurve, Geo2d_SizeFunction, Geo2d_MetricFunction> curveType;
		typedef void surfType;
		typedef Geo_MetricPrcsr<Geo2d_SizeFunction, Geo2d_MetricFunction> metricPrcsr;
	};
}

#endif // !_Aft2d_tBndEdgeSurfaceTraits_Header