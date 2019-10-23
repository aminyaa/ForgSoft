#pragma once
#include <GeoProcessor.hxx>

namespace AutLib
{

	template<class EdgeTraits>
	Standard_Real Mesh_Edge<EdgeTraits>::CalcDistance(const Point & theCoord) const
	{
		return Processor::Distance_cgal(theCoord, Node0()->Coord(), Node1()->Coord());
	}

	template<class EdgeTraits>
	Standard_Real Mesh_Edge<EdgeTraits>::CalcSquareDistance(const Point & theCoord) const
	{
		return Processor::SquareDistance_cgal(theCoord, Node0()->Coord(), Node1()->Coord());
	}
}