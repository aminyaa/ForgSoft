#pragma once
#ifndef _pointPatchFieldsFwd_Header
#define _pointPatchFieldsFwd_Header

#include <fieldTypes.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	template<class Type> class pointPatchField;

	typedef pointPatchField<scalar> pointPatchScalarField;
	typedef pointPatchField<vector> pointPatchVectorField;
	typedef pointPatchField<sphericalTensor> pointPatchSphericalTensorField;
	typedef pointPatchField<symmTensor> pointPatchSymmTensorField;
	typedef pointPatchField<symmTensor4thOrder> pointPatchSymmTensor4thOrderField;
	typedef pointPatchField<diagTensor> pointPatchDiagTensorField;
	typedef pointPatchField<tensor> pointPatchTensorField;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_pointPatchFieldsFwd_Header
