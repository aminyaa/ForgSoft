#pragma once
#ifndef _Knit_ChainNode_Header
#define _Knit_ChainNode_Header

#include <Global_Indexed.hxx>
#include <Global_AccessMethod.hxx>
#include <Knit_ChainNode_Type.hxx>

#include <memory>

namespace AutLib
{

	template<class NodeType>
	class Knit_ChainNode
		: public NodeType
	{

		/*Private Data*/

		Knit_ChainNode_Type theType_;

	public:

		typedef NodeType base;
		typedef typename base::ptType Point;

		Knit_ChainNode(const Standard_Integer theIndex, const Point& theCoord)
			: NodeType(theIndex, theCoord)
		{}

		Knit_ChainNode(const NodeType& theNode)
			: NodeType(theNode)
		{}

		static Standard_Boolean IsLess
		(
			const std::shared_ptr<Knit_ChainNode>& theNode0,
			const std::shared_ptr<Knit_ChainNode>& theNode1
		);

		// Macros
		GLOBAL_ACCESS_PRIM_SINGLE(Knit_ChainNode_Type, Type)
	};
}

#include <Knit_ChainNodeI.hxx>

#endif // !_Knit_ChainNode_Header
