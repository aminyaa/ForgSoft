#pragma once
#ifndef _tensorBlockAMGPrecon_Header
#define _tensorBlockAMGPrecon_Header

#include <BlockAMGPrecon.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	template<>
	void tnbLib::BlockAMGPrecon<tensor>::precondition
	(
		tensorField& x,
		const tensorField& b
	) const;


	// template<>
	// void tnbLib::BlockAMGPrecon<tensor>::preconditionT
	// (
	//     tensorField& xT,
	//     const tensorField& bT
	// ) const;


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_tensorBlockAMGPrecon_Header
