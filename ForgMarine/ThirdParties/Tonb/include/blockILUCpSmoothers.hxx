#pragma once
#ifndef _blockILUCpSmoothers_Header
#define _blockILUCpSmoothers_Header

#include <BlockILUCpSmoother.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef BlockILUCpSmoother<scalar> blockILUCpSmootherScalar;
	typedef BlockILUCpSmoother<vector> blockILUCpSmootherVector;
	typedef BlockILUCpSmoother<tensor> blockILUCpSmootherTensor;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_blockILUCpSmoothers_Header
