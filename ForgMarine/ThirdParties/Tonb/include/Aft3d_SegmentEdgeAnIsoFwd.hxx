#pragma once
#ifndef _Aft3d_SegmentEdgeAnIsoFwd_Header
#define _Aft3d_SegmentEdgeAnIsoFwd_Header

#include <Mesh_BndEdge_Position.hxx>

namespace tnbLib
{
	// Forward Declarations
	template<class BndEdgeTraits, Mesh_BndEdge_Position POS>
	class Mesh_TBndEdge;

	struct Aft3d_SegmentEdgeAnIsoTraits;

	typedef Mesh_TBndEdge<Aft3d_SegmentEdgeAnIsoTraits, Mesh_BndEdge_Position_Segment>
		Aft3d_SegmentEdgeAnIso;
}

#endif // !_Aft3d_SegmentEdgeAnIsoFwd_Header