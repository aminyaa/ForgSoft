#pragma once
namespace AutLib
{

	template<class PointRef, class DirectRef>
	template<class Archive>
	void Entity_Line<PointRef, DirectRef>::serialize
	(
		Archive & ar,
		const unsigned int version
	)
	{
		ar& Point();
		ar& Direct();
	}
}