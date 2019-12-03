#pragma once
#ifndef _Mesh2d_PlnCurveSurfaceFwd_Header
#define _Mesh2d_PlnCurveSurfaceFwd_Header

#include <Geo2d_SizeFunctionFwd.hxx>
#include <Geo2d_MetricFunctionFwd.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class CurveType, class SizeFun, class MetricFun>
	class Mesh_PlnCurve;

	class GModel_parCurve;

	typedef Mesh_PlnCurve<GModel_parCurve, Geo2d_SizeFunction, Geo2d_MetricFunction>
		Mesh2d_gPlnCurveSurface;
}

#endif // !_Mesh2d_PlnCurveSurfaceFwd_Header
