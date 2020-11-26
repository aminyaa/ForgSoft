#pragma once
namespace tnbLib
{

	template<class gCurveType, class MetricPrcsrType>
	Mesh_CurveEntity<gCurveType, MetricPrcsrType>::Mesh_CurveEntity
	(
		const gCurveType& theCurve,
		const MetricPrcsrType& theSizeMap,
		const Standard_Real theFirst,
		const Standard_Real theLast
	)
		: theCurve_(theCurve)
		, theSizeMap_(theSizeMap)
		, theFirstParameter_(theFirst)
		, theLastParameter_(theLast)
	{
	}

	template<class gCurveType, class MetricPrcsrType>
	typename Mesh_CurveEntity<gCurveType, MetricPrcsrType>::Point
		Mesh_CurveEntity<gCurveType, MetricPrcsrType>::Value
		(
			const Standard_Real x
		) const
	{
		auto Pt = theCurve_.Value(x);
		return std::move(Pt);
	}
}

//- Static members

template<class gCurveType, class MetricPrcsrType>
Standard_Real tnbLib::Mesh_CurveEntity<gCurveType, MetricPrcsrType>::Integrand
(
	const Standard_Real x,
	const Mesh_CurveEntity& theEntity
)
{
	auto first = theEntity.FirstParameter();
	auto last = theEntity.LastParameter();

	auto param = x;
	if (param < first) param = first;
	if (param > last) param = last;

	Point point;
	typename cascadeLib::vec_type_from_point<Point>::vcType vector;

	theEntity.Curve().D1(param, point, vector);
	return theEntity.SizeMap().IntegrandPerSize(point, vector);
}