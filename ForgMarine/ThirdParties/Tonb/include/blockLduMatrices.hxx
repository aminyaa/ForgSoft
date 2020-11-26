#pragma once
#ifndef _blockLduMatrices_Header
#define _blockLduMatrices_Header

#include <scalarBlockLduMatrix.hxx>
#include <sphericalTensorBlockLduMatrix.hxx>
#include <symmTensorBlockLduMatrix.hxx>
#include <tensorBlockLduMatrix.hxx>
#include <Map.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef BlockLduMatrix<scalar> blockScalarMatrix;
	typedef BlockLduMatrix<vector> blockVectorMatrix;
	typedef BlockLduMatrix<sphericalTensor> blockSphericalTensorMatrix;
	typedef BlockLduMatrix<symmTensor> blockSymmTensorMatrix;
	typedef BlockLduMatrix<tensor> blockTensorMatrix;


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_blockLduMatrices_Header
