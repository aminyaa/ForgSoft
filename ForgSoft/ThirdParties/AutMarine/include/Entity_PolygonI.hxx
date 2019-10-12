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
}