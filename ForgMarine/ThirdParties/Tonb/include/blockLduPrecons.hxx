#pragma once
#ifndef _blockLduPrecons_Header
#define _blockLduPrecons_Header

#include <BlockLduPrecon.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef BlockLduPrecon<scalar> blockScalarPrecon;
	typedef BlockLduPrecon<vector> blockVectorPrecon;
	typedef BlockLduPrecon<tensor> blockTensorPrecon;


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_blockLduPrecons_Header
