#pragma once
#ifndef _Aft2d_tSegmentNodeFwd_Header
#define _Aft2d_tSegmentNodeFwd_Header

#include <Mesh_BndNode_Position.hxx>

namespace tnbLib
{

	// Forward Declarations
	template<class TBndNodeTraits, Mesh_BndNode_Position POS>
	class Mesh_TBndNode;

	struct Aft2d_tBndNodeSurfaceTraits;

	typedef Mesh_TBndNode<Aft2d_tBndNodeSurfaceTraits, Mesh_BndNode_Position_Segment>
		Aft2d_tSegmentNode;
}


#endif // !_Aft2d_tSegmentNodeFwd_Header