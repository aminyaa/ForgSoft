#pragma once
namespace tnbLib
{

	template<class KnitTraits>
	std::shared_ptr<typename Geo_KnitGraph<KnitTraits>::ptType> 
		Geo_KnitGraph<KnitTraits>::Next
		(
			const std::shared_ptr<ptType>& theNode
		)
	{
		if (Type(*theNode) NOT_EQUAL Geo_KnitNodeType::REGULAR)
		{
			if (NOT theNode->NbEdges())
			{
				base::PtRegistry().RemoveFromGeo_KnitNodes(theNode->Index());
			}

			return nullptr;
		}

		const auto& edges = theNode->Edges();

		auto iEdge = edges.begin()->second.lock();
		Debug_Null_Pointer(iEdge);

		theNode->RemoveFromEdges(iEdge->Index());
		base::SegRegistry().RemoveFromGeo_KnitEdges(iEdge->Index());

		const auto& left = iEdge->Node0();
		const auto& right = iEdge->Node1();

		std::shared_ptr<ptType> next;
		if (left IS_EQUAL theNode) next = right;
		else if (right IS_EQUAL theNode) next = left;
		else
		{
			FatalErrorIn("node_ptr Next(const node_ptr& theNode)")
				<< "Unable to find the next node" << endl
				<< abort(FatalError);
		}

		if (edges.size() IS_EQUAL 1)
		{
			base::PtRegistry().RemoveFromGeo_KnitNodes(theNode->Index());
		}

		next->RemoveFromEdges(iEdge->Index());
		return std::move(next);
	}

	template<class KnitTraits>
	Geo_KnitNodeType Geo_KnitGraph<KnitTraits>::Type(const ptType & theNode)
	{
		if (theNode.NbEdges() IS_EQUAL 2)
		{
			// regular node
			return Geo_KnitNodeType::REGULAR;
		}
		else
		{
			// start node
			return Geo_KnitNodeType::START;
		}
	}
}