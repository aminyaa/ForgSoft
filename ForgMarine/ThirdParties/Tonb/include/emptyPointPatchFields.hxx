#pragma once
#ifndef _emptyPointPatchFields_Header
#define _emptyPointPatchFields_Header

#include <pointPatchField.hxx>
#include <EmptyPointPatchField.hxx>
#include <emptyPointPatch.hxx>
#include <fieldTypes.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	makeTypePointPatchFieldTypedefs
	(
		empty,
		Empty,
		pointMesh,
		pointPatch,
		pointPatch,
		PointPatch,
		DummyMatrix,
		emptyPointPatch
	);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_emptyPointPatchFields_Header
