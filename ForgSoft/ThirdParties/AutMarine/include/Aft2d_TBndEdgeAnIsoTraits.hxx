#pragma once
#ifndef _Aft2d_TBndEdgeAnIsoTraits_Header
#define _Aft2d_TBndEdgeAnIsoTraits_Header

#include <Aft2d_BndEdgeAnIsoTraits.hxx>
#include <Geo2d_SizeFunction.hxx>
#include <Geo2d_MetricFunction.hxx>

namespace AutLib
{

	// Forward Declarations
	class Pln_Curve;

	template<class CrvEntity, class SizeFun, class MetricFun>
	class Mesh_PlnCurve;

	template<class SizeFun, class MetricFun>
	class Geo_MetricPrcsr;

	struct Aft2d_TBndEdgeAnIsoTraits
	{

		typedef Aft2d_BndEdgeAnIsoTraits bndEdgeTraits;

		typedef Mesh_PlnCurve<Pln_Curve, Geo2d_SizeFunction, Geo2d_MetricFunction> curveType;
		typedef void surfType;
		typedef Geo_MetricPrcsr<Geo2d_SizeFunction, Geo2d_MetricFunction> metricPrcsr;
	};
}

#endif // !_Aft2d_TBndEdgeAnIsoTraits_Header
