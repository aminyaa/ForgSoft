#pragma once
#ifndef _interpolateXY_Header
#define _interpolateXY_Header

#include <scalar.hxx>
#include <primitiveFieldsFwd.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	template<class Type>
	Field<Type> interpolateXY
	(
		const scalarField& xNew,
		const scalarField& xOld,
		const Field<Type>& yOld
	);


	template<class Type>
	Type interpolateXY
	(
		const scalar x,
		const scalarField& xOld,
		const Field<Type>& yOld
	);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <interpolateXY.cxx>
#endif

#endif // !_interpolateXY_Header
