#pragma once
#ifndef _blockCoeffComponentNorms_Header
#define _blockCoeffComponentNorms_Header

#include <BlockCoeffComponentNorm.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef BlockCoeffComponentNorm<scalar> blockCoeffComponentNormScalar;
	typedef BlockCoeffComponentNorm<vector> blockCoeffComponentNormVector;
	typedef BlockCoeffComponentNorm<tensor> blockCoeffComponentNormTensor;


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_blockCoeffComponentNorms_Header
