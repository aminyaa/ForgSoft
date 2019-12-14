#pragma once
#ifndef _Aft2d_PlnCurveAnIsoFwd_Header
#define _Aft2d_PlnCurveAnIsoFwd_Header

#include <Geo2d_SizeFunctionFwd.hxx>
#include <Geo2d_MetricFunctionFwd.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class CurveType, class SizeFun, class MetricFun>
	class Mesh_PlnCurve;

	class Pln_Curve;

	typedef Mesh_PlnCurve<Pln_Curve, Geo2d_SizeFunction, Geo2d_MetricFunction>
		Aft2d_PlnCurveAnIso;
}

#endif // !_Aft2d_PlnCurveAnIsoFwd_Header
