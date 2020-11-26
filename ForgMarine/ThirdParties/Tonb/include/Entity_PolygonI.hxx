#pragma once
namespace tnbLib
{

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