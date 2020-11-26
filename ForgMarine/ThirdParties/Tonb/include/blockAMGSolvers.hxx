#pragma once
#ifndef _blockAMGSolvers_Header
#define _blockAMGSolvers_Header

#include <BlockAMGSolver.hxx>
#include <fieldTypes.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef BlockAMGSolver<scalar> blockAmgSolverScalar;
	typedef BlockAMGSolver<vector> blockAmgSolverVector;
	typedef BlockAMGSolver<tensor> blockAmgSolverTensor;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_blockAMGSolvers_Header
