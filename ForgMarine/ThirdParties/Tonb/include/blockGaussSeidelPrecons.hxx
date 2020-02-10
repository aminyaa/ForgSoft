#pragma once
#ifndef _blockGaussSeidelPrecons_Header
#define _blockGaussSeidelPrecons_Header

#include <scalarBlockGaussSeidelPrecon.hxx>
#include <tensorBlockGaussSeidelPrecon.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef BlockGaussSeidelPrecon<scalar> blockGaussSeidelPreconScalar;
	typedef BlockGaussSeidelPrecon<vector> blockGaussSeidelPreconVector;
	typedef BlockGaussSeidelPrecon<tensor> blockGaussSeidelPreconTensor;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_blockGaussSeidelPrecons_Header
