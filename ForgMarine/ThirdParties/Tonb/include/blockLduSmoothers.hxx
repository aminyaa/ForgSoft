#pragma once
#ifndef _blockLduSmoothers_Header
#define _blockLduSmoothers_Header

#include <BlockLduSmoother.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef BlockLduSmoother<scalar> blockScalarSmoother;
	typedef BlockLduSmoother<vector> blockVectorSmoother;
	typedef BlockLduSmoother<tensor> blockTensorSmoother;


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_blockLduSmoothers_Header
