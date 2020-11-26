#pragma once
#ifndef _blockAMGPrecons_Header
#define _blockAMGPrecons_Header

// KRJ: No specializations implemented
#include <tensorBlockAMGPrecon.hxx>

#include <BlockAMGPrecon.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef BlockAMGPrecon<scalar> blockAMGPreconScalar;
	typedef BlockAMGPrecon<vector> blockAMGPreconVector;
	typedef BlockAMGPrecon<tensor> blockAMGPreconTensor;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_blockAMGPrecons_Header
