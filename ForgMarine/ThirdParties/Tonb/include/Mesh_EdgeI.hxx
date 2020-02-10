#pragma once
#include <Geo_Tools.hxx>
namespace tnbLib
{

	template<class EdgeTraits>
	Standard_Real Mesh_Edge<EdgeTraits>::CalcDistance(const Point & theCoord) const
	{
		return Geo_Tools::Distance_cgal(theCoord, Node0()->Coord(), Node1()->Coord());
	}

	template<class EdgeTraits>
	Standard_Real Mesh_Edge<EdgeTraits>::CalcSquareDistance(const Point & theCoord) const
	{
		return Geo_Tools::SquareDistance_cgal(theCoord, Node0()->Coord(), Node1()->Coord());
	}
}