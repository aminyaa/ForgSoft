#pragma once
#ifndef _blockGMRESSolvers_Header
#define _blockGMRESSolvers_Header

#include <BlockGMRESSolver.hxx>
#include <fieldTypes.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef BlockGMRESSolver<scalar> blockGMRESsolverScalar;
	typedef BlockGMRESSolver<vector> blockGMRESsolverVector;
	typedef BlockGMRESSolver<tensor> blockGMRESsolverTensor;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_blockGMRESSolvers_Header
