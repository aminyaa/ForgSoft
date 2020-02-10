#pragma once
#ifndef _symmTensorBlockLduMatrix_Header
#define _symmTensorBlockLduMatrix_Header

#include <BlockLduMatrix.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	template<>
	void BlockLduMatrix<symmTensor>::sumDiag();

	template<>
	void BlockLduMatrix<symmTensor>::negSumDiag();

	template<>
	void BlockLduMatrix<symmTensor>::check() const;

	template<>
	void BlockLduMatrix<symmTensor>::relax
	(
		const symmTensorField& x,
		symmTensorField& b,
		const scalar alpha
	);

	template<>
	void BlockLduMatrix<symmTensor>::operator*=(const scalarField& sf);

	template<>
	void BlockLduMatrix<symmTensor>::AmulCore
	(
		symmTensorField& mul,
		const symmTensorField& x
	) const;

	template<>
	void BlockLduMatrix<symmTensor>::TmulCore
	(
		symmTensorField& mul,
		const symmTensorField& x
	) const;

	template<>
	void BlockLduMatrix<symmTensor>::segregateB
	(
		symmTensorField& mul,
		const symmTensorField& x
	) const;


	template<>
	tmp<symmTensorField>
		BlockLduMatrix<symmTensor>::H(const symmTensorField& x) const;

	template<>
	tmp<symmTensorField>
		BlockLduMatrix<symmTensor>::faceH(const symmTensorField& x) const;


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_symmTensorBlockLduMatrix_Header
