#pragma once
#ifndef _Aft2d_gSegmentEdgeFwd_Header
#define _Aft2d_gSegmentEdgeFwd_Header

#include <Mesh_BndEdge_Position.hxx>

namespace tnbLib
{

	// Forward Declarations
	template<class BndEdgeTraits, Mesh_BndEdge_Position POS>
	class Mesh_TBndEdge;

	struct Aft2d_gBndEdgeSurfaceTraits;

	typedef Mesh_TBndEdge<Aft2d_gBndEdgeSurfaceTraits, Mesh_BndEdge_Position_Segment>
		Aft2d_gSegmentEdge;
}

#endif // !_Aft2d_gSegmentEdgeFwd_Header