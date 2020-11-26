#pragma once
#ifndef _line_Header
#define _line_Header

#include <vector.hxx>
#include <PointHitTemplate.hxx>
#include <point2D.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Forward declaration of classes

	class Istream;
	class Ostream;


	// Forward declaration of friend functions and operators

	template<class Point, class PointRef> class line;

	template<class Point, class PointRef>
	inline Istream& operator>>(Istream&, line<Point, PointRef>&);

	template<class Point, class PointRef>
	inline Ostream& operator<<(Ostream&, const line<Point, PointRef>&);


	/*---------------------------------------------------------------------------*\
							   Class line Declaration
	\*---------------------------------------------------------------------------*/

	template<class Point, class PointRef>
	class line
	{
		// Private data

		PointRef a_, b_;


	public:

		// Constructors

			//- Construct from two points
		line(const Point& start, const Point& end);

		//- Construct from Istream
		line(Istream&);


		// Member functions

			// Access

				//- Return first vertex
		PointRef start() const;

		//- Return second vertex
		PointRef end() const;


		// Properties

			//- Return centre (centroid)
		Point centre() const;

		//- Return scalar magnitude
		scalar mag() const;

		//- Return start-end vector
		Point vec() const;

		//- Return nearest distance to line from a given point
		//  If the nearest point is on the line, return a hit
		PointHit<Point> nearestDist(const Point& p) const;

		//- Return nearest distance from line to line. Returns distance
		//  and sets both points (one on *this, one on the provided
		//  linePointRef.
		scalar nearestDist
		(
			const line<Point, const Point&>& edge,
			Point& thisPoint,
			Point& edgePoint
		) const;


		// Ostream operator

		friend Istream& operator>> <Point, PointRef>
			(
				Istream&,
				line&
				);

		friend Ostream& operator<< <Point, PointRef>
			(
				Ostream&,
				const line&
				);
	};


	//- 2D specialisation
	template<>
	scalar line<point2D, const point2D&>::nearestDist
	(
		const line<point2D, const point2D&>& edge,
		point2D& thisPoint,
		point2D& edgePoint
	) const;


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <lineI.hxx>

#endif // !_line_Header
