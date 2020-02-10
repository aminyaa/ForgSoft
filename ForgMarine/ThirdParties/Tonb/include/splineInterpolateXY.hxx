#pragma once
#ifndef _splineInterpolateXY_Header
#define _splineInterpolateXY_Header

#include <scalarField.hxx>
#include <NamedEnum.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						Class splineInterpolateXY Declaration
	\*---------------------------------------------------------------------------*/

	class splineInterpolateXY
	{
	public:

		//- Types of spline boundary condition
		enum splineBCType
		{
			NOT_A_KNOT,
			NATURAL
		};

		static const NamedEnum<splineBCType, 2> splineBCTypeNames;


	private:

		// Private data

			//- Given x-data
		scalarField X_;

		//- Given y-data
		scalarField Y_;

		//- Second derivative data
		scalarField Y2_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		splineInterpolateXY(const splineInterpolateXY&);

		//- Disallow default bitwise assignment
		void operator=(const splineInterpolateXY&);


		//- Initialize spline with given values
		void setData
		(
			const splineBCType& startBC,
			const splineBCType& endBC
		);


	public:

		// Constructors

			//- Construct from components
		splineInterpolateXY
		(
			const scalarField& x,
			const scalarField& y,
			const word& startSplineBCs,
			const word& endSplineBCs
		);

		// Destructor - default


		// Member Functions

			//- Return interpolated value at given location xStar
		scalar interpolate(const scalar xStar) const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_splineInterpolateXY_Header
