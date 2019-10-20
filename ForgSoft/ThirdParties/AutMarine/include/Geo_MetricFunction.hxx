#pragma once
#ifndef _Geo_MetricFunction_Header
#define _Geo_MetricFunction_Header

#include <Global_Indexed.hxx>
#include <Global_Named.hxx>
#include <Global_Done.hxx>
#include <Entity_Box.hxx>
#include <Geo_MetricFunctionTraits.hxx>

namespace AutLib
{

	template<class Point>
	class Geo_MetricFunction
		: public Global_Indexed
		, public Global_Named
		, public Global_Done
	{

		/*Private Data*/

		Entity_Box<Point> theBoundingBox_;

	protected:

		Geo_MetricFunction()
		{}

		Geo_MetricFunction
		(
			const Standard_Integer theIndex, 
			const word& theName
		)
			: Global_Indexed(theIndex)
			, Global_Named(theName)
		{}

		Geo_MetricFunction
		(
			const Standard_Integer theIndex,
			const word& theName,
			const Entity_Box<Point>& theBoundingBox
		)
			: Global_Indexed(theIndex)
			, Global_Named(theName)
			, theBoundingBox_(theBoundingBox)
		{}


		Entity_Box<Point>& ChangeBoundingBox()
		{
			return theBoundingBox_;
		}

	public:

		typedef Point ptType;
		typedef typename metric_type_from_point<Point>::metricType metricType;

		virtual metricType Value(const Point& theCoord) const = 0;

		virtual void Perform()
		{
			Change_IsDone() = Standard_True;
		}
	};
}

#endif // !_Geo_MetricFunction_Header
