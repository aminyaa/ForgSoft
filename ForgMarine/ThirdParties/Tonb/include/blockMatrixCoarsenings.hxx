#pragma once
#ifndef _blockMatrixCoarsenings_Header
#define _blockMatrixCoarsenings_Header

#include <BlockMatrixCoarsening.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef BlockMatrixCoarsening<scalar> blockScalarMatrixCoarsening;
	typedef BlockMatrixCoarsening<vector> blockVectorMatrixCoarsening;
	typedef BlockMatrixCoarsening<tensor> blockTensorMatrixCoarsening;


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_blockMatrixCoarsenings_Header
