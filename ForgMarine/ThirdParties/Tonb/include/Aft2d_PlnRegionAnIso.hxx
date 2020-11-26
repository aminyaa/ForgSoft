#pragma once
#ifndef _Aft2d_PlnRegionAnIso_Header
#define _Aft2d_PlnRegionAnIso_Header

#include <Mesh_PlnRegion.hxx>
#include <Aft2d_PlnCurveAnIsoFwd.hxx>
#include <Aft2d_PlnWireAnIsoFwd.hxx>

namespace tnbLib
{

	// Forward Declarations
	class Pln_Curve;

	typedef Mesh_PlnRegion<Pln_Curve, Geo2d_SizeFunction, Geo2d_MetricFunction>
		Aft2d_PlnRegionAnIso;
}

#endif // !_Aft2d_PlnRegionAnIso_Header