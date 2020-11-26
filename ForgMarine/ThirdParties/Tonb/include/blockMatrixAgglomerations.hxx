#pragma once
#ifndef _blockMatrixAgglomerations_Header
#define _blockMatrixAgglomerations_Header

#include <scalarBlockMatrixAgglomeration.hxx>
#include <tensorBlockMatrixAgglomeration.hxx>
#include <BlockMatrixAgglomeration.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef BlockMatrixAgglomeration<scalar> blockMatrixAgglomerationScalar;
	typedef BlockMatrixAgglomeration<vector> blockMatrixAgglomerationVector;
	typedef BlockMatrixAgglomeration<tensor> blockMatrixAgglomerationTensor;


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_blockMatrixAgglomerations_Header
