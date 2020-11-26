#pragma once
#ifndef _Aft_OptNode_Calculator_Header
#define _Aft_OptNode_Calculator_Header

#include <Global_Indexed.hxx>
#include <Global_Named.hxx>
#include <Global_Done.hxx>
#include <Aft_MetricPrcsr.hxx>

#include <memory>

namespace tnbLib
{

	template<class FrontType, class SizeFun, class MetricFun = void>
	class Aft_OptNode_Calculator
		: public Global_Indexed
		, public Global_Named
		, public Global_Done
	{

		typedef Aft_MetricPrcsr<FrontType, SizeFun, MetricFun>
			metricMap;
		typedef FrontType frontType;
		typedef typename SizeFun::ptType Point;

		/*Private Data*/

		std::shared_ptr<frontType> theFront_;
		std::shared_ptr<metricMap> theMetricMap_;

		Standard_Real theSize_;


		Point theCoord_;

		Standard_Boolean IsConverged_;

	protected:

		Aft_OptNode_Calculator()
		{}

		Point& ChangeCoord()
		{
			return theCoord_;
		}

		Standard_Boolean& Change_IsConverged()
		{
			return IsConverged_;
		}

	public:

		const std::shared_ptr<frontType>& Front() const
		{
			return theFront_;
		}

		const std::shared_ptr<metricMap>& MetricMap() const
		{
			return theMetricMap_;
		}

		Standard_Real Size() const
		{
			return theSize_;
		}

		const Point& Coord() const
		{
			return theCoord_;
		}

		Standard_Boolean IsConverged() const
		{
			return IsConverged_;
		}

		virtual void Perform() = 0;

		void SetFront(const std::shared_ptr<frontType>& theFront)
		{
			theFront_ = theFront;
		}

		void SetMetricMap(const std::shared_ptr<metricMap>& theMetricMap)
		{
			theMetricMap_ = theMetricMap;
		}

		void SetSize(const Standard_Real theSize)
		{
			theSize_ = theSize;
		}
	};
}

#endif // !_Aft_OptNode_Calculator_Header