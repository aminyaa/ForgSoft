#pragma once
#ifndef _dimensionedDiagTensor_Header
#define _dimensionedDiagTensor_Header

#include <dimensionedVector.hxx>
#include <dimensionedTensor.hxx>
#include <diagTensor.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef dimensioned<diagTensor> dimensionedDiagTensor;


	// friend functions

	dimensionedScalar tr(const dimensionedDiagTensor&);
	dimensionedScalar det(const dimensionedDiagTensor&);
	dimensionedDiagTensor inv(const dimensionedDiagTensor&);
	dimensionedDiagTensor diag(const dimensionedTensor&);

	// friend operators


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_dimensionedDiagTensor_Header
