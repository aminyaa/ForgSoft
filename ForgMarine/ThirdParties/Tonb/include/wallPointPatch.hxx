#pragma once
#ifndef _wallPointPatch_Header
#define _wallPointPatch_Header

#include <facePointPatch.hxx>
#include <wallPolyPatch.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						   Class wallPointPatch Declaration
	\*---------------------------------------------------------------------------*/

	class wallPointPatch
		: public facePointPatch
	{

	public:

		//- Runtime type information
		TypeName(wallPolyPatch::typeName_());


		// Constructors

			//- Construct from polyPatch
		wallPointPatch
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

#endif // !_wallPointPatch_Header
