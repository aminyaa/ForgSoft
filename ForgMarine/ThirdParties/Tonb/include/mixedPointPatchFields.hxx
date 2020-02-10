#pragma once
#ifndef _mixedPointPatchFields_Header
#define _mixedPointPatchFields_Header

#include <pointPatchField.hxx>
#include <MixedPointPatchField.hxx>
#include <fieldTypes.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	makePointPatchFieldTypedefs
	(
		mixed,
		Mixed,
		pointMesh,
		pointPatch,
		pointPatch,
		DummyMatrix,
		PointPatch
	);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_mixedPointPatchFields_Header
