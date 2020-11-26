#pragma once
namespace tnbLib
{

	template<class TBndEdgeTraits, Mesh_BndEdge_Position POS>
	std::vector<std::shared_ptr<typename TBndEdgeTraits::bndEdgeTraits::edgeType>>
		Mesh_TBndEdge<TBndEdgeTraits, POS>::UpCast(const std::vector<std::shared_ptr<Mesh_TBndEdge>>& theEdges)
	{
		std::vector<std::shared_ptr<typename TBndEdgeTraits::bndEdgeTraits::edgeType>> edges;
		edges.reserve(theEdges.size());

		for (const auto& x : theEdges)
		{
			Debug_Null_Pointer(x);
			edges.push_back(x);
		}
		return std::move(edges);
	}
}