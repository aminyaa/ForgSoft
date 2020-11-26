#pragma once
#ifndef _uniformDimensionedFields_Header
#define _uniformDimensionedFields_Header

#include <UniformDimensionedField.hxx>
#include <fieldTypes.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef UniformDimensionedField<scalar> uniformDimensionedScalarField;
	typedef UniformDimensionedField<vector> uniformDimensionedVectorField;
	typedef UniformDimensionedField<sphericalTensor> uniformDimensionedSphericalTensorField;
	typedef UniformDimensionedField<symmTensor> uniformDimensionedSymmTensorField;
	typedef UniformDimensionedField<symmTensor4thOrder> uniformDimensionedSymmTensor4thOrderField;
	typedef UniformDimensionedField<diagTensor> uniformDimensionedDiagTensorField;
	typedef UniformDimensionedField<tensor> uniformDimensionedTensorField;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_uniformDimensionedFields_Header
