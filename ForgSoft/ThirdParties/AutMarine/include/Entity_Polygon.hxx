#pragma once
#ifndef _Entity_Polygon_Header
#define _Entity_Polygon_Header

#include <Standard_TypeDef.hxx>
#include <OFstream.hxx>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include <vector>
#include <fstream>

namespace AutLib
{

	template<class Point>
	class Entity_Polygon
	{

		typedef std::vector<Point> pointList;

		friend class boost::serialization::access;

		/*Private Data*/

		pointList thePoints_;

		Standard_Real theDeflection_;


		template<class Archive>
		void serialize(Archive& ar, const unsigned int version);

	public:

		Entity_Polygon()
		{}

		Entity_Polygon
		(
			const pointList& thePoints,
			const Standard_Real theDeflection
		)
			: thePoints_(thePoints)
			, theDeflection_(theDeflection)
		{}

		Entity_Polygon Reversed() const
		{
			Entity_Polygon copy = *this;
			copy.Reverse();
			return std::move(copy);
		}

		const pointList& Points() const
		{
			return thePoints_;
		}

		pointList& Points()
		{
			return thePoints_;
		}

		Standard_Real Deflection() const
		{
			return theDeflection_;
		}

		Standard_Real& Deflection()
		{
			return theDeflection_;
		}

		Standard_Integer NbPoints() const
		{
			return (Standard_Integer)thePoints_.size();
		}

		Standard_Boolean IsClosed() const
		{
			const auto& p0 = thePoints_[0];
			const auto& p1 = thePoints_[thePoints_.size() - 1];

			return p0.Distance(p1) <= gp::Resolution();
		}

		const Point& GetPoint(const Standard_Integer theIndex) const
		{
			return thePoints_[theIndex];
		}

		Point& GetPoint(const Standard_Integer theIndex)
		{
			return thePoints_[theIndex];
		}

		void Reverse();

		void Smoothing(const Standard_Real Omega, const Standard_Integer NbIterations);

		void ExportToPlt(std::fstream& File) const;

		void ExportToPlt(OFstream& File) const;
	};
}

#include <Entity_PolygonI.hxx>

#endif // !_Entity_Polygon_Header
