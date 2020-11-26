#pragma once
#ifndef _Aft2d_SegmentNodeAnIsoFwd_Header
#define _Aft2d_SegmentNodeAnIsoFwd_Header

#include <Mesh_BndNode_Position.hxx>

namespace tnbLib
{

	// Forward Declarations
	template<class BndNodeTraits, Mesh_BndNode_Position POS>
	class Mesh_TBndNode;

	struct Aft2d_TBndNodeAnIsoTraits;

	typedef Mesh_TBndNode<Aft2d_TBndNodeAnIsoTraits, Mesh_BndNode_Position_Segment>
		Aft2d_SegmentNodeAnIso;
}

#endif // !_Aft2d_SegmentNodeAnIsoFwd_Header