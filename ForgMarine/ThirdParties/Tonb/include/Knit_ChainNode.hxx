#pragma once
#ifndef _Knit_ChainNode_Header
#define _Knit_ChainNode_Header

#include <Geo_GraphNode.hxx>
#include <Knit_ChainNode_Type.hxx>

#include <memory>
#include <map>

namespace tnbLib
{

	template<class NodeTraits>
	class Knit_ChainNode
		: public Geo_GraphNode<NodeTraits>
	{

		typedef typename NodeTraits::nodeType nodeType;

		/*Private Data*/

		Knit_ChainNode_Type theType_;

		std::shared_ptr<nodeType> theNode_;

	public:

		Knit_ChainNode
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<nodeType>& theNode
		)
			: Global_Indexed(theIndex)
			, theNode_(theNode)
		{}


		// Macros
		GLOBAL_ACCESS_PRIM_SINGLE(Knit_ChainNode_Type, Type)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<nodeType>, Node)
	};
}

#include <Knit_ChainNodeI.hxx>

#endif // !_Knit_ChainNode_Header
