#pragma once
#ifndef _Aft2d_SegmentEdgeAnIso_Header
#define _Aft2d_SegmentEdgeAnIso_Header

#include <Aft_TBndEdge.hxx>
#include <Aft2d_TBndEdgeAnIsoTraits.hxx>

namespace AutLib
{
	typedef Aft_TBndEdge<Aft2d_TBndEdgeAnIsoTraits, Mesh_BndNode_Position_Segment>
		Aft2d_SegmentEdgeAnIso;
}

#endif // !_Aft2d_SegmentEdgeAnIso_Header
