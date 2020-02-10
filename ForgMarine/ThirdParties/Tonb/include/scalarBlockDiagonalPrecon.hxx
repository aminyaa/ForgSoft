#pragma once
#ifndef _scalarBlockDiagonalPrecon_Header
#define _scalarBlockDiagonalPrecon_Header

#include <BlockDiagonalPrecon.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	template<>
	void tnbLib::BlockDiagonalPrecon<scalar>::precondition
	(
		scalarField& x,
		const scalarField& b
	) const;


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_scalarBlockDiagonalPrecon_Header
