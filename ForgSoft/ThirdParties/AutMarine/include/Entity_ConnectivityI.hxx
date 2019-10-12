#pragma once
namespace AutLib
{

	template<int Dim>
	template<class Archive>
	void Entity_Connectivity<Dim>::serialize
	(
		Archive & ar,
		const unsigned int version
	)
	{
		for (int i = 0; i < Dim; i++) 
			ar& theV_[i];
	}
}