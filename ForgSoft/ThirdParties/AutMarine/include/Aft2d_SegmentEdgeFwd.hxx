#pragma once
#ifndef _Aft2d_SegmentEdgeFwd_Header
#define _Aft2d_SegmentEdgeFwd_Header

#include <Mesh_BndEdge_Position.hxx>

namespace AutLib
{
	// Forward Declarations
	template<class BndEdgeTraits, Mesh_BndEdge_Position POS>
	class Aft_TBndEdge;

	struct Aft2d_SegmentEdgeTraits;

	typedef Aft_TBndEdge<Aft2d_SegmentEdgeTraits, Mesh_BndEdge_Position_Segment>
		Aft2d_SegmentEdge;
}

#endif // !_Aft2d_SegmentEdgeFwd_Header