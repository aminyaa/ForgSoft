#pragma once
#ifndef _coupledPointPatchFields_Header
#define _coupledPointPatchFields_Header

#include <pointPatchField.hxx>
#include <CoupledPointPatchField.hxx>
#include <coupledPointPatch.hxx>
#include <fieldTypes.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	makeTypePointPatchFieldTypedefs
	(
		coupled,
		Coupled,
		pointMesh,
		pointPatch,
		pointPatch,
		PointPatch,
		DummyMatrix,
		coupledPointPatch
	);

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_coupledPointPatchFields_Header
