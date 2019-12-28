#pragma once
#ifndef _Aft2d_CornerNode_Header
#define _Aft2d_CornerNode_Header

#include <Aft_TBndNode.hxx>
#include <Aft2d_TBndNodeTraits.hxx>

namespace AutLib
{

	typedef Aft_TBndNode<Aft2d_TBndNodeTraits, Mesh_BndNode_Position_Corner>
		Aft2d_CornerNode;
}

#endif // !_Aft2d_CornerNode_Header
