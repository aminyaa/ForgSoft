#pragma once
#ifndef _coeffFields_Header
#define _coeffFields_Header

#include <scalarCoeffField.hxx>
#include <sphericalTensorCoeffField.hxx>
#include <symmTensorCoeffField.hxx>
#include <tensorCoeffField.hxx>
#include <symmTensor4thOrderCoeffField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef CoeffField<scalar> scalarCoeffField;
	typedef CoeffField<vector> vectorCoeffField;
	typedef CoeffField<sphericalTensor> sphericalTensorCoeffField;
	typedef CoeffField<symmTensor> diagTensorCoeffField;
	typedef CoeffField<symmTensor> symmTensorCoeffField;
	typedef CoeffField<tensor> tensorCoeffField;
	typedef CoeffField<symmTensor4thOrder> symmTensor4thOrderCoeffField;


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_coeffFields_Header
