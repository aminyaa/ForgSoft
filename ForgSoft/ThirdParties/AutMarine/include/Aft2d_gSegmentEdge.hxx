#pragma once
#ifndef _Aft2d_gSegmentEdge_Header
#define _Aft2d_gSegmentEdge_Header

#include <Aft_TBndEdge.hxx>
#include <Aft2d_gBndEdgeSurfaceTraits.hxx>

namespace AutLib
{
	typedef Aft_TBndEdge<Aft2d_gBndEdgeSurfaceTraits, Mesh_BndEdge_Position_Segment>
		Aft2d_gSegmentEdge;
}

#endif // !_Aft2d_gSegmentEdge_Header
