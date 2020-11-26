#pragma once
#ifndef _scalarBlockILUCpPrecon_Header
#define _scalarBlockILUCpPrecon_Header

#include <BlockILUCpPrecon.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Calculate active type factorization
	template<>
	template<>
	void BlockILUCpPrecon<scalar>::calcActiveTypeFactorization
	(
		scalarField& preconD,
		scalarField& extUpper,
		scalarField& extLower
	) const;


	// Calculate factorization (constructor helper)
	template<>
	void BlockILUCpPrecon<scalar>::calcFactorization() const;


	// Precondition
	template<>
	void BlockILUCpPrecon<scalar>::precondition
	(
		scalarField& x,
		const scalarField& b
	) const;


	// Precondition transpose
	template<>
	void BlockILUCpPrecon<scalar>::preconditionT
	(
		scalarField& xT,
		const scalarField& bT
	) const;


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_scalarBlockILUCpPrecon_Header
