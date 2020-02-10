#pragma once
#ifndef _tensorBlockDiagonalPrecon_Header
#define _tensorBlockDiagonalPrecon_Header

#include <BlockDiagonalPrecon.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	template<>
	void tnbLib::BlockDiagonalPrecon<tensor>::precondition
	(
		tensorField& x,
		const tensorField& b
	) const;


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_tensorBlockDiagonalPrecon_Header
