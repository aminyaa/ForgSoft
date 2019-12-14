#pragma once
#ifndef _Aft2d_gPlnRegionSurfaceFwd_Header
#define _Aft2d_gPlnRegionSurfaceFwd_Header

#include <Geo2d_SizeFunctionFwd.hxx>
#include <Geo2d_MetricFunctionFwd.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class CurveType, class SizeFun, class MetricFun>
	class Mesh_PlnRegion;

	class GModel_parCurve;

	typedef Mesh_PlnRegion<GModel_parCurve, Geo2d_SizeFunction, Geo2d_MetricFunction>
		Aft2d_gPlnRegionSurface;
}

#endif // !_Aft2d_gPlnRegionSurfaceFwd_Header
