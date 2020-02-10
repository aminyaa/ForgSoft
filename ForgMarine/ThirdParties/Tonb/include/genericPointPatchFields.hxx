#pragma once
#ifndef _genericPointPatchFields_Header
#define _genericPointPatchFields_Header

#include <pointPatchField.hxx>
#include <GenericPointPatchField.hxx>
#include <fieldTypes.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	makePointPatchFieldTypedefs
	(
		generic,
		Generic,
		pointMesh,
		pointPatch,
		pointPatch,
		DummyMatrix,
		PointPatch
	);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_genericPointPatchFields_Header
