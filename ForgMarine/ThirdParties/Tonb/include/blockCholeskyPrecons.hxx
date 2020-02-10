#pragma once
#ifndef _blockCholeskyPrecons_Header
#define _blockCholeskyPrecons_Header

#include <scalarBlockCholeskyPrecon.hxx>
#include <tensorBlockCholeskyPrecon.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef BlockCholeskyPrecon<scalar> blockCholeskyPreconScalar;
	typedef BlockCholeskyPrecon<vector> blockCholeskyPreconVector;
	typedef BlockCholeskyPrecon<tensor> blockCholeskyPreconTensor;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_blockCholeskyPrecons_Header
