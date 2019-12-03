#pragma once
#ifndef _Aft2d_tSegmentEdgeFwd_Header
#define _Aft2d_tSegmentEdgeFwd_Header

#include <Mesh_BndEdge_Position.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class BndEdgeTraits, Mesh_BndEdge_Position POS>
	class Aft_TBndEdge;

	struct Aft2d_tBndEdgeSurfaceTraits;

	typedef Aft_TBndEdge<Aft2d_tBndEdgeSurfaceTraits, Mesh_BndEdge_Position_Segment>
		Aft2d_tSegmentEdge;
}

#endif // !_Aft2d_tSegmentEdgeFwd_Header
