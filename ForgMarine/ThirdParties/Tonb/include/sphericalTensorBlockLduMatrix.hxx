#pragma once
#ifndef _sphericalTensorBlockLduMatrix_Header
#define _sphericalTensorBlockLduMatrix_Header

#include <BlockLduMatrix.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	template<>
	void BlockLduMatrix<sphericalTensor>::sumDiag();

	template<>
	void BlockLduMatrix<sphericalTensor>::negSumDiag();

	template<>
	void BlockLduMatrix<sphericalTensor>::check() const;

	template<>
	void BlockLduMatrix<sphericalTensor>::relax
	(
		const sphericalTensorField& x,
		sphericalTensorField& b,
		const scalar alpha
	);

	template<>
	void BlockLduMatrix<sphericalTensor>::operator*=(const scalarField& sf);

	template<>
	void BlockLduMatrix<sphericalTensor>::AmulCore
	(
		sphericalTensorField& mul,
		const sphericalTensorField& x
	) const;

	template<>
	void BlockLduMatrix<sphericalTensor>::TmulCore
	(
		sphericalTensorField& mul,
		const sphericalTensorField& x
	) const;

	template<>
	void BlockLduMatrix<sphericalTensor>::segregateB
	(
		sphericalTensorField& mul,
		const sphericalTensorField& x
	) const;


	template<>
	tmp<sphericalTensorField>
		BlockLduMatrix<sphericalTensor>::H(const sphericalTensorField& x) const;

	template<>
	tmp<sphericalTensorField>
		BlockLduMatrix<sphericalTensor>::faceH(const sphericalTensorField& x) const;


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_sphericalTensorBlockLduMatrix_Header
