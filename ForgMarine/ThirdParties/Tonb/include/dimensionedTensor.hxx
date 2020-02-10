#pragma once
#ifndef _dimensionedTensor_Header
#define _dimensionedTensor_Header

#include <dimensionedVector.hxx>
#include <dimensionedSymmTensor.hxx>
#include <tensor.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef dimensioned<tensor> dimensionedTensor;


	// global functions

	dimensionedScalar tr(const dimensionedTensor&);
	dimensionedTensor dev(const dimensionedTensor&);
	dimensionedTensor dev2(const dimensionedTensor&);
	dimensionedScalar det(const dimensionedTensor&);
	dimensionedTensor cof(const dimensionedTensor&);
	dimensionedTensor inv(const dimensionedTensor&);
	dimensionedTensor hinv(const dimensionedTensor&);
	dimensionedSymmTensor symm(const dimensionedTensor&);
	dimensionedSymmTensor twoSymm(const dimensionedTensor&);
	dimensionedTensor skew(const dimensionedTensor&);

	dimensionedVector eigenValues(const dimensionedTensor&);
	dimensionedTensor eigenVectors(const dimensionedTensor&);

	dimensionedVector eigenValues(const dimensionedSymmTensor&);
	dimensionedTensor eigenVectors(const dimensionedSymmTensor&);


	// global operators

	//- Hodge Dual operator (tensor -> vector)
	dimensionedVector operator*(const dimensionedTensor&);

	//- Hodge Dual operator (vector -> tensor)
	dimensionedTensor operator*(const dimensionedVector&);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_dimensionedTensor_Header
