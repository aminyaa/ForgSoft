#pragma once
#ifndef _cohesivePointPatch_Header
#define _cohesivePointPatch_Header

#include <facePointPatch.hxx>
#include <cohesivePolyPatch.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						   Class cohesivePointPatch Declaration
	\*---------------------------------------------------------------------------*/

	class cohesivePointPatch
		: public facePointPatch
	{

	public:

		//- Runtime type information
		TypeName(cohesivePolyPatch::typeName_());


		// Constructors

			//- Construct from polyPatch
		cohesivePointPatch
		(
			const polyPatch& patch,
			const pointBoundaryMesh& bm
		)
			:
			facePointPatch(patch, bm)
		{}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_cohesivePointPatch_Header
