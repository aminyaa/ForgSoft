#pragma once
#ifndef _Geo_MetricPrcsr_Header
#define _Geo_MetricPrcsr_Header

#include <Global_Indexed.hxx>
#include <Global_Named.hxx>
#include <Geo_CascadeTraits.hxx>

#include <memory>

namespace AutLib
{

	class Geo_MetricPrcsrBase
		: public Global_Indexed
		, public Global_Named
	{

		/*Private Data*/

	protected:

		Geo_MetricPrcsrBase()
		{}

		Geo_MetricPrcsrBase
		(
			const Standard_Integer theIndex,
			const word& theName
		)
			: Global_Indexed(theIndex)
			, Global_Named(theName)
		{}

	};

	template<class SizeFun, class MetricFun = void>
	class Geo_MetricPrcsr
		: public Geo_MetricPrcsrBase
	{

		typedef typename SizeFun::ptType Point;
		typedef typename MetricFun::metricType metricType;

		/*Private Data*/

		std::shared_ptr<SizeFun> theSizeFunction_;
		std::shared_ptr<MetricFun> theMetricFunction_;

	public:


		typedef typename cascadeLib::vec_type_from_point<Point>::vcType vcType;

		Geo_MetricPrcsr()
		{}

		Geo_MetricPrcsr
		(
			const std::shared_ptr<SizeFun>& theSizeFunction,
			const std::shared_ptr<MetricFun>& theMetricFunction
		)
			: theSizeFunction_(theSizeFunction)
			, theMetricFunction_(theMetricFunction)
		{}

		Geo_MetricPrcsr
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<SizeFun>& theSizeFunction,
			const std::shared_ptr<MetricFun>& theMetricFunction
		)
			: Geo_MetricPrcsrBase(theIndex, theName)
			, theSizeFunction_(theSizeFunction)
			, theMetricFunction_(theMetricFunction)
		{}

		Standard_Real CalcElementSize(const Point& theCoord) const;

		metricType CalcMetric(const Point& theCoord) const;

		Standard_Real CalcDistance(const Point& theP0, const Point& theP1) const;

		Standard_Real CalcSquareDistance(const Point& theP0, const Point& theP1) const;

		Standard_Real CalcUnitDistance(const Point& theP0, const Point& theP1) const;

		Standard_Real Integrand(const Point& thePoint, const Point& theVector) const;

		Standard_Real Integrand(const Point& thePoint, const vcType& theVector) const;

		Standard_Real IntegrandPerSize(const Point& thePoint, const Point& theVector) const;

		Standard_Real IntegrandPerSize(const Point& thePoint, const vcType& theVector) const;
	};


	template<class SizeFun>
	class Geo_MetricPrcsr<SizeFun, void>
		: public Geo_MetricPrcsrBase
	{

		typedef typename SizeFun::ptType Point;

		/*Private Data*/

		std::shared_ptr<SizeFun> theSizeFunction_;

	public:

		typedef typename cascadeLib::vec_type_from_point<Point>::vcType vcType;

		Geo_MetricPrcsr()
		{}

		Geo_MetricPrcsr
		(
			const std::shared_ptr<SizeFun>& theSizeFunction
		)
			: theSizeFunction_(theSizeFunction)
		{}

		Geo_MetricPrcsr
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<SizeFun>& theSizeFunction
		)
			: Geo_MetricPrcsrBase(theIndex, theName)
			, theSizeFunction_(theSizeFunction)
		{}

		Standard_Real CalcElementSize(const Point& theCoord) const;

		Standard_Real CalcDistance(const Point& theP0, const Point& theP1) const;

		Standard_Real CalcSquareDistance(const Point& theP0, const Point& theP1) const;

		Standard_Real CalcUnitDistance(const Point& theP0, const Point& theP1) const;

		Standard_Real Integrand(const Point& thePoint, const Point& theVector) const;

		Standard_Real Integrand(const Point& thePoint, const vcType& theVector) const;

		Standard_Real IntegrandPerSize(const Point& thePoint, const Point& theVector) const;

		Standard_Real IntegrandPerSize(const Point& thePoint, const vcType& theVector) const;
	};
}

#include <Geo_MetricPrcsrI.hxx>

#endif // !_Geo_MetricPrcsr_Header
