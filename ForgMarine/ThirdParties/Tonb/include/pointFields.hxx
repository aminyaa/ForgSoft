#pragma once
#ifndef _pointFields_Header
#define _pointFields_Header

#include <GeometricFields.hxx>
#include <fieldTypes.hxx>
#include <pointPatchFields.hxx>
#include <pointMesh.hxx>
#include <pointFieldsFwd.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef GeometricField<scalar, pointPatchField, pointMesh> pointScalarField;
	typedef GeometricField<vector, pointPatchField, pointMesh> pointVectorField;
	typedef GeometricField<tensor, pointPatchField, pointMesh> pointTensorField;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_pointFields_Header
