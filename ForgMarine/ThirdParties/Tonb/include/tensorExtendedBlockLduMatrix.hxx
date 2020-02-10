#pragma once
#ifndef _tensorExtendedBlockLduMatrix_Header
#define _tensorExtendedBlockLduMatrix_Header

#include <extendedBlockLduMatrix.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	template<>
	void extendedBlockLduMatrix<tensor>::mapOffDiagCoeffs
	(
		const BlockLduMatrix<tensor>& blockLdum
	);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_tensorExtendedBlockLduMatrix_Header
