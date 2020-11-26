#pragma once
#ifndef _Aft3d_SegmentNodeAnIsoFwd_Header
#define _Aft3d_SegmentNodeAnIsoFwd_Header

#include <Mesh_BndNode_Position.hxx>

namespace tnbLib
{

	// Forward Declarations
	template<class BndNodeTraits, Mesh_BndNode_Position POS>
	class Mesh_TBndNode;

	struct Aft3d_SegmentNodeAnIsoTraits;

	typedef Mesh_TBndNode<Aft3d_SegmentNodeAnIsoTraits, Mesh_BndNode_Position_Segment>
		Aft3d_SegmentNodeAnIso;
}

#endif // !_Aft3d_SegmentNodeAnIsoFwd_Header