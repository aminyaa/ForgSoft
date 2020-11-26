#pragma once
#ifndef _blockDiagonalSolvers_Header
#define _blockDiagonalSolvers_Header

#include <BlockDiagonalSolver.hxx>
#include <fieldTypes.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef BlockDiagonalSolver<scalar> blockDiagonalSolverScalar;
	typedef BlockDiagonalSolver<vector> blockDiagonalSolverVector;
	typedef BlockDiagonalSolver<tensor> blockDiagonalSolverTensor;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_blockDiagonalSolvers_Header
