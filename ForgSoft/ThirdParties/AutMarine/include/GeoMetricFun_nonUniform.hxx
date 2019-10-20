#pragma once
#ifndef _GeoMetricFun_nonUniform_Header
#define _GeoMetricFun_nonUniform_Header

#include <Geo_MetricFunction.hxx>

namespace AutLib
{

	template<class Point>
	class GeoMetricFun_nonUniform
		: public Geo_MetricFunction<Point>
	{

		/*Private Data*/

	protected:

		GeoMetricFun_nonUniform()
		{}

		GeoMetricFun_nonUniform
		(
			const Standard_Integer theIndex,
			const word& theName
		)
			: Geo_MetricFunction<Point>(theIndex, theName)
		{}

		GeoMetricFun_nonUniform
		(
			const Standard_Integer theIndex,
			const word& theName,
			const Entity_Box<Point>& theBoundingBox
		)
			: Geo_MetricFunction<Point>(theIndex, theName, theBoundingBox)
		{}
	};
}

#endif // !_GeoMetricFun_nonUniform_Header
