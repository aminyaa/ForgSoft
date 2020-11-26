#pragma once
#ifndef _Aft2d_BndNode_Header
#define _Aft2d_BndNode_Header

#include <Mesh_BndNode.hxx>
#include <Aft2d_BndNodeTraits.hxx>

namespace tnbLib
{
	typedef Mesh_BndNode<Aft2d_BndNodeTraits>
		Aft2d_BndNode;
}

#endif // !_Aft2d_BndNode_Header