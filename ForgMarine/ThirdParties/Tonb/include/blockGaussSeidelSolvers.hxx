#pragma once
#ifndef _blockGaussSeidelSolvers_Header
#define _blockGaussSeidelSolvers_Header

#include <BlockGaussSeidelSolver.hxx>
#include <fieldTypes.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef BlockGaussSeidelSolver<scalar> blockGaussSeidelSolverScalar;
	typedef BlockGaussSeidelSolver<vector> blockGaussSeidelSolverVector;
	typedef BlockGaussSeidelSolver<tensor> blockGaussSeidelSolverTensor;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_blockGaussSeidelSolvers_header
