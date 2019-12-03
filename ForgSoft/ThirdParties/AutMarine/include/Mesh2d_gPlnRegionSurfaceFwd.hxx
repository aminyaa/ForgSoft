#pragma once
#ifndef _Mesh2d_gPlnRegionSurfaceFwd_Header
#define _Mesh2d_gPlnRegionSurfaceFwd_Header

#include <Geo2d_SizeFunctionFwd.hxx>
#include <Geo2d_MetricFunctionFwd.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class CurveType, class SizeFun, class MetricFun>
	class Mesh_PlnRegion;

	class GModel_parCurve;

	typedef Mesh_PlnRegion<GModel_parCurve, Geo2d_SizeFunction, Geo2d_MetricFunction>
		Mesh2d_gPlnRegionSurface;
}

#endif // !_Mesh2d_gPlnRegionSurfaceFwd_Header
