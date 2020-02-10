#pragma once
#ifndef _oscillatingFixedValuePointPatchFields_Header
#define _oscillatingFixedValuePointPatchFields_Header

#include <pointPatchField.hxx>
#include <OscillatingFixedValuePointPatchField.hxx>
#include <fieldTypes.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	makePointPatchFieldTypedefs
	(
		oscillatingFixedValue,
		OscillatingFixedValue,
		pointMesh,
		pointPatch,
		pointPatch,
		DummyMatrix,
		PointPatch
	);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_oscillatingFixedValuePointPatchFields_Header
