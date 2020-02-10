#pragma once
#include <Geo_SegmentIntegrand.hxx>
namespace tnbLib
{

	template<class MetricPrcsrType, bool UnitLength>
	Standard_Real Geo_SegmentIntegrand_Function<MetricPrcsrType, UnitLength>::Value
	(
		const Standard_Real x
	) const
	{
		return GeoLib::SegmentIntegrand<MetricPrcsrType, UnitLength>::_(x, Entity());
	}
}