#pragma once
#ifndef _processorPointPatchFields_Header
#define _processorPointPatchFields_Header

#include <pointPatchField.hxx>
#include <ProcessorPointPatchField.hxx>
#include <processorPointPatch.hxx>
#include <fieldTypes.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	makeTypePointPatchFieldTypedefs
	(
		processor,
		Processor,
		pointMesh,
		pointPatch,
		pointPatch,
		PointPatch,
		DummyMatrix,
		processorPointPatch
	);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_processorPointPatchFields_Header
