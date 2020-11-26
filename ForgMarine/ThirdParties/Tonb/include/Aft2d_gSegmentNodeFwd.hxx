#pragma once
#ifndef _Aft2d_gSegmentNodeFwd_Header
#define _Aft2d_gSegmentNodeFwd_Header

#include <Mesh_BndNode_Position.hxx>

namespace tnbLib
{

	// Forward Declarations
	template<class TBndNodeTraits, Mesh_BndNode_Position POS>
	class Mesh_TBndNode;

	struct Aft2d_gBndNodeSurfaceTraits;

	typedef Mesh_TBndNode<Aft2d_gBndNodeSurfaceTraits, Mesh_BndNode_Position_Segment>
		Aft2d_gSegmentNode;
}


#endif // !_Aft2d_gSegmentNodeFwd_Header