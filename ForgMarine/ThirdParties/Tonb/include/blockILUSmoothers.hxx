#pragma once
#ifndef _blockILUSmoothers_Header
#define _blockILUSmoothers_Header

#include <BlockILUSmoother.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef BlockILUSmoother<scalar> blockILUSmootherScalar;
	typedef BlockILUSmoother<vector> blockILUSmootherVector;
	typedef BlockILUSmoother<tensor> blockILUSmootherTensor;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_blockILUSmoothers_Header
