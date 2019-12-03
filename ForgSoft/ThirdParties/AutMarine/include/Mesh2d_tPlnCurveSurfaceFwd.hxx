#pragma once
#ifndef _Mesh2d_tPlnCurveSurfaceFwd_Header
#define _Mesh2d_tPlnCurveSurfaceFwd_Header

#include <Geo2d_SizeFunctionFwd.hxx>
#include <Geo2d_MetricFunctionFwd.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class CurveType, class SizeFun, class MetricFun>
	class Mesh_PlnCurve;

	class TModel_parCurve;

	typedef Mesh_PlnCurve<TModel_parCurve, Geo2d_SizeFunction, Geo2d_MetricFunction>
		Mesh2d_tPlnCurveSurface;
}

#endif // !_Mesh2d_tPlnCurveSurfaceFwd_Header
