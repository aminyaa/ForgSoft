#pragma once
#ifndef _Aft2d_tPlnCurveSurfaceFwd_Header
#define _Aft2d_tPlnCurveSurfaceFwd_Header

#include <Geo2d_SizeFunctionFwd.hxx>
#include <Geo2d_MetricFunctionFwd.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class CurveType, class SizeFun, class MetricFun>
	class Mesh_PlnCurve;

	class TModel_parCurve;

	typedef Mesh_PlnCurve<TModel_parCurve, Geo2d_SizeFunction, Geo2d_MetricFunction>
		Aft2d_tPlnCurveSurface;
}

#endif // !_Aft2d_tPlnCurveSurfaceFwd_Header
