#pragma once
#ifndef _Aft2d_tCornerNode_Header
#define _Aft2d_tCornerNode_Header

#include <Mesh_TBndNode.hxx>
#include <Aft2d_tBndNodeSurfaceTraits.hxx>

namespace tnbLib
{
	typedef Mesh_TBndNode<Aft2d_tBndNodeSurfaceTraits, Mesh_BndNode_Position_Corner>
		Aft2d_tCornerNode;
}

#endif // !_Aft2d_tCornerNode_Header