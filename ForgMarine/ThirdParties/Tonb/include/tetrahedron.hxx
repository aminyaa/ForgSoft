#pragma once
#ifndef _tetrahedron_Header
#define _tetrahedron_Header

#include <point.hxx>
#include <primitiveFieldsFwd.hxx>
#include <pointHit.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	class Istream;
	class Ostream;

	// Forward declaration of friend functions and operators

	template<class Point, class PointRef> class tetrahedron;

	template<class Point, class PointRef>
	inline Istream& operator>>
		(
			Istream&,
			tetrahedron<Point, PointRef>&
			);

	template<class Point, class PointRef>
	inline Ostream& operator<<
		(
			Ostream&,
			const tetrahedron<Point, PointRef>&
			);


	/*---------------------------------------------------------------------------*\
							   class tetrahedron Declaration
	\*---------------------------------------------------------------------------*/

	template<class Point, class PointRef>
	class tetrahedron
	{
		// Private data

		PointRef a_, b_, c_, d_;


	public:

		// Member constants

		enum
		{
			nVertices = 4,  // Number of vertices in tetrahedron
			nEdges = 6      // Number of edges in tetrahedron
		};


		// Constructors

			//- Construct from points
		tetrahedron
		(
			const Point& a,
			const Point& b,
			const Point& c,
			const Point& d
		);

		//- Construct from Istream
		tetrahedron(Istream&);


		// Member Functions

			// Access

				//- Return vertices
		const Point& a() const;

		const Point& b() const;

		const Point& c() const;

		const Point& d() const;


		// Properties

			//- Return face normal
		vector Sa() const;

		vector Sb() const;

		vector Sc() const;

		vector Sd() const;


		//- Return volume
		scalar mag() const;

		//- Return centre
		vector centre() const;

		//- Return circum-centre
		vector circumCentre() const;

		//- Return circum-radius
		scalar circumRadius() const;

		//- Return (min)containment sphere, i.e. the smallest sphere with
		//  all points inside. Returns pointHit with:
		//  - hit         : if sphere is equal to circumsphere
		//                  (biggest sphere)
		//  - point       : centre of sphere
		//  - distance    : radius of sphere
		//  - eligiblemiss: false
		// Tol (small compared to 1, e.g. 1E-9) is used to determine
		// whether point is inside: mag(pt - ctr) < (1+tol)*radius.
		pointHit containmentSphere(const scalar tol) const;

		//- Fill buffer with shape function products
		void gradNiSquared(scalarField& buffer) const;

		void gradNiDotGradNj(scalarField& buffer) const;

		void gradNiGradNi(tensorField& buffer) const;

		void gradNiGradNj(tensorField& buffer) const;


		// IOstream operators

		friend Istream& operator>> <Point, PointRef>
			(
				Istream&,
				tetrahedron&
				);

		friend Ostream& operator<< <Point, PointRef>
			(
				Ostream&,
				const tetrahedron&
				);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <tetrahedronI.hxx>

#endif // !_tetrahedron_Header
