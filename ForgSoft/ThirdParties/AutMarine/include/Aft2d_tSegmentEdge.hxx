#pragma once
#ifndef _Aft2d_tSegmentEdge_Header
#define _Aft2d_tSegmentEdge_Header

#include <Aft_TBndEdge.hxx>
#include <Aft2d_tBndEdgeSurfaceTraits.hxx>

namespace AutLib
{
	typedef Aft_TBndEdge<Aft2d_tBndEdgeSurfaceTraits, Mesh_BndEdge_Position_Segment>
		Aft2d_gSegmentEdge;
}

#endif // !_Aft2d_tSegmentEdge_Header
