#pragma once
#ifndef _Entity_Triangle_Header
#define _Entity_Triangle_Header

#include <Traits.hxx>
#include <Entity_Segment.hxx>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

namespace AutLib
{

	template<class PointRef>
	class Entity_Triangle
	{

		typedef typename remove_reference<PointRef>::type Point;
		typedef Entity_Segment<PointRef> segment;

		friend class boost::serialization::access;

		/*Private Data*/

		PointRef theP0_;
		PointRef theP1_;
		PointRef theP2_;


		template<class Archive>
		void serialize(Archive& ar, const unsigned int version);

	public:

		Entity_Triangle()
			: theP0_(Point::null)
			, theP1_(Point::null)
			, theP2_(Point::null)
		{}

		Entity_Triangle
		(
			const Point& theP0,
			const Point& theP1,
			const Point& theP2
		)
			: theP0_(theP0)
			, theP1_(theP1)
			, theP2_(theP2)
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

		const Point& P2() const
		{
			return theP2_;
		}

		/*Point& P2()
		{
			return const_cast<Point&>(theP2_);
		}*/

		const Point& Vertex
		(
			const Standard_Integer theIndex
		) const
		{
			if (theIndex == 0)
			{
				return theP0_;
			}
			else if (theIndex == 1)
			{
				return theP1_;
			}
			else
			{
				return theP2_;
			}
		}

		segment Segment0() const
		{
			segment s(P1(), P2());
			return std::move(s);
		}

		segment Segment1() const
		{
			segment s(P2(), P0());
			return std::move(s);
		}

		segment Segment2() const
		{
			segment s(P0(), P1());
			return std::move(s);
		}

		segment Segment
		(
			const Standard_Integer theIndex
		) const
		{
			if (theIndex == 0)
			{
				segment s(theP1_, theP2_);
				return std::move(s);
			}
			else if (theIndex == 1)
			{
				segment s(theP2_, theP0_);
				return std::move(s);
			}
			else
			{
				segment s(theP0_, theP1_);
				return std::move(s);
			}
			
		}
	};
}

#include <Entity_TriangleI.hxx>

#endif // !_Entity_Triangle_Header
