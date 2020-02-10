#pragma once
#ifndef _zeroGradientPointPatchFields_Header
#define _zeroGradientPointPatchFields_Header

#include <pointPatchField.hxx>
#include <zeroGradientPointPatchField.hxx>
#include <fieldTypes.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	makePointPatchFieldTypedefs
	(
		zeroGradient,
		ZeroGradient,
		pointMesh,
		pointPatch,
		pointPatch,
		DummyMatrix,
		PointPatch
	);

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_zeroGradientPointPatchFields_Header
