#pragma once
namespace AutLib
{

	template<class Point, class ConnectType, bool NeighbData>
	template<class Archive>
	void Entity_StaticData<Point, ConnectType, NeighbData>::serialize
	(
		Archive & ar,
		const unsigned int version
	)
	{
		ar& Points();
		ar& Connectivity();
		ar& theBoundingBox_;
	}
}