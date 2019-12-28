#pragma once
#ifndef _Mesh2d_KnitNode_Header
#define _Mesh2d_KnitNode_Header

#include <Mesh2d_Node.hxx>
#include <Knit_ChainNode.hxx>

namespace AutLib
{

	typedef Knit_ChainNode<Mesh2d_Node>
		Mesh2d_KnitNode;
}

#endif // !_Mesh2d_KnitNode_Header
