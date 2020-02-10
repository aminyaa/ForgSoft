#pragma once
#ifndef _blockCGSolvers_Header
#define _blockCGSolvers_Header

#include <BlockCGSolver.hxx>
#include <fieldTypes.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef BlockCGSolver<scalar> blockCGSolverScalar;
	typedef BlockCGSolver<vector> blockCGSolverVector;
	typedef BlockCGSolver<tensor> blockCGSolverTensor;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_blockCGSolvers_Header
