#pragma once
#include <Global_Macros.hxx>
namespace tnbLib
{

	template<class TBndNodeTraits, Mesh_BndNode_Position POS>
	std::shared_ptr<Mesh_TBndNode<TBndNodeTraits, POS>> Mesh_TBndNode<TBndNodeTraits, POS>::MergeNodes
	(
		const std::shared_ptr<Mesh_TBndNode>& theNode0,
		const std::shared_ptr<Mesh_TBndNode>& theNode1,
		const Mesh_BndMergeAlg theAlg
	)
	{
		if (theAlg IS_EQUAL Mesh_BndMergeAlg::FirstPreferred)
		{
			auto node = theNode0;
			return std::move(node);
		}
		else if (theAlg IS_EQUAL Mesh_BndMergeAlg::SecondPreferred)
		{
			auto node = MergeNodes(theNode1, theNode0, Mesh_BndMergeAlg::FirstPreferred);
			return std::move(node);
		}
		else
		{
			auto node =
				std::make_shared<Mesh_TBndNode>(0, MEAN(theNode0->Coord(), theNode1->Coord()));
			return std::move(node);
		}
	}
}