#pragma once
#ifndef _blockCoeffTwoNorms_Header
#define _blockCoeffTwoNorms_Header

#include <tensorBlockCoeffTwoNorm.hxx>
#include <BlockCoeffTwoNorm.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef BlockCoeffTwoNorm<scalar> blockCoeffTwoNormScalar;
	typedef BlockCoeffTwoNorm<vector> blockCoeffTwoNormVector;
	typedef BlockCoeffTwoNorm<tensor> blockCoeffTwoNormTensor;


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_blockCoeffTwoNorms_Header
