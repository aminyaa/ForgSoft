#pragma once
#ifndef _Mesh2d_KnitNodeFwd_Header
#define _Mesh2d_KnitNodeFwd_Header

#include <Mesh2d_NodeFwd.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class NodeType>
	class Knit_ChainNode;

	typedef Knit_ChainNode<Mesh2d_Node>
		Mesh2d_KnitNode;
}

#endif // !_Mesh2d_KnitNodeFwd_Header
