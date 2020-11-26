#pragma once
#ifndef _fixedValuePointPatchFields_Header
#define _fixedValuePointPatchFields_Header

#include <pointPatchField.hxx>
#include <FixedValuePointPatchField.hxx>
#include <fieldTypes.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	makePointPatchFieldTypedefs
	(
		fixedValue,
		FixedValue,
		pointMesh,
		pointPatch,
		pointPatch,
		DummyMatrix,
		PointPatch
	);

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_fixedValuePointPatchFields_Header
