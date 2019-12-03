#pragma once
#ifndef _Mesh2d_PlnRegionAnIsoFwd_Header
#define _Mesh2d_PlnRegionAnIsoFwd_Header

#include <Geo2d_SizeFunctionFwd.hxx>
#include <Geo2d_MetricFunctionFwd.hxx>
#include <Mesh2d_PlnCurveFwd.hxx>
#include <Mesh2d_PlnWireFwd.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class CurveType, class SizeFun, class MetricFun>
	class Mesh_PlnRegion;

	class Pln_Curve;

	typedef Mesh_PlnRegion<Pln_Curve, Geo2d_SizeFunction, Geo2d_MetricFunction>
		Mesh2d_PlnRegionAnIso;
}

#endif // !_Mesh2d_PlnRegionAnIsoFwd_Header
