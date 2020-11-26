#pragma once
#ifndef _symmTensorExtendedBlockLduMatrix_Header
#define _symmTensorExtendedBlockLduMatrix_Header

#include <extendedBlockLduMatrix.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	template<>
	void extendedBlockLduMatrix<symmTensor>::mapOffDiagCoeffs
	(
		const BlockLduMatrix<symmTensor>& blockLdum
	);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_symmTensorExtendedBlockLduMatrix_Header
