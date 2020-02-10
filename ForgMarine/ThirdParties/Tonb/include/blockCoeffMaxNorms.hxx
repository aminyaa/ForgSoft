#pragma once
#ifndef _blockCoeffMaxNorms_Header
#define _blockCoeffMaxNorms_Header

#include <scalarBlockCoeffMaxNorm.hxx>
#include <tensorBlockCoeffMaxNorm.hxx>
#include <BlockCoeffNorm.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef BlockCoeffMaxNorm<scalar> blockCoeffMaxNormScalar;
	typedef BlockCoeffMaxNorm<vector> blockCoeffMaxNormVector;
	typedef BlockCoeffMaxNorm<tensor> blockCoeffMaxNormTensor;


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_blockCoeffMaxNorms_Header
