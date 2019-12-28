#pragma once
namespace AutLib
{

	template<class Point>
	template<class Archive>
	void Entity_Polygon<Point>::serialize
	(
		Archive & ar,
		const unsigned int version
	)
	{
		ar& Points();
		ar& Deflection();
	}

	template<class Point>
	void Entity_Polygon<Point>::Reverse()
	{
		const auto iMax = (Standard_Integer)thePoints_.size() - 1;
		forThose(Index, 0, thePoints_.size() / 2 - 1)
		{
			std::swap(thePoints_[Index], thePoints_[iMax - Index]);
		}
	}
}