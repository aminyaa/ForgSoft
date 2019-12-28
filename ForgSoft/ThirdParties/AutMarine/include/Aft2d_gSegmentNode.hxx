#pragma once
#ifndef _Aft2d_gSegmentNode_Header
#define _Aft2d_gSegmentNode_Header

#include <Aft_TBndNode.hxx>
#include <Aft2d_gBndNodeSurfaceTraits.hxx>

namespace AutLib
{
	typedef Aft_TBndNode<Aft2d_gBndNodeSurfaceTraits, Mesh_BndNode_Position_Segment>
		Aft2d_gSegmentNode;
}

#endif // !_Aft2d_gSegmentNode_Header
