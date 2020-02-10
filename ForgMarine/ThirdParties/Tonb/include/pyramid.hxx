#pragma once
#ifndef _pyramid_Header
#define _pyramid_Header

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Forward declaration of friend functions and operators
	class Istream;
	class Ostream;

	template<class Point, class PointRef, class polygonRef>
	class pyramid;

	template<class Point, class PointRef, class polygonRef>
	inline Istream& operator>>
		(
			Istream&,
			pyramid<Point, PointRef, polygonRef>&
			);

	template<class Point, class PointRef, class polygonRef>
	inline Ostream& operator<<
		(
			Ostream&,
			const pyramid<Point, PointRef, polygonRef>&
			);


	/*---------------------------------------------------------------------------*\
							   Class pyramid Declaration
	\*---------------------------------------------------------------------------*/

	template<class Point, class PointRef, class polygonRef>
	class pyramid
	{
		// Private data

		polygonRef base_;
		PointRef apex_;


	public:

		// Constructors

			//- Construct from base polygon and apex point
		pyramid(polygonRef base, const Point& apex);

		//- Construct from Istream
		pyramid(Istream&);


		// Member functions

			// Access

				//- Return apex point
		const Point& apex() const;

		//- Return base polygon
		polygonRef base() const;


		// Properties

			//- Return centre (centroid)
		Point centre(const pointField& points) const;

		//- Return height vector
		vector height(const pointField& points) const;

		//- Return scalar magnitude - returns volume of pyramid
		scalar mag(const pointField& points) const;


		// IOstream operators

		friend Istream& operator>> <Point, PointRef, polygonRef>
			(
				Istream&,
				pyramid&
				);

		friend Ostream& operator<< <Point, PointRef, polygonRef>
			(
				Ostream&,
				const pyramid&
				);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <pyramidI.hxx>

#endif // !_pyramid_Header
