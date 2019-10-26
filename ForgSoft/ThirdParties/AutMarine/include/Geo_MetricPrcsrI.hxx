#pragma once
namespace AutLib
{

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