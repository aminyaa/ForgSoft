#pragma once
#ifndef _scalarBlockLduMatrix_Header
#define _scalarBlockLduMatrix_Header

#include <BlockLduMatrix.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	template<>
	void BlockLduMatrix<scalar>::sumDiag();

	template<>
	void BlockLduMatrix<scalar>::negSumDiag();

	template<>
	void BlockLduMatrix<scalar>::check() const;

	template<>
	void BlockLduMatrix<scalar>::relax
	(
		const scalarField& x,
		scalarField& b,
		const scalar alpha
	);

	template<>
	void BlockLduMatrix<scalar>::operator*=(const scalarField& sf);

	template<>
	void BlockLduMatrix<scalar>::AmulCore
	(
		scalarField& mul,
		const scalarField& x
	) const;

	template<>
	void BlockLduMatrix<scalar>::TmulCore
	(
		scalarField& mul,
		const scalarField& x
	) const;

	template<>
	void BlockLduMatrix<scalar>::segregateB
	(
		scalarField& mul,
		const scalarField& x
	) const;

	template<>
	tmp<scalarField> BlockLduMatrix<scalar>::H(const scalarField& x) const;

	template<>
	tmp<scalarField> BlockLduMatrix<scalar>::faceH(const scalarField& x) const;


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_scalarBlockLduMatrix_Header
