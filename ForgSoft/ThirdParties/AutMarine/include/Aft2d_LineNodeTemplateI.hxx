#pragma once
namespace AutLib
{

	template<class BndNodeType>
	std::shared_ptr<BndNodeType> 
		Aft2d_LineNodeTemplate<BndNodeType>::MergeNodes
		(
			const std::shared_ptr<BndNodeType>& theNode0,
			const std::shared_ptr<BndNodeType>& theNode1,
			const typename base::Merge_Alg Alg
		)
	{
		if (Alg IS_EQUAL base::Merge_Alg::FirstPreferred)
		{
			auto node = theNode0;
			return std::move(node);
		}
		else if (Alg IS_EQUAL base::Merge_Alg::SecondPreferred)
		{
			auto node = MergeNodes(theNode1, theNode0, base::Merge_Alg::FirstPreferred);
			return std::move(node);
		}
		else
		{
			auto node =
				std::make_shared<Aft2d_LineNodeTemplate>(0, MEAN(theNode0->Coord(), theNode1->Coord()));
			return std::move(node);
		}
	}
}