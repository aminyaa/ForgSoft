#pragma once
namespace tnbLib
{

	template<class NodeTraits>
	std::vector<typename Aft_Node<NodeTraits>::Point>
		Aft_Node<NodeTraits>::RetrieveGeometry
		(
			const std::vector<std::shared_ptr<Aft_Node>>& theNodes
		)
	{
		std::vector<Point> Pts;
		Pts.reserve(theNodes.size());
		for (const auto& x : theNodes)
		{
			Pts.push_back(x->Coord());
		}
		return std::move(Pts);
	}
}