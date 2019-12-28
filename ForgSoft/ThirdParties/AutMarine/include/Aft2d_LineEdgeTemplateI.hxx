#pragma once
#include <Global_Macros.hxx>
#include <Aft2d_LineNodeTemplate.hxx>
#include <error.hxx>
#include <OSstream.hxx>
template<class BndEdgeType>
std::vector<std::shared_ptr<typename AutLib::Aft2d_LineEdgeTemplate<BndEdgeType>::edgeType>> 
AutLib::Aft2d_LineEdgeTemplate<BndEdgeType>::GetTopology
(
	const AutLib::Entity2d_Chain& theChain
)
{
	const auto& pts = theChain.Points();

	std::vector<std::shared_ptr<Aft2d_LineNodeTemplate<bndNodeType>>> nodes;
	nodes.reserve(pts.size());

	Standard_Integer K = 0;
	for (const auto& x : pts)
	{
		nodes.push_back(std::make_shared<Aft2d_LineNodeTemplate<bndNodeType>>(++K, x));
	}

	const auto& connect = theChain.Connectivity();

	std::vector<std::shared_ptr<edgeType>> edges;
	edges.reserve(connect.size());

	K = 0;
	for (const auto& x : connect)
	{
		auto& n0 = nodes[Index_Of(x.Value(0))];
		auto& n1 = nodes[Index_Of(x.Value(1))];

		Debug_Null_Pointer(n0);
		Debug_Null_Pointer(n1);

		auto edge = std::make_shared<Aft2d_LineEdgeTemplate>(++K, n0, n1);
		Debug_Null_Pointer(edge);

		edges.push_back(edge);
	}
	return std::move(edges);
}