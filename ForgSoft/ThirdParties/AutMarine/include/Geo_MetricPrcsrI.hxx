#pragma once
#include <error.hxx>
#include <OSstream.hxx>
namespace AutLib
{

	template<class SizeFun, class MetricFun>
	Standard_Real Geo_MetricPrcsr<SizeFun, MetricFun>::CalcElementSize
	(
		const Point & theCoord
	) const
	{
		Debug_Null_Pointer(theSizeFunction_);
		return theSizeFunction_->Value(theCoord);
	}

	template<class SizeFun, class MetricFun>
	typename Geo_MetricPrcsr<SizeFun, MetricFun>::metricType 
		Geo_MetricPrcsr<SizeFun, MetricFun>::CalcMetric
		(
			const Point & theCoord
		) const
	{
		Debug_Null_Pointer(theMetricFunction_);
		auto m = theMetricFunction_->Value(theCoord);
		currentMetric = m;
		return std::move(m);
	}

	template<class SizeFun, class MetricFun>
	Standard_Real
		Geo_MetricPrcsr<SizeFun, MetricFun>::CalcSquareDistance
		(
			const Point& theP0,
			const Point& theP1
		) const
	{
		auto d = CalcDistance(theP0, theP1);
		return d * d;
	}

	template<class SizeFun, class MetricFun>
	Standard_Real Geo_MetricPrcsr<SizeFun, MetricFun>::Integrand
	(
		const Point & thePoint,
		const Point & theVector
	) const
	{
		return sqrt(DotProduct(theVector, CalcMetric(thePoint).Multiplied(theVector)));
	}

	template<class SizeFun, class MetricFun>
	Standard_Real Geo_MetricPrcsr<SizeFun, MetricFun>::Integrand
	(
		const Point & thePoint,
		const vcType & theVector
	) const
	{
		return sqrt(theVector.Dot(CalcMetric(thePoint).Multiplied(theVector)));
	}

	template<class SizeFun, class MetricFun>
	Standard_Real Geo_MetricPrcsr<SizeFun, MetricFun>::IntegrandPerSize
	(
		const Point & thePoint,
		const Point & theVector
	) const
	{
		return sqrt(DotProduct(theVector, CalcMetric(thePoint).Multiplied(theVector)))
			/ CalcElementSize(thePoint);
	}

	template<class SizeFun, class MetricFun>
	Standard_Real Geo_MetricPrcsr<SizeFun, MetricFun>::IntegrandPerSize
	(
		const Point & thePoint,
		const vcType & theVector
	) const
	{
		return sqrt(theVector.Dot(CalcMetric(thePoint).Multiplied(theVector)))
			/ CalcElementSize(thePoint);
	}

	template<class SizeFun>
	Standard_Real Geo_MetricPrcsr<SizeFun, void>::CalcElementSize
	(
		const Point & theCoord
	) const
	{
		Debug_Null_Pointer(theSizeFunction_);
		return theSizeFunction_->Value(theCoord);
	}

	template<class SizeFun>
	Standard_Real
		Geo_MetricPrcsr<SizeFun, void>::CalcDistance
		(
			const Point& theP0,
			const Point& theP1
		) const
	{
		return theP0.Distance(theP1);
	}

	template<class SizeFun>
	Standard_Real
		Geo_MetricPrcsr<SizeFun, void>::CalcSquareDistance
		(
			const Point& theP0,
			const Point& theP1
		) const
	{
		return theP0.SquareDistance(theP1);
	}

	template<class SizeFun>
	Standard_Real Geo_MetricPrcsr<SizeFun, void>::Integrand
	(
		const Point& thePoint,
		const Point& theVector
	) const
	{
		return sqrt(DotProduct(theVector, theVector));
	}

	template<class SizeFun>
	Standard_Real Geo_MetricPrcsr<SizeFun, void>::Integrand
	(
		const Point& thePoint,
		const vcType& theVector
	) const
	{
		return sqrt(theVector.Dot(theVector));
	}

	template<class SizeFun>
	Standard_Real 
		Geo_MetricPrcsr<SizeFun, void>::IntegrandPerSize
		(
			const Point& thePoint, 
			const Point& theVector
		) const
	{
		return (Standard_Real)1.0 / CalcElementSize(thePoint) * sqrt(DotProduct(theVector, theVector));
	}

	template<class SizeFun>
	Standard_Real 
		Geo_MetricPrcsr<SizeFun, void>::IntegrandPerSize
		(
			const Point& thePoint, 
			const vcType& theVector
		) const
	{
		return (Standard_Real)1.0 / CalcElementSize(thePoint) * sqrt(theVector.Dot(theVector));
	}
}