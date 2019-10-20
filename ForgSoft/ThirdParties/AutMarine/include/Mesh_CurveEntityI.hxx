#pragma once
namespace AutLib
{

	template<class gCurveType, class SizeMapType>
	Mesh_CurveEntity<gCurveType, SizeMapType>::Mesh_CurveEntity
	(
		const gCurveType& theCurve, 
		const SizeMapType& theSizeMap, 
		const Standard_Real theFirst, 
		const Standard_Real theLast
	)
		: theCurve_(theCurve)
		, theSizeMap_(theSizeMap)
		, theFirstParameter_(theFirst)
		, theLastParameter_(theLast)
	{
	}

	template<class gCurveType, class SizeMapType>
	typename Mesh_CurveEntity<gCurveType, SizeMapType>::Point 
		Mesh_CurveEntity<gCurveType, SizeMapType>::Value
		(
			const Standard_Real x
		) const
	{
		auto Pt = theCurve_.Value(x);
		return std::move(Pt);
	}
}

//- Static members

template<class gCurveType, class SizeMapType>
Standard_Real AutLib::Mesh_CurveEntity<gCurveType, SizeMapType>::Integrand
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

	typename CurveType::ptType point;
	typename CurveType::vtType vector;

	theEntity.Curve().D1(param, point, vector);
	return theEntity.SizeMap().IntegrandPerSize(point, vector);
}