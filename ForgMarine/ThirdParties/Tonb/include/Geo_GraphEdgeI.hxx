#pragma once
#include <Geo_GraphNode.hxx>
namespace tnbLib
{

	template<class EdgeTraits>
	void Geo_GraphEdge<EdgeTraits>::deAttach
	(
		const std::shared_ptr<Geo_GraphEdge>& theEdge
	)
	{
		const auto& n0 = theEdge->Node0();
		const auto& n1 = theEdge->Node1();

		Debug_Null_Pointer(n0);
		Debug_Null_Pointer(n1);

		n0->RemoveFromEdges(theEdge->Index());
		n1->RemoveFromEdges(theEdge->Index());
	}
}