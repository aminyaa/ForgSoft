#pragma once
#ifndef _HormannAgathos_Header
#define _HormannAgathos_Header

#include <List.hxx>
#include <point2D.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						   Class HormannAgathos Declaration
	\*---------------------------------------------------------------------------*/

	class HormannAgathos
	{
		// Private data

			//- 2D coordinate of polygon vertices
			//  We keep the same notation as in the paper
		List<point2D> P_;

		//- 2D distance tolerance factor for in/out tests
		scalar distTol_;

		//- 2D distance epsilon for in/out tests
		scalar epsilon_;


		// Private Member Functions

			//- Compute 2D distance epsilon based on a tolerance factor
		void evaluateEpsilon();

		//- Comparison of two scalar within a tolerance
		bool equalWithTol
		(
			const scalar& a,
			const scalar& b
		) const;

		bool greaterWithTol
		(
			const scalar& a,
			const scalar& b
		) const;

		bool smallerWithTol
		(
			const scalar& a,
			const scalar& b
		) const;

		bool greaterOrEqualWithTol
		(
			const scalar& a,
			const scalar& b
		) const;

		bool smallerOrEqualWithTol
		(
			const scalar& a,
			const scalar& b
		) const;


	public:

		// Public typedefs
		enum inOutClassification
		{
			POINT_OUTSIDE,
			POINT_INSIDE,
			POINT_ON_VERTEX,
			POINT_ON_EDGE
		};

		// Constructors

			//- Construct from components
		HormannAgathos
		(
			const List<point2D>& P,
			const scalar& distTol
		);


		// Destructor - default


		// Member Functions

			//- Executa classification of points
		inOutClassification evaluate(const point2D& R) const;
	};

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <HormannAgathosI.hxx>

#endif // !_HormannAgathos_Header
