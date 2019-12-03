#pragma once
#ifndef _Mesh2d_PlnRegionAnIso_Header
#define _Mesh2d_PlnRegionAnIso_Header

#include <Mesh_PlnRegion.hxx>
#include <Mesh2d_PlnCurveAnIsoFwd.hxx>
#include <Mesh2d_PlnWireAnIsoFwd.hxx>

namespace AutLib
{

	// Forward Declarations
	class Pln_Curve;

	typedef Mesh_PlnRegion<Pln_Curve, Geo2d_SizeFunction, Geo2d_MetricFunction>
		Mesh2d_PlnRegionAnIso;
}

#endif // !_Mesh2d_PlnRegionAnIso_Header

