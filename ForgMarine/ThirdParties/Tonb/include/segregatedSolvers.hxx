#pragma once
#ifndef _segregatedSolvers_Header
#define _segregatedSolvers_Header

#include <SegregatedSolver.hxx>
#include <fieldTypes.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef SegregatedSolver<scalar> segregatedSolverScalar;
	typedef SegregatedSolver<vector> segregatedSolverVector;
	typedef SegregatedSolver<tensor> segregatedSolverTensor;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_segregatedSolvers_Header
