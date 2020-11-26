#pragma once
#ifndef _FadOneField_Header
#define _FadOneField_Header

#include <FadOne.hxx>
#include <Field.hxx>
#include <scalarField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	template<int nVars>
	tmp<Field<FadOne<nVars>>> ValueFadOneField(const UList<scalar>&);


	template<int nVars>
	tmp<scalarField> FadOneValue(const Field<FadOne<nVars> >&);

	template<int nVars>
	void FadOneSetValue
	(
		Field<FadOne<nVars> >&,
		const scalarField&
	);

	template<int nVars>
	tmp<scalarField> FadOneDeriv
	(
		const Field<FadOne<nVars> >&,
		const direction
	);

	template<int nVars>
	void FadOneSetDeriv
	(
		Field<FadOne<nVars> >&,
		const direction,
		const scalarField&
	);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

#ifdef NoRepository
#   include <FadOneField.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_FadOneField_Header
