#pragma once
#ifndef _Aft2d_tPlnBoundarySurface_Header
#define _Aft2d_tPlnBoundarySurface_Header

#include <Aft_PlnBoundary.hxx>
#include <Geo2d_SizeFunction.hxx>
#include <Geo2d_MetricFunction.hxx>
#include <Aft2d_tSegmentEdge.hxx>
#include <Aft2d_tPlnWireSurface.hxx>
#include <Aft2d_tPlnRegionSurface.hxx>
#include <Aft2d_PlnBoundaryAnIso_Info.hxx>

namespace AutLib
{

	typedef Aft_PlnBoundary<Aft2d_tPlnRegionSurface, Geo2d_SizeFunction, Geo2d_MetricFunction>
		Aft2d_tPlnBoundarySurface;
}

#endif // !_Aft2d_tPlnBoundarySurface_Header
