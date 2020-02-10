#pragma once
#ifndef _blockLduSolvers_Header
#define _blockLduSolvers_Header

#include <BlockLduSolver.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef BlockLduSolver<scalar> blockScalarSolver;
	typedef BlockLduSolver<vector> blockVectorSolver;
	typedef BlockLduSolver<tensor> blockTensorSolver;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_blockLduSolvers_Header
