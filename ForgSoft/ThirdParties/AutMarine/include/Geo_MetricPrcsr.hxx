#pragma once
#ifndef _Geo_MetricPrcsr_Header
#define _Geo_MetricPrcsr_Header

#include <Global_Indexed.hxx>
#include <Global_Named.hxx>
#include <Geo_CascadeTraits.hxx>
#include <Numeric_AdaptIntegrationInfo.hxx>

#include <memory>

namespace AutLib
{

	class Geo_MetricPrcsrBase
		: public Global_Indexed
		, public Global_Named
	{
		
	public:

		typedef Numeric_AdaptIntegrationInfo info;

	private:

		/*Private Data*/

		std::shared_ptr<info> theInfo_;

	protected:

		Geo_MetricPrcsrBase(const std::shared_ptr<info>& theInfo)
			: theInfo_(theInfo)
		{}

		Geo_MetricPrcsrBase
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<info>& theInfo
		)
			: Global_Indexed(theIndex)
			, Global_Named(theName)
			, theInfo_(theInfo)
		{}

		const std::shared_ptr<info>& Info() const
		{
			return theInfo_;
		}

		void OverrideInfo(const std::shared_ptr<info>& theInfo)
		{
			theInfo_ = theInfo;
		}

	};

	template<class SizeFun, class MetricFun = void>
	class Geo_MetricPrcsr
		: public Geo_MetricPrcsrBase
	{

	public:

		typedef typename SizeFun::ptType Point;
		typedef typename MetricFun::metricType metricType;

		mutable metricType currentMetric;

	private:

		/*Private Data*/

		std::shared_ptr<SizeFun> theSizeFunction_;
		std::shared_ptr<MetricFun> theMetricFunction_;

	public:

		typedef typename Geo_MetricPrcsrBase::info info;

		typedef Point ptType;
		typedef typename cascadeLib::vec_type_from_point<Point>::vcType vcType;

		Geo_MetricPrcsr(const std::shared_ptr<info>& theInfo)
			: Geo_MetricPrcsrBase(theInfo)
		{}

		Geo_MetricPrcsr
		(
			const std::shared_ptr<SizeFun>& theSizeFunction,
			const std::shared_ptr<MetricFun>& theMetricFunction,
			const std::shared_ptr<info>& theInfo
		)
			: Geo_MetricPrcsrBase(theInfo)
			, theSizeFunction_(theSizeFunction)
			, theMetricFunction_(theMetricFunction)
		{}

		Geo_MetricPrcsr
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<SizeFun>& theSizeFunction,
			const std::shared_ptr<MetricFun>& theMetricFunction,
			const std::shared_ptr<info>& theInfo
		)
			: Geo_MetricPrcsrBase(theIndex, theName, theInfo)
			, theSizeFunction_(theSizeFunction)
			, theMetricFunction_(theMetricFunction)
		{}

		const std::shared_ptr<SizeFun>& SizeFunction() const
		{
			return theSizeFunction_;
		}

		const std::shared_ptr<MetricFun>& MetricFunction() const
		{
			return theMetricFunction_;
		}

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

	public:

		typedef typename SizeFun::ptType Point;

	private:

		/*Private Data*/

		std::shared_ptr<SizeFun> theSizeFunction_;

	public:

		typedef typename Geo_MetricPrcsrBase::info info;

		typedef Point ptType;
		typedef typename cascadeLib::vec_type_from_point<Point>::vcType vcType;

		Geo_MetricPrcsr(const std::shared_ptr<info>& theInfo)
			: Geo_MetricPrcsrBase(theInfo)
		{}

		Geo_MetricPrcsr
		(
			const std::shared_ptr<SizeFun>& theSizeFunction,
			const std::shared_ptr<info>& theInfo
		)
			: Geo_MetricPrcsrBase(theInfo)
			, theSizeFunction_(theSizeFunction)
		{}

		Geo_MetricPrcsr
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<SizeFun>& theSizeFunction,
			const std::shared_ptr<info>& theInfo
		)
			: Geo_MetricPrcsrBase(theIndex, theName, theInfo)
			, theSizeFunction_(theSizeFunction)
		{}

		const std::shared_ptr<SizeFun>& SizeFunction() const
		{
			return theSizeFunction_;
		}

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
