#pragma once
#ifndef _tensorBlockILUCpPrecon_Header
#define _tensorBlockILUCpPrecon_Header

#include <BlockILUCpPrecon.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Calculate active type factorization
	template<>
	template<>
	void BlockILUCpPrecon<tensor>::calcActiveTypeFactorization
	(
		tensorField& preconD,
		tensorField& extUpper,
		tensorField& extLower
	) const;


	// Calculate factorization (constructor helper)
	template<>
	void BlockILUCpPrecon<tensor>::calcFactorization() const;


	// Precondition
	template<>
	void BlockILUCpPrecon<tensor>::precondition
	(
		tensorField& x,
		const tensorField& b
	) const;


	// Precondition transpose
	template<>
	void BlockILUCpPrecon<tensor>::preconditionT
	(
		tensorField& xT,
		const tensorField& bT
	) const;


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_tensorBlockILUCpPrecon_Header
