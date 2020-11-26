#pragma once
#ifndef _Aft3d_SegmentEdgeFwd_Header
#define _Aft3d_SegmentEdgeFwd_Header

#include <Mesh_BndEdge_Position.hxx>

namespace tnbLib
{
	// Forward Declarations
	template<class BndEdgeTraits, Mesh_BndEdge_Position POS>
	class Mesh_TBndEdge;

	struct Aft3d_SegmentEdgeTraits;

	typedef Mesh_TBndEdge<Aft3d_SegmentEdgeTraits, Mesh_BndEdge_Position_Segment>
		Aft3d_SegmentEdge;
}

#endif // !_Aft3d_SegmentEdgeFwd_Header