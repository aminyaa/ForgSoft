#pragma once
#include <error.hxx>
#include <OSstream.hxx>
namespace AutLib
{

	template<class NodeType>
	Standard_Boolean Knit_ChainNode<NodeType>::IsLess
	(
		const std::shared_ptr<Knit_ChainNode>& theNode0,
		const std::shared_ptr<Knit_ChainNode>& theNode1
	)
	{
		Debug_Null_Pointer(theNode0);
		Debug_Null_Pointer(theNode1);

		return theNode0->Index() < theNode1->Index();
	}
}