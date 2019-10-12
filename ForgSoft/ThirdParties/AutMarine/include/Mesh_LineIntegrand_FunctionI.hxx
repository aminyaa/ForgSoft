#pragma once
#include <Mesh_LineIntegrand.hxx>
namespace AutLib
{
	template<class SizeMap, bool UnitLength>
	Standard_Real Mesh_LineIntegrand_Function<SizeMap, UnitLength>::Value
	(
		const Standard_Real x
	) const
	{
		return MeshLib::Integrand<SizeMap, UnitLength>::_(x, Entity());
	}
}