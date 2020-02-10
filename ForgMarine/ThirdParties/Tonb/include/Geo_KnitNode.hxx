#pragma once
#ifndef _Geo_KnitNode_Header
#define _Geo_KnitNode_Header

#include <Global_Macros.hxx>
#include <Geo_GraphNode.hxx>

namespace tnbLib
{

	template<class NodeTraits>
	using Geo_KnitNode = Geo_GraphNode<NodeTraits>;
}

#endif // !_Geo_KnitNode_Header
