#pragma once
#ifndef _tensorBlockCholeskyPrecon_Header
#define _tensorBlockCholeskyPrecon_Header

#include <BlockCholeskyPrecon.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	template<>
	void tnbLib::BlockCholeskyPrecon<tensor>::calcPreconDiag();

	template<>
	void tnbLib::BlockCholeskyPrecon<tensor>::precondition
	(
		tensorField& x,
		const tensorField& b
	) const;


	template<>
	void tnbLib::BlockCholeskyPrecon<tensor>::preconditionT
	(
		tensorField& xT,
		const tensorField& bT
	) const;


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_tensorBlockCholeskyPrecon_Header
