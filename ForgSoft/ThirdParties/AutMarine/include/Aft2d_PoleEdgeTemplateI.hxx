#pragma once
#include <Global_Macros.hxx>
#include <Aft2d_PoleNodeTemplate.hxx>
#include <error.hxx>
#include <OSstream.hxx>
namespace AutLib
{

	template<class BndEdgeType>
	void Aft2d_PoleEdgeTemplate<BndEdgeType>::SingularityContraction
	(
		const typename BndEdgeType::metricPrcsr & thePrcsr
	)
	{
		Debug_Null_Pointer(this->Node0());
		Debug_Null_Pointer(this->Node1());

		const auto n0 = 
			std::dynamic_pointer_cast
			<
			Aft2d_PoleNodeTemplate
			<typename BndEdgeType::traitsType::nodeType
			>>(this->Node0());
		const auto n1 = 
			std::dynamic_pointer_cast
			<
			Aft2d_PoleNodeTemplate
			<typename BndEdgeType::traitsType::nodeType
			>>(this->Node1());
		Debug_Null_Pointer(n0);
		Debug_Null_Pointer(n1);

		if (n0->NbBoundaryEdges() NOT_EQUAL 2)
		{
			FatalErrorIn("void SingularityContraction()")
				<< "contradictory data" << endl
				<< abort(FatalError);
		}

		if (n1->NbBoundaryEdges() NOT_EQUAL 2)
		{
			FatalErrorIn("void SingularityContraction()")
				<< "contradictory data" << endl
				<< abort(FatalError);
		}

		if (n0->IsFixed() AND n1->IsFixed())
		{
			FatalErrorIn("void SingularityContraction()")
				<< "contradictory data: both nodes on the either side of the edge are fixed!" << endl
				<< abort(FatalError);
		}

		std::shared_ptr
			<
			Aft2d_PoleNodeTemplate
			<
			typename BndEdgeType::traitsType::nodeType
			>> fixed, other;
		if (n0->IsFixed()) fixed = n0;
		if (n1->IsFixed()) fixed = n1;

		if (NOT n0->IsFixed()) other = n0;
		if (NOT n1->IsFixed()) other = n1;

		Debug_Null_Pointer(fixed);
		Debug_If_Condition(other == fixed);

		n0->RemoveFromBoundaryEdges(this->Index());
		n1->RemoveFromBoundaryEdges(this->Index());

		Debug_Null_Pointer(other);
		const auto& edges = other->RetrieveBoundaryEdges();
		Debug_If_Condition(edges.size() NOT_EQUAL 1);

		auto edge = edges.begin()->second.lock();
		Debug_Null_Pointer(edge);

		other->RemoveFromBoundaryEdges(edge->Index());
		Debug_If_Condition(other->NbBoundaryEdges());

		if (edge->Node0() IS_EQUAL other) edge->Node0() = fixed;
		else edge->Node1() = fixed;

		fixed->InsertToBoundaryEdges(edge->Index(), edge);

		edge->SetCharLength
		(
			thePrcsr.CalcDistance
			(
				edge->Node0()->Coord(),
				edge->Node1()->Coord()));
		edge->SetCentre
		(
			thePrcsr.CalcCentreOf
			(
				edge->Node0()->Coord(),
				edge->Node1()->Coord()));

		Debug_If_Condition(fixed->NbBoundaryEdges() NOT_EQUAL 2);
	}
}

template<class BndEdgeType>
std::vector<std::shared_ptr<typename AutLib::Aft2d_PoleEdgeTemplate<BndEdgeType>::edgeType>> 
AutLib::Aft2d_PoleEdgeTemplate<BndEdgeType>::GetTopology(const AutLib::Entity2d_Chain& theChain)
{
	const auto& pts = theChain.Points();
	if (pts.size() NOT_EQUAL 3)
	{
		FatalErrorIn("std::vector<std::shared_ptr<edgeType>> GetTopology(const Entity2d_Chain& theChain)")
			<< "Invalid Pole Data" << endl
			<< abort(FatalError);
	}

	std::vector<std::shared_ptr<Aft2d_PoleNodeTemplate<bndNodeType>>> nodes;
	nodes.reserve(pts.size());

	Standard_Integer K = 0;
	for (const auto& x : pts)
	{
		nodes.push_back(std::make_shared<Aft2d_PoleNodeTemplate<bndNodeType>>(++K, x));
	}

	nodes[1]->SetFixed(Standard_True);

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

		auto edge = std::make_shared<Aft2d_PoleEdgeTemplate>(++K, n0, n1);
		Debug_Null_Pointer(edge);

		edges.push_back(edge);
	}
	return std::move(edges);
}