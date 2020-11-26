#pragma once
#ifndef _genericPointPatch_Header
#define _genericPointPatch_Header

#include <facePointPatch.hxx>
#include <genericPolyPatch.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						   Class genericPointPatch Declaration
	\*---------------------------------------------------------------------------*/

	class genericPointPatch
		: public facePointPatch
	{

	public:

		//- Runtime type information
		TypeName(genericPolyPatch::typeName_());


		// Constructors

			//- Construct from polyPatch
		genericPointPatch
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

#endif // !_genericPointPatch_Header
