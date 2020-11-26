#pragma once
#ifndef _Aft2d_SegmentEdgeFwd_Header
#define _Aft2d_SegmentEdgeFwd_Header

#include <Mesh_BndEdge_Position.hxx>

namespace tnbLib
{
	// Forward Declarations
	template<class BndEdgeTraits, Mesh_BndEdge_Position POS>
	class Mesh_TBndEdge;

	struct Aft2d_TBndEdgeTraits;

	typedef Mesh_TBndEdge<Aft2d_TBndEdgeTraits, Mesh_BndEdge_Position_Segment>
		Aft2d_SegmentEdge;
}

#endif // !_Aft2d_SegmentEdgeFwd_Header