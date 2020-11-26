#pragma once
#ifndef _symmetryPointPatchFields_Header
#define _symmetryPointPatchFields_Header

#include <pointPatchField.hxx>
#include <SymmetryPointPatchField.hxx>
#include <symmetryPointPatch.hxx>
#include <fieldTypes.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	makeTypePointPatchFieldTypedefs
	(
		symmetry,
		Symmetry,
		pointMesh,
		pointPatch,
		pointPatch,
		PointPatch,
		DummyMatrix,
		symmetryPointPatch
	);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_symmetryPointPatchFields_Header
