#pragma once
#include <map>
namespace AutLib
{
	template<class EdgeTraits>
	std::vector<std::shared_ptr<typename Aft_Edge<EdgeTraits>::nodeType>>
		Aft_Edge<EdgeTraits>::RetrieveNodes
		(
			const std::vector<std::shared_ptr<Aft_Edge>>& theEdges
		)
	{
		std::map<Standard_Integer, std::shared_ptr<nodeType>> nodes_map;
		for (const auto& x : theEdges)
		{
			Debug_Null_Pointer(x);

			const auto& n0 = x->Node0();
			const auto& n1 = x->Node1();

			auto iter = nodes_map.find(n0->Index());
			if (iter == nodes_map.end())
			{
				nodes_map.insert(std::make_pair(n0->Index(), n0));
			}

			iter = nodes_map.find(n1->Index());
			if (iter == nodes_map.end())
			{
				nodes_map.insert(std::make_pair(n1->Index(), n1));
			}
		}

		std::vector<std::shared_ptr<nodeType>> nodes;
		nodes.reserve(nodes_map.size());
		for (const auto& x : nodes_map)
		{
			nodes.push_back(x.second);
		}
		return std::move(nodes);
	}
}