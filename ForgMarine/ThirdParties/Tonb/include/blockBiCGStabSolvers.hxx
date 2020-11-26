#pragma once
#ifndef _blockBiCGStabSolvers_Header
#define _blockBiCGStabSolvers_Header

#include <BlockBiCGStabSolver.hxx>
#include <fieldTypes.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef BlockBiCGStabSolver<scalar> blockBiCGStabSolverScalar;
	typedef BlockBiCGStabSolver<vector> blockBiCGStabSolverVector;
	typedef BlockBiCGStabSolver<tensor> blockBiCGStabSolverTensor;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_blockBiCGStabSolvers_Header
