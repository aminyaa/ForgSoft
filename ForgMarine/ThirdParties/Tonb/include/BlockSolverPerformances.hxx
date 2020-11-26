#pragma once
#ifndef _BlockSolverPerformances_Header
#define _BlockSolverPerformances_Header

#include <BlockSolverPerformance.hxx>
#include <fieldTypes.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef BlockSolverPerformance<scalar> BlockSolverPerformanceScalar;
	typedef BlockSolverPerformance<vector> BlockSolverPerformanceVector;
	typedef BlockSolverPerformance<sphericalTensor>
		BlockSolverPerformanceSphericalTensor;
	typedef BlockSolverPerformance<symmTensor> BlockSolverPerformanceSymmTensor;
	typedef BlockSolverPerformance<tensor> BlockSolverPerformanceTensor;


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_BlockSolverPerformances_Header
