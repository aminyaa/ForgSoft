#pragma once
#ifndef _dimensionedSymmTensor_Header
#define _dimensionedSymmTensor_Header

#include <dimensionedVector.hxx>
#include <dimensionedType.hxx>
#include <symmTensor.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef dimensioned<symmTensor> dimensionedSymmTensor;


	// global functions

	dimensionedSymmTensor sqr(const dimensionedVector&);
	dimensionedSymmTensor innerSqr(const dimensionedSymmTensor&);

	dimensionedScalar tr(const dimensionedSymmTensor&);
	dimensionedSymmTensor symm(const dimensionedSymmTensor&);
	dimensionedSymmTensor twoSymm(const dimensionedSymmTensor&);
	dimensionedSymmTensor dev(const dimensionedSymmTensor&);
	dimensionedSymmTensor dev2(const dimensionedSymmTensor&);
	dimensionedScalar det(const dimensionedSymmTensor&);
	dimensionedSymmTensor cof(const dimensionedSymmTensor&);
	dimensionedSymmTensor inv(const dimensionedSymmTensor&);
	dimensionedSymmTensor hinv(const dimensionedSymmTensor&);


	// global operators

	//- Hodge Dual operator (tensor -> vector)
	dimensionedVector operator*(const dimensionedSymmTensor&);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_dimensionedSymmTensor_Header
