#pragma once
#ifndef _Aft2d_tSegmentNode_Header
#define _Aft2d_tSegmentNode_Header

#include <Aft_TBndNode.hxx>
#include <Aft2d_tBndNodeSurfaceTraits.hxx>

namespace AutLib
{

	typedef Aft_TBndNode<Aft2d_tBndNodeSurfaceTraits, Mesh_BndNode_Position_Segment>
		Aft2d_tSegmentNode;
}

#endif // !_Aft2d_tSegmentNode_Header
