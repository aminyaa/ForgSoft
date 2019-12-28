#pragma once
#ifndef _Aft2d_PlnCurveSurfaceFwd_Header
#define _Aft2d_PlnCurveSurfaceFwd_Header

#include <Geo2d_SizeFunctionFwd.hxx>
#include <Geo2d_MetricFunctionFwd.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class CurveType, class SizeFun, class MetricFun>
	class Mesh_PlnCurve;

	class GModel_parCurve;

	typedef Mesh_PlnCurve<GModel_parCurve, Geo2d_SizeFunction, Geo2d_MetricFunction>
		Aft2d_gPlnCurveSurface;
}

#endif // !_Aft2d_PlnCurveSurfaceFwd_Header
