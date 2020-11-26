#pragma once
#ifndef _Aft3d_SegmentNodeFwd_Header
#define _Aft3d_SegmentNodeFwd_Header

#include <Mesh_BndNode_Position.hxx>

namespace tnbLib
{

	// Forward Declarations
	template<class BndNodeTraits, Mesh_BndNode_Position POS>
	class Mesh_TBndNode;

	struct Aft3d_TBndNodeTraits;

	typedef Mesh_TBndNode<Aft3d_TBndNodeTraits, Mesh_BndNode_Position_Segment>
		Aft3d_SegmentNode;
}

#endif // !_Aft3d_SegmentNodeFwd_Header