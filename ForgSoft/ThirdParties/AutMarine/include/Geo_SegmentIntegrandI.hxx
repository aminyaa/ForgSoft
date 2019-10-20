#pragma once
namespace AutLib
{
	template<class MetricPrcsrType>
	Geo_SegmentIntegrand<MetricPrcsrType>::Geo_SegmentIntegrand
	(
		const Point & theP0, 
		const Point & theP1, 
		const MetricPrcsrType & theProcessor
	)
		: theP0_(theP0)
		, theProcessor_(theProcessor)
	{
		theVector_ = theP1 - theP0_;
	}
}

namespace AutLib
{

	namespace GeoLib
	{

		template<class MetricPrcsrType, bool UnitLength = false>
		struct SegmentIntegrand
		{
			static Standard_Real _
			(
				const Standard_Real x,
				const Geo_SegmentIntegrand<MetricPrcsrType>& theIntegrand
			)
			{
				return theIntegrand.Processor().Integrand(theIntegrand.CalcPoint(x), theIntegrand.Vector());
			}
		};

		template<class MetricPrcsrType>
		struct SegmentIntegrand<MetricPrcsrType, true>
		{
			static Standard_Real _
			(
				const Standard_Real x,
				const Geo_SegmentIntegrand<MetricPrcsrType>& theIntegrand
			)
			{
				return theIntegrand.Processor().IntegrandPerSize(theIntegrand.CalcPoint(x), theIntegrand.Vector());
			}
		};
	}
}