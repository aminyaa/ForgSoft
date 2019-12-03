#pragma once
namespace AutLib
{

	template<class BndEdgeType, class SurfPln>
	Standard_Boolean Aft_SingEdge<BndEdgeType, SurfPln>::IsSingular
	(
		const std::shared_ptr<BndEdgeType>& theEdge
	)
	{
		auto singular = std::dynamic_pointer_cast<Aft_SingEdge>(theEdge);
		if (singular) return Standard_True;
		else return Standard_False;
	}
}