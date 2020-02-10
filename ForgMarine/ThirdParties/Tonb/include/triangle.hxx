#pragma once
#ifndef _triangle_Header
#define _triangle_Header

#include <intersection.hxx>
#include <vector.hxx>
#include <pointHit.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	class Istream;
	class Ostream;

	// Forward declaration of friend functions and operators

	template<class Point, class PointRef> class triangle;

	template<class Point, class PointRef>
	Istream& operator>>
		(
			Istream&,
			triangle<Point, PointRef>&
			);

	template<class Point, class PointRef>
	Ostream& operator<<
		(
			Ostream&,
			const triangle<Point, PointRef>&
			);


	/*---------------------------------------------------------------------------*\
							   class triangle Declaration
	\*---------------------------------------------------------------------------*/

	template<class Point, class PointRef>
	class triangle
	{
		// Private data

		PointRef a_, b_, c_;

		// Private member functions

			//- Find intersection of triangle (origin V0, spanning edges
			//  E0, E1) with infinite ray (origin P, direction dir) Based
			//  on Graphics Gems - Fast Ray Triangle intersection.  Since
			//  direction is coordinate axis there is no need to do
			//  projection, we can directly check u,v components for
			//  inclusion in triangle.
		static bool intersection
		(
			const Point& baseVertex,
			const vector& E0,
			const vector& E1,
			const vector& n,
			const Point& P,
			const vector& dir,
			Point& pInter
		);

		//- Fast distance to triangle calculation. From
		//  "Distance Between Point and Trangle in 3D"
		//  David Eberly, Magic Software Inc. Aug. 2002.
		//  Works on function Q giving distance to point and tries to
		//  minimize this.
		static pointHit nearestPoint
		(
			const Point& baseVertex,
			const vector& E0,
			const vector& E1,
			const Point& P
		);


	public:

		//- Return types for classify
		enum proxType
		{
			NONE,
			POINT,  // Close to point
			EDGE    // Close to edge
		};


		// Constructors

			//- Construct from three points
		triangle(const Point& a, const Point& b, const Point& c);

		//- Construct from Istream
		triangle(Istream&);


		// Member Functions

			// Access

				//- Return first vertex
		const Point& a() const;

		//- Return second vertex
		const Point& b() const;

		//- Return third vertex
		const Point& c() const;


		// Properties

			//- Return centre (centroid)
		Point centre() const;

		//- Return scalar magnitude
		scalar mag() const;

		//- Return vector normal
		vector normal() const;

		//- Return circum-centre
		vector circumCentre() const;

		//- Return circum-radius
		scalar circumRadius() const;

		//- Return quality: Ratio triangle and circum-circle area
		scalar quality() const;

		//- Return swept-volume
		scalar sweptVol(const triangle& t) const;

		//- Return point intersection with a ray.
		//  For a hit, the distance is signed.  Positive number
		//  represents the point in front of triangle.
		//  In case of miss pointHit is set to nearest point
		//  on triangle and its distance to the distance between
		//  the original point and the plane intersection point
		pointHit ray
		(
			const Point& p,
			const vector& q,
			const intersection::algorithm = intersection::FULL_RAY,
			const intersection::direction dir = intersection::VECTOR
		) const;

		//- Fast intersection with a ray.
		//  For a hit, the pointHit.distance() is the line parameter t :
		//  intersection=p+t*q. Only defined for VISIBLE, FULL_RAY or
		//  HALF_RAY.
		pointHit fastIntersection
		(
			const Point& p,
			const vector& q,
			const intersection::algorithm alg,
			const scalar tol = 0.0
		) const;

		//- Return nearest point to p on triangle
		pointHit nearestPoint
		(
			const Point& p
		) const;

		//- Classify point in triangle plane w.r.t. triangle edges.
		//  - inside (true returned)/outside (false returned)
		//  - near point (nearType=POINT, nearLabel=0, 1, 2)
		//  - near edge (nearType=EDGE, nearLabel=0, 1, 2)
		//    Note: edges are counted from starting
		//    vertex so e.g. edge 2 is from f[2] to f[0]
		//  tol is fraction to account for truncation error. Is only used
		//  when comparing normalized (0..1) numbers.
		bool classify
		(
			const Point& p,
			const scalar tol,
			label& nearType,
			label& nearLabel
		) const;

		//- Return shape function gradient
		vector gradNi(label i) const;

		//- Evaluate shape function at a given point
		scalar Ni(label i, const Point& p) const;


		// IOstream operators

		friend Istream& operator>> <Point, PointRef>
			(
				Istream&,
				triangle&
				);

		friend Ostream& operator<< <Point, PointRef>
			(
				Ostream&,
				const triangle&
				);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <triangleI.hxx>

#endif // !_triangle_Header
