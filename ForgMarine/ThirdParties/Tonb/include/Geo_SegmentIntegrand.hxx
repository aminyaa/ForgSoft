#pragma once
#ifndef _Geo_SegmentIntegrand_Header
#define _Geo_SegmentIntegrand_Header

#include <Standard_TypeDef.hxx>

namespace tnbLib
{

	template<class MetricPrcsrType>
	class Geo_SegmentIntegrand
	{

		typedef typename MetricPrcsrType::ptType Point;

		/*Private Data*/

		const Point& theP0_;

		const MetricPrcsrType& theProcessor_;

		Point theVector_;

	public:

		Geo_SegmentIntegrand
		(
			const Point& theP0,
			const Point& theP1,
			const MetricPrcsrType& theProcessor
		);


		const MetricPrcsrType& Processor() const
		{
			return theProcessor_;
		}

		const Point& Vector() const
		{
			return theVector_;
		}

		const Point& P0() const
		{
			return theP0_;
		}

		Point CalcPoint(const Standard_Real x) const
		{
			return theP0_ + theVector_ * x;
		}
	};
}

#include <Geo_SegmentIntegrandI.hxx>

#endif // !_Geo_SegmentIntegrand_Header