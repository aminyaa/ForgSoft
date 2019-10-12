#pragma once
#ifndef _Entity_Segment_Header
#define _Entity_Segment_Header

#include <Traits.hxx>

namespace AutLib
{

	template<class PointRef>
	class Entity_Segment
	{

		typedef typename remove_reference<PointRef>::type Point;

		/*Private Data*/

		PointRef theP0_;
		PointRef theP1_;

	public:

		Entity_Segment()
			: theP0_(Point::null)
			, theP1_(Point::null)
		{}

		Entity_Segment
		(
			const Point& theP0,
			const Point& theP1
		)
			: theP0_(theP0)
			, theP1_(theP1)
		{}

		const Point& P0() const
		{
			return theP0_;
		}

		/*Point& P0()
		{
			return const_cast<Point&>(theP0_);
		}*/

		const Point& P1() const
		{
			return theP1_;
		}

		/*Point& P1()
		{
			return const_cast<Point&>(theP1_);
		}*/
	};
}

#endif // !_Entity_Segment_Header
