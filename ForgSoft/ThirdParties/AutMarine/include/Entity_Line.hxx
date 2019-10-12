#pragma once
#ifndef _Entity_Line_Header
#define _Entity_Line_Header

#include <Traits.hxx>
#include <Entity2d_LineRef.hxx>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

namespace AutLib
{

	template<class PointRef, class DirectRef>
	class Entity_Line
	{

		typedef typename remove_reference<PointRef>::type Point;
		typedef typename remove_reference<DirectRef>::type Direct;

		template< bool cond, typename U >
		using resolvedType = typename std::enable_if< cond, U >::type;

		friend class boost::serialization::access;

		/*Private Data*/

		PointRef theP_;
		DirectRef theDir_;


		template<class Archive>
		void serialize(Archive& ar, const unsigned int version);

	public:

		Entity_Line()
			: theP_(Point::null)
			, theDir_(Direct::null)
		{}

		Entity_Line
		(
			const Point& theP, 
			const Direct& theV
		)
			: theP_(theP)
			, theDir_(theV)
		{}

		const Point& P() const
		{
			return theP_;
		}

		Point& P()
		{
			return const_cast<Point&>(theP_);
		}

		const Direct& Dir() const
		{
			return theDir_;
		}

		Direct& Dir()
		{
			return const_cast<Direct&>(theDir_);
		}
	};
}

#include <Entity_LineI.hxx>

#endif // !_Entity_Line_Header
