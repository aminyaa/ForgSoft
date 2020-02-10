#pragma once
#ifndef _complexFields_Header
#define _complexFields_Header

#include <complex.hxx>
#include <complexVector.hxx>
#include <primitiveFields.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef Field<complex> complexField;

	complexField ComplexField(const UList<scalar>&, const UList<scalar>&);
	complexField ReComplexField(const UList<scalar>&);
	complexField ImComplexField(const UList<scalar>&);
	scalarField Re(const UList<complex>&);
	scalarField Im(const UList<complex>&);
	scalarField ReImSum(const UList<complex>&);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef Field<complexVector> complexVectorField;

	complexVectorField ComplexField(const UList<vector>&, const UList<vector>&);
	complexVectorField ReComplexField(const UList<vector>&);
	complexVectorField ImComplexField(const UList<vector>&);
	vectorField Re(const UList<complexVector>&);
	vectorField Im(const UList<complexVector>&);
	vectorField ReImSum(const UList<complexVector>&);

	complexVectorField operator^
		(
			const UList<vector>&,
			const UList<complexVector>&
			);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_complexFields_Header
