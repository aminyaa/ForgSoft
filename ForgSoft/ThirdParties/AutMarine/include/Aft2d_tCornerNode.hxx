#pragma once
#ifndef _Aft2d_tCornerNode_Header
#define _Aft2d_tCornerNode_Header

#include <Aft_TBndNode.hxx>
#include <Aft2d_tBndNodeSurfaceTraits.hxx>

namespace AutLib
{
	typedef Aft_TBndNode<Aft2d_tBndNodeSurfaceTraits, Mesh_BndNode_Position_Corner>
		Aft2d_tCornerNode;
}

#endif // !_Aft2d_tCornerNode_Header
