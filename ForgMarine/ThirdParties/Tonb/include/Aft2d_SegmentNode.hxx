#pragma once
#ifndef _Aft2d_SegmentNode_Header
#define _Aft2d_SegmentNode_Header

#include <Mesh_TBndNode.hxx>
#include <Aft2d_TBndNodeTraits.hxx>

namespace tnbLib
{

	typedef Mesh_TBndNode<Aft2d_TBndNodeTraits, Mesh_BndNode_Position_Segment>
		Aft2d_SegmentNode;
}

#endif // !_Aft2d_SegmentNode_Header