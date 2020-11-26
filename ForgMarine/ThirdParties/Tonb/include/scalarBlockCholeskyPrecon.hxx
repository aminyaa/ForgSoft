#pragma once
#ifndef _scalarBlockCholeskyPrecon_Header
#define _scalarBlockCholeskyPrecon_Header

#include <BlockCholeskyPrecon.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	template<>
	void tnbLib::BlockCholeskyPrecon<scalar>::calcPreconDiag();

	template<>
	void tnbLib::BlockCholeskyPrecon<scalar>::precondition
	(
		scalarField& x,
		const scalarField& b
	) const;


	template<>
	void tnbLib::BlockCholeskyPrecon<scalar>::preconditionT
	(
		scalarField& xT,
		const scalarField& bT
	) const;


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_scalarBlockCholeskyPrecon_Header
