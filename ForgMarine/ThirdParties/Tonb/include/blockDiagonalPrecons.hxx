#pragma once
#ifndef _blockDiagonalPrecons_Header
#define _blockDiagonalPrecons_Header

#include <scalarBlockDiagonalPrecon.hxx>
#include <tensorBlockDiagonalPrecon.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef BlockDiagonalPrecon<scalar> blockDiagonalPreconScalar;
	typedef BlockDiagonalPrecon<vector> blockDiagonalPreconVector;
	typedef BlockDiagonalPrecon<tensor> blockDiagonalPreconTensor;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_blockDiagonalPrecons_Header
