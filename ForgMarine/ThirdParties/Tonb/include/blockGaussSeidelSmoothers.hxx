#pragma once
#ifndef _blockGaussSeidelSmoothers_Header
#define _blockGaussSeidelSmoothers_Header

#include <BlockGaussSeidelSmoother.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef BlockGaussSeidelSmoother<scalar> blockGaussSeidelSmootherScalar;
	typedef BlockGaussSeidelSmoother<vector> blockGaussSeidelSmootherVector;
	typedef BlockGaussSeidelSmoother<tensor> blockGaussSeidelSmootherTensor;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_blockGaussSeidelSmoothers_Header
