#pragma once
#ifndef _blockCoeffNorms_Header
#define _blockCoeffNorms_Header

#include <BlockCoeffNorm.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef BlockCoeffNorm<scalar> blockScalarCoeffNorm;
	typedef BlockCoeffNorm<vector> blockVectorCoeffNorm;
	typedef BlockCoeffNorm<tensor> blockTensorCoeffNorm;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_blockCoeffNorms_Header
