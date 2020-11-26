#pragma once
#ifndef _Aft2d_tPlnRegionSurfaceFwd_Header
#define _Aft2d_tPlnRegionSurfaceFwd_Header

#include <Geo2d_SizeFunctionFwd.hxx>
#include <Geo2d_MetricFunctionFwd.hxx>

namespace tnbLib
{

	// Forward Declarations
	template<class CurveType, class SizeFun, class MetricFun>
	class Mesh_PlnRegion;

	class TModel_ParaCurve;

	typedef Mesh_PlnRegion<TModel_ParaCurve, Geo2d_SizeFunction, Geo2d_MetricFunction>
		Aft2d_tPlnRegionSurface;
}


#endif // !_Aft2d_tPlnRegionSurfaceFwd_Header