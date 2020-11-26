#pragma once
#ifndef _intersection_Header
#define _intersection_Header

#include <scalar.hxx>
#include <NamedEnum.hxx>
#include <tolerancesSwitch.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							Class intersection Declaration
	\*---------------------------------------------------------------------------*/

	class intersection
	{
	public:

		// Static data

			//- Relative tolerance for point in a plane.
			//  The tolerance is relative to the object size.
			//  Used to determine if a half-ray from a point in plane of triangle
			//  intersects the triangle or not.
			//  Adjusting the tolerance from the code does not allow it to be const
			//  HJ, 5/Jan/2008
			//static tnbLib::debug::controlSwitches<scalar> planarTol_;
		static tnbLib::debug::tolerancesSwitch planarTol_;

		//- Intersection miss tolerance, of the order of 1e-15
		static const debug::tolerancesSwitch missTol_;


		enum direction
		{
			VECTOR,
			CONTACT_SPHERE
		};

		enum algorithm
		{
			FULL_RAY,        // Intersecting with full ray
			HALF_RAY,        // Intersecting with half ray
			VISIBLE          // Intersecting with the visible side
		};


		// Static member functions

			//- Direction names
		static const NamedEnum<direction, 2> directionNames_;

		//- Projection algorithm names
		static const NamedEnum<algorithm, 3> algorithmNames_;

		//- Set the planar tolerance, returning the previous value
		static scalar setPlanarTol(const scalar t)
		{
			if (t < -VSMALL)
			{
				FatalErrorIn
				(
					"scalar intersection::setPlanarTol(const scalar t)"
				) << "Negative planar tolerance.  This is not allowed."
					<< abort(FatalError);
			}

			// Ugly violence to allow tolerance to remain a const scalar
			// HJ, 7/Sep/2008
			scalar oldTol = planarTol_();

			planarTol_ = t;

			return oldTol;
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_intersection_Header
