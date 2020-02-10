#pragma once
#ifndef _wedgePointPatch_Header
#define _wedgePointPatch_Header

#include <facePointPatch.hxx>
#include <wedgePolyPatch.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						   Class wedgePointPatch Declaration
	\*---------------------------------------------------------------------------*/

	class wedgePointPatch
		:
		public facePointPatch
	{

	public:

		//- Runtime type information
		TypeName(wedgePolyPatch::typeName_());


		// Constructors

			//- Construct from polyPatch
		wedgePointPatch
		(
			const polyPatch& patch,
			const pointBoundaryMesh& bm
		)
			:
			facePointPatch(patch, bm)
		{}


		// Member Functions

			//- Accumulate the effect of constraint direction of this patch
		virtual void applyConstraint
		(
			const label pointi,
			pointConstraint&
		) const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_wedgePointPatch_Header
