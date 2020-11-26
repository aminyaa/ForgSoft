#pragma once
#ifndef _emptyPointPatch_Header
#define _emptyPointPatch_Header

#include <facePointPatch.hxx>
#include <emptyPolyPatch.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						  Class emptyPointPatch Declaration
	\*---------------------------------------------------------------------------*/

	class emptyPointPatch
		: public facePointPatch
	{

	public:

		//- Runtime type information
		TypeName(emptyPolyPatch::typeName_());


		// Constructors

			//- Construct from polyPatch
		emptyPointPatch
		(
			const polyPatch& patch,
			const pointBoundaryMesh& bm
		)
			:
			facePointPatch(patch, bm)
		{}


		// Destructor

		virtual ~emptyPointPatch()
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

#endif // !_emptyPointPatch_Header
