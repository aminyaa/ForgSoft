#pragma once
#include <Mesh_CurveEntity.hxx>
namespace AutLib
{

	template<class CurveType, class SizeMap>
	Standard_Real AutLib::Mesh_CurveLength_Function<CurveType, SizeMap>::Value
	(
		const Standard_Real x
	) const
	{
		const auto& map = theEntity_.SizeMap();
		const auto& curve = theEntity_.Curve();

		auto first = theEntity_.FirstParameter();
		auto last = theEntity_.LastParameter();

		auto p = x;
		if (p < first) p = first;
		if (p > last) p = last;

		typename CurveType::ptType pt;
		typename CurveType::vtType vec;

		curve.D1(p, pt, vec);
		return map.IntegrandPerSize(pt, vec);
	}
}