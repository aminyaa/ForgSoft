#pragma once
#include <GeoProcessor.hxx>

namespace AutLib
{

	template<class ElementTraits>
	Standard_Real Mesh_Element<ElementTraits, Mesh_ElementType_Triangle3D>::Oriented
	(
		const Point & theCoord
	) const
	{
		return Processor::Oriented_cgal(theCoord, Node0()->Coord(), Node1()->Coord(), Node2()->Coord());
	}

	template<class ElementTraits>
	Standard_Real Mesh_Element<ElementTraits, Mesh_ElementType_Triangle3D>::CalcDistance
	(
		const Point & theCoord
	) const
	{
		return Processor::Distance_cgal(theCoord, Node0()->Coord(), Node1()->Coord(), Node2()->Coord());
	}

	template<class ElementTraits>
	Standard_Real Mesh_Element<ElementTraits, Mesh_ElementType_Triangle3D>::CalcSquareDistance
	(
		const Point & theCoord
	) const
	{
		return Processor::SquareDistance_cgal(theCoord, Node0()->Coord(), Node1()->Coord(), Node2()->Coord());
	}
}