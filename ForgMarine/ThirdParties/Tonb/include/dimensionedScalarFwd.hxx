#pragma once
#ifndef _dimensionedScalarFwd_Header
#define _dimensionedScalarFwd_Header

#include <scalar.hxx>

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	template<class Type>
	class dimensioned;

	typedef dimensioned<scalar> dimensionedScalar;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#endif // !_dimensionedScalarFwd_Header
