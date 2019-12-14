#pragma once
#include <error.hxx>
#include <OSstream.hxx>
namespace AutLib
{
	template<class CurveType, class SizeFun, class MetricFun>
	void Mesh_PlnRegion<CurveType, SizeFun, MetricFun>::RetrieveWiresTo
	(
		wireList& theWires
	) const
	{
		theWires.push_back(theOutter_);
		if (theInner_)
		{
			for (const auto& x : *theInner_)
			{
				theWires.push_back(x);
			}
		}
	}

	template<class CurveType, class SizeFun, class MetricFun>
	template<class WireType>
	std::shared_ptr<typename Mesh_PlnRegion<CurveType, SizeFun, MetricFun>::plnWireType> 
		Mesh_PlnRegion<CurveType, SizeFun, MetricFun>::MakeMeshWire
		(
			const WireType & theWire
		)
	{
		auto curves_ptr =
			std::make_shared<std::vector<std::shared_ptr<plnCurveType>>>();
		auto& curves = *curves_ptr;
		curves.reserve(theWire.NbEdges());

		Standard_Integer K = 0;
		for (const auto& x : theWire.Edges())
		{
			Debug_Null_Pointer(x);

			const auto& xCurve = x->Curve();
			Debug_Null_Pointer(xCurve);

			curves.push_back(std::make_shared<plnCurveType>(*xCurve));
		}

		auto wire =
			std::make_shared<plnWireType>(curves_ptr);

		return std::move(wire);
	}
}

template<class CurveType, class SizeFun, class MetricFun>
std::shared_ptr<AutLib::Mesh_PlnRegion<CurveType, SizeFun, MetricFun>>
AutLib::Mesh_PlnRegion<CurveType, SizeFun, MetricFun>::MakePlane
(
	const std::shared_ptr<plnType>& thePlane
)
{
	Debug_Null_Pointer(thePlane);
	if (NOT thePlane->OuterWire())
	{
		FatalErrorIn(FunctionSIG)
			<< "Invalid surface : has no outer wire" << endl
			<< abort(FatalError);
	}

	const auto& Outer = *thePlane->OuterWire();
	const auto& Inners = *thePlane->InnerWires();

	auto outer_wire =
		MakeMeshWire(Outer);

	std::shared_ptr<std::vector<std::shared_ptr<plnWireType>>>
		inner_wires;
	if (thePlane->InnerWires())
	{
		inner_wires =
			std::make_shared<std::vector<std::shared_ptr<plnWireType>>>();
		inner_wires->reserve(Inners.size());

		for (const auto& x : Inners)
		{
			Debug_Null_Pointer(x);

			auto wire = MakeMeshWire(*x);
			inner_wires->push_back(wire);
		}
	}

	auto plane =
		std::make_shared<Mesh_PlnRegion>
		(
			thePlane, outer_wire,
			inner_wires);
	return std::move(plane);
}