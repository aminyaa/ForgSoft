#pragma once
#ifndef _Aft2d_SegmentEdge_Header
#define _Aft2d_SegmentEdge_Header

#include <Aft_TBndEdge.hxx>
#include <Aft2d_TBndEdgeTraits.hxx>

namespace AutLib
{
	typedef Aft_TBndEdge<Aft2d_TBndEdgeTraits, Mesh_BndNode_Position_Segment>
		Aft2d_SegmentEdge;
}

#endif // !_Aft2d_SegmentEdge_Header
