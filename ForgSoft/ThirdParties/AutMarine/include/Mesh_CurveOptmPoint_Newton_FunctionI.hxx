#pragma once
#include <iostream>
namespace AutLib
{
	template<class CurveType, class SizeMap>
	Standard_Real Mesh_CurveOptmPoint_Newton_Function<CurveType, SizeMap>::Value
	(
		const Standard_Real x
	) const
	{
		return Mesh_CurveLength::Length(Curve(), X0(), x, theInfo_) - Step();
	}
}