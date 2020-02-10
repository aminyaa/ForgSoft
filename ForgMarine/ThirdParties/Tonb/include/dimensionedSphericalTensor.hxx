#pragma once
#ifndef _dimensionedSphericalTensor_Header
#define _dimensionedSphericalTensor_Header

#include <dimensionedType.hxx>
#include <sphericalTensor.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef dimensioned<sphericalTensor> dimensionedSphericalTensor;


	// global functions

	dimensionedScalar tr(const dimensionedSphericalTensor&);
	dimensionedScalar det(const dimensionedSphericalTensor&);
	dimensionedSphericalTensor inv(const dimensionedSphericalTensor&);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_dimensionedSphericalTensor_Header
