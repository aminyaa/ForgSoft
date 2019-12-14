#pragma once
#include <Global_Macros.hxx>
namespace AutLib
{

	template<class TBndNodeTraits, Mesh_BndNode_Position POS>
	std::shared_ptr<Aft_TBndNode<TBndNodeTraits, POS>> Aft_TBndNode<TBndNodeTraits, POS>::MergeNodes
	(
		const std::shared_ptr<Aft_TBndNode>& theNode0,
		const std::shared_ptr<Aft_TBndNode>& theNode1, 
		const typename base::base::Merge_Alg theAlg
	)
	{
		if (theAlg IS_EQUAL base::base::Merge_Alg::FirstPreferred)
		{
			auto node = theNode0;
			return std::move(node);
		}
		else if (theAlg IS_EQUAL base::base::Merge_Alg::SecondPreferred)
		{
			auto node = MergeNodes(theNode1, theNode0, base::base::Merge_Alg::FirstPreferred);
			return std::move(node);
		}
		else
		{
			auto node =
				std::make_shared<Aft_TBndNode>(0, MEAN(theNode0->Coord(), theNode1->Coord()));
			return std::move(node);
		}
	}
}