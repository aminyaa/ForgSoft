#pragma once
#ifndef _symmetryPointPatch_Header
#define _symmetryPointPatch_Header

#include <facePointPatch.hxx>
#include <symmetryPolyPatch.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
				   Class symmetryPointPatch Declaration
	\*---------------------------------------------------------------------------*/

	class symmetryPointPatch
		:
		public facePointPatch
	{

	public:

		//- Runtime type information
		TypeName(symmetryPolyPatch::typeName_());


		// Constructors

			//- Construct from polyPatch
		symmetryPointPatch
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

#endif // !_symmetryPointPatch_Header
