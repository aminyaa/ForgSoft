#pragma once
#ifndef _pointFieldsFwd_Header
#define _pointFieldsFwd_Header

#include <fieldTypes.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	class pointMesh;

	template<class Type>
	class pointPatchField;

	template<class Type, template<class> class PatchField, class GeoMesh>
	class GeometricField;

	typedef GeometricField<scalar, pointPatchField, pointMesh> pointScalarField;
	typedef GeometricField<vector, pointPatchField, pointMesh> pointVectorField;
	typedef GeometricField<sphericalTensor, pointPatchField, pointMesh>
		pointSphericalTensorField;
	typedef GeometricField<symmTensor, pointPatchField, pointMesh>
		pointSymmTensorField;
	typedef GeometricField<symmTensor4thOrder, pointPatchField, pointMesh>
		pointSymmTensor4thOrderField;
	typedef GeometricField<diagTensor, pointPatchField, pointMesh>
		pointDiagTensorField;
	typedef GeometricField<tensor, pointPatchField, pointMesh> pointTensorField;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_pointFieldsFwd_Header
