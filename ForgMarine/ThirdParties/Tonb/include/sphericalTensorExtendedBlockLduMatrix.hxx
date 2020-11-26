#pragma once
#ifndef _sphericalTensorExtendedBlockLduMatrix_Header
#define _sphericalTensorExtendedBlockLduMatrix_Header

#include <extendedBlockLduMatrix.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	template<>
	void extendedBlockLduMatrix<sphericalTensor>::mapOffDiagCoeffs
	(
		const BlockLduMatrix<sphericalTensor>& blockLdum
	);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_sphericalTensorExtendedBlockLduMatrix_Header