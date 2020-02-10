#pragma once
namespace tnbLib
{

	template<class CurveType, class MetricPrcsrType>
	typename Geo_CurveIntegrand<CurveType, MetricPrcsrType>::Point
		Geo_CurveIntegrand<CurveType, MetricPrcsrType>::CalcPoint
		(
			const Standard_Real x,
			Vector & theVec
		) const
	{
		const auto& curve = Curve();

		Point pt;
		curve.D1(x, pt, theVec);

		return std::move(pt);
	}

	template<class CurveType>
	typename Geo_CurveIntegrand<CurveType, void>::Point
		Geo_CurveIntegrand<CurveType, void>::CalcPoint
		(
			const Standard_Real x, Vector & theVec
		) const
	{
		const auto& curve = Curve();

		Point pt;
		curve.D1(x, pt, theVec);

		return std::move(pt);
	}
}

namespace tnbLib
{

	namespace GeoLib
	{

		template<class CurveType, class MetricPrcsrType = void, bool UnitLength = false>
		struct CurveIntegrand
		{
			static Standard_Real _
			(
				const Standard_Real x,
				const Geo_CurveIntegrand<CurveType, MetricPrcsrType>& theIntegrand
			)
			{
				typename Geo_CurveIntegrand<CurveType, MetricPrcsrType>::Vector vect;
				auto pt = theIntegrand.CalcPoint(x, vect);

				return theIntegrand.Processor().Integrand(pt, vect);
			}
		};

		template<class CurveType>
		struct CurveIntegrand<CurveType, void, false>
		{
			static Standard_Real _
			(
				const Standard_Real x,
				const Geo_CurveIntegrand<CurveType, void>& theIntegrand
			)
			{
				typename Geo_CurveIntegrand<CurveType, void>::Vector vect;
				auto pt = theIntegrand.CalcPoint(x, vect);

				return sqrt(vect.Dot(vect));
			}
		};

		template<class CurveType, class MetricPrcsrType>
		struct CurveIntegrand<CurveType, MetricPrcsrType, true>
		{
			static Standard_Real _
			(
				const Standard_Real x,
				const Geo_CurveIntegrand<CurveType, MetricPrcsrType>& theIntegrand
			)
			{
				typename Geo_CurveIntegrand<CurveType, MetricPrcsrType>::Vector vect;
				auto pt = theIntegrand.CalcPoint(x, vect);

				return theIntegrand.Processor().IntegrandPerSize(pt, vect);
			}
		};

	}
}