#pragma once
#include <Global_Macros.hxx>
#include <error.hxx>
#include <OSstream.hxx>
namespace tnbLib
{

	template<class SizeFun, class MetricFun>
	typename Geo_MetricPrcsr<SizeFun, MetricFun>::Point
		Geo_MetricPrcsr<SizeFun, MetricFun>::CalcCentre
		(
			const Point& theP0,
			const Point& theP1
		) const
	{
		auto c = MEAN(theP0, theP1);
		return std::move(c);
	}

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
	typename Geo_MetricPrcsr<SizeFun, MetricFun>::metricType
		Geo_MetricPrcsr<SizeFun, MetricFun>::CalcEffectiveMetric
		(
			const Point & theP0,
			const Point & theP1
		) const
	{
		const auto nbSamples = base::Info()->NbSamples();
		if (nbSamples IS_EQUAL 1)
		{
			auto m = CalcMetric(MEAN(theP0, theP1));
			const auto dP = theP1 - theP0;

			const auto d = CalcDistance(theP0, theP1);
			const auto landa = d / DotProduct(dP, m.Multiplied(dP));

			m *= (landa*landa);
			return std::move(m);
		}

		const auto du = 1.0 / (Standard_Real)nbSamples;
		const auto dP = theP1 - theP0;
		const auto dPu = dP * du;

		std::vector<metricType> metrics;
		metrics.reserve(nbSamples);
		forThose(Index, 1, nbSamples)
		{
			auto P = dPu * Index + theP0 - 0.5*dPu;

			auto m = CalcMetric(P);
			metrics.push_back(std::move(m));
		}

		auto ms = metrics[0];
		forThose(Index, 1, metrics.size() - 1)
		{
			ms = metricType::IntersectionSR(ms, metrics[Index]);
		}

		const auto d = CalcDistance(theP0, theP1);
		const auto landa = d / metricType::Distance(theP0, theP1, ms);

		ms *= (landa*landa);
		return std::move(ms);
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
	typename Geo_MetricPrcsr<SizeFun, void>::Point
		Geo_MetricPrcsr<SizeFun, void>::CalcCentre
		(
			const Point& theP0,
			const Point& theP1
		) const
	{
		auto c = MEAN(theP0, theP1);
		return std::move(c);
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
		return ((Standard_Real)1.0 / CalcElementSize(thePoint)) * sqrt(DotProduct(theVector, theVector));
	}

	template<class SizeFun>
	Standard_Real
		Geo_MetricPrcsr<SizeFun, void>::IntegrandPerSize
		(
			const Point& thePoint,
			const vcType& theVector
		) const
	{
		return ((Standard_Real)1.0 / CalcElementSize(thePoint)) * sqrt(theVector.Dot(theVector));
	}
}