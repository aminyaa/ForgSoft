#pragma once
#ifndef _Aft3d_SegmentEdgeAnIsoFwd_Header
#define _Aft3d_SegmentEdgeAnIsoFwd_Header

#include <Mesh_BndEdge_Position.hxx>

namespace AutLib
{
	// Forward Declarations
	template<class BndEdgeTraits, Mesh_BndEdge_Position POS>
	class Aft_TBndEdge;

	struct Aft3d_SegmentEdgeAnIsoTraits;

	typedef Aft_TBndEdge<Aft3d_SegmentEdgeAnIsoTraits, Mesh_BndEdge_Position_Segment>
		Aft3d_SegmentEdgeAnIso;
}

#endif // !_Aft3d_SegmentEdgeAnIsoFwd_Header
