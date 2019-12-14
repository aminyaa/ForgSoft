#pragma once
#ifndef _Aft2d_PlnBoundaryAnIso_Header
#define _Aft2d_PlnBoundaryAnIso_Header

#include <Aft_PlnBoundary.hxx>
#include <Geo2d_SizeFunction.hxx>
#include <Geo2d_MetricFunction.hxx>
#include <Aft2d_SegmentEdgeAnIso.hxx>
#include <Aft2d_PlnWireAnIso.hxx>
#include <Aft2d_PlnRegionAnIso.hxx>
#include <Aft2d_PlnBoundaryAnIso_Info.hxx>

namespace AutLib
{

	typedef Aft_PlnBoundary<Aft2d_PlnRegionAnIso, Geo2d_SizeFunction, Geo2d_MetricFunction>
		Aft2d_PlnBoundaryAnIso;
}

#endif // !_Aft2d_PlnBoundaryAnIso_Header
