#pragma once
#ifndef _blockILUCpPrecons_Header
#define _blockILUCpPrecons_Header

#include <scalarBlockILUCpPrecon.hxx>
#include <tensorBlockILUCpPrecon.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef BlockILUCpPrecon<scalar> blockILUCpPreconScalar;
	typedef BlockILUCpPrecon<vector> blockILUCpPreconVector;
	typedef BlockILUCpPrecon<tensor> blockILUCpPreconTensor;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_blockILUCpPrecons_Header
