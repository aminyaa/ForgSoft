#pragma once
#ifndef _tensorBlockGaussSeidelPrecon_Header
#define _tensorBlockGaussSeidelPrecon_Header

#include <BlockGaussSeidelPrecon.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	template<>
	void BlockGaussSeidelPrecon<tensor>::calcInvDiag();


	template<>
	void BlockGaussSeidelPrecon<tensor>::precondition
	(
		tensorField& x,
		const tensorField& b
	) const;


	template<>
	void BlockGaussSeidelPrecon<tensor>::preconditionT
	(
		tensorField& xT,
		const tensorField& bT
	) const;
}


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_tensorBlockGaussSeidelPrecon_Header