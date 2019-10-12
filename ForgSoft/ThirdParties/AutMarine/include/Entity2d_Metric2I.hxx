#pragma once
namespace AutLib
{

	template<class Archive>
	void Entity2d_Metric2::serialize
	(
		Archive & ar, 
		const unsigned int version
	)
	{
		ar& E1();
		ar& E2();

		ar& H1();
		ar& H2();
	}
}