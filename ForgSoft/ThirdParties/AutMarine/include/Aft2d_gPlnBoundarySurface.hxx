#pragma once
#ifndef _Aft2d_gPlnBoundarySurface_Header
#define _Aft2d_gPlnBoundarySurface_Header

#include <Aft_PlnBoundary.hxx>
#include <Geo2d_SizeFunction.hxx>
#include <Geo2d_MetricFunction.hxx>
#include <Aft2d_gSegmentEdge.hxx>
#include <Aft2d_gPlnWireSurface.hxx>
#include <Aft2d_gPlnRegionSurface.hxx>
#include <Aft2d_PlnBoundaryAnIso_Info.hxx>

namespace AutLib
{

	typedef Aft_PlnBoundary<Aft2d_gPlnRegionSurface, Geo2d_SizeFunction, Geo2d_MetricFunction>
		Aft2d_gPlnBoundarySurface;
}

#endif // !_Aft2d_gPlnBoundarySurface_header
