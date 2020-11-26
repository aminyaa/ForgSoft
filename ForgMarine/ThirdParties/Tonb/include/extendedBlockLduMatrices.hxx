#pragma once
#ifndef _extendedBlockLduMatrices_Header
#define _extendedBlockLduMatrices_Header

#include <sphericalTensorExtendedBlockLduMatrix.hxx>
#include <symmTensorExtendedBlockLduMatrix.hxx>
#include <tensorExtendedBlockLduMatrix.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef extendedBlockLduMatrix<scalar> extendedBlockScalarMatrix;
	typedef extendedBlockLduMatrix<vector> extendedBlockVectorMatrix;
	typedef extendedBlockLduMatrix<sphericalTensor>
		extendedBlockSphericalTensorMatrix;
	typedef extendedBlockLduMatrix<symmTensor> extendedBlockSymmTensorMatrix;
	typedef extendedBlockLduMatrix<tensor> extendedBlockTensorMatrix;


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_extendedBlockLduMatrices_Header
