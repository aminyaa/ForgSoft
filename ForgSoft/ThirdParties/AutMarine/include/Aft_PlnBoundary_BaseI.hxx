#pragma once
#include <GeoProcessor.hxx>
namespace AutLib
{

	template<class BndType>
	Standard_Boolean Aft_PlnBoundary_Base<BndType>::CheckWireOrientation
	(
		const std::vector<std::shared_ptr<BndType>>& theEdges,
		const Standard_Boolean ccw
	)
	{
		auto nodes = BndType::RetrieveNodes(BndType::UpCast(theEdges));
		if (nodes.size() < 3)
		{
			return Standard_False;
		}

		auto pts = BndType::bndNodeType::RetrieveGeometry(nodes);

		if (ccw)
		{
			return !Processor::IsCcwOrder_cgal(pts);
		}

		return Processor::IsCcwOrder_cgal(pts);
	}

	template<class BndType>
	Standard_Boolean Aft_PlnBoundary_Base<BndType>::CheckWireNbPts
	(
		const std::vector<std::shared_ptr<BndType>>& theEdges
	)
	{
		return theEdges.size() < 3;
	}

	template<class BndType>
	Standard_Boolean Aft_PlnBoundary_Base<BndType>::CheckSimplicity
	(
		const std::vector<std::shared_ptr<BndType>>& theEdges
	)
	{
		auto nodes = BndType::RetrieveNodes(BndType::UpCast(theEdges));
		if (nodes.size() < 3)
		{
			return Standard_False;
		}

		auto pts = BndType::bndNodeType::RetrieveGeometry(nodes);

		return !Processor::IsSimple_cgal(pts);
	}
}