#pragma once
namespace AutLib
{

	template<class PointRef>
	template<class Archive>
	void Entity_Triangle<PointRef>::serialize
	(
		Archive & ar, 
		const unsigned int version
	)
	{
		ar& theP0_;
		ar& theP1_;
		ar& theP2_;
	}
}