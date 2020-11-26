#pragma once
#ifndef _cyclicPointPatchFields_Header
#define _cyclicPointPatchFields_Header

#include <pointPatchField.hxx>
#include <CyclicPointPatchField.hxx>
#include <cyclicPointPatch.hxx>
#include <fieldTypes.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	makeTypePointPatchFieldTypedefs
	(
		cyclic,
		Cyclic,
		pointMesh,
		pointPatch,
		pointPatch,
		PointPatch,
		DummyMatrix,
		cyclicPointPatch
	);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_cyclicPointPatchFields_Header
