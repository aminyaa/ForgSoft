#pragma once
#ifndef _Aft2d_PlnBoundary_Header
#define _Aft2d_PlnBoundary_Header

#include <Aft_PlnBoundary.hxx>
#include <Geo2d_SizeFunction.hxx>
#include <Aft2d_SegmentEdge.hxx>
#include <Aft2d_PlnWire.hxx>
#include <Aft2d_PlnRegion.hxx>
#include <Aft2d_PlnBoundary_Info.hxx>

namespace AutLib
{

	typedef Aft_PlnBoundary<Aft2d_PlnRegion, Geo2d_SizeFunction>
		Aft2d_PlnBoundary;
}

#endif // !_Aft2d_PlnBoundary_Header
