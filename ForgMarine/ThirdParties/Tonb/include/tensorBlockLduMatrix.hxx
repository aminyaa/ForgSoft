#pragma once
#ifndef _tensorBlockLduMatrix_Header
#define _tensorBlockLduMatrix_Header

#include <BlockLduMatrix.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	template<>
	void BlockLduMatrix<tensor>::sumDiag();

	template<>
	void BlockLduMatrix<tensor>::negSumDiag();

	template<>
	void BlockLduMatrix<tensor>::check() const;

	template<>
	void BlockLduMatrix<tensor>::relax
	(
		const tensorField& x,
		tensorField& b,
		const scalar alpha
	);

	template<>
	void BlockLduMatrix<tensor>::operator*=(const scalarField& sf);

	template<>
	void BlockLduMatrix<tensor>::AmulCore
	(
		tensorField& mul,
		const tensorField& x
	) const;

	template<>
	void BlockLduMatrix<tensor>::TmulCore
	(
		tensorField& mul,
		const tensorField& x
	) const;

	template<>
	void BlockLduMatrix<tensor>::segregateB
	(
		tensorField& mul,
		const tensorField& x
	) const;


	template<>
	tmp<tensorField> BlockLduMatrix<tensor>::H(const tensorField& x) const;

	template<>
	tmp<tensorField> BlockLduMatrix<tensor>::faceH(const tensorField& x) const;



	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_tensorBlockLduMatrix_Header
