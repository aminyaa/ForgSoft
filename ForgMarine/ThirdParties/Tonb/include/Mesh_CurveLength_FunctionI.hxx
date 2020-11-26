#pragma once
#include <Mesh_CurveEntity.hxx>
namespace tnbLib
{

	template<class gCurveType, class MetricPrcsrType>
	Mesh_CurveLength_Function<gCurveType, MetricPrcsrType>::Mesh_CurveLength_Function
	(
		const entity& theEntity
	)
		: theEntity_(theEntity)
	{}

	template<class gCurveType, class MetricPrcsrType>
	Standard_Real Mesh_CurveLength_Function<gCurveType, MetricPrcsrType>::Value
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

		Point pt;
		Vector vec;

		curve.D1(p, pt, vec);
		return map.IntegrandPerSize(pt, vec);
	}
}