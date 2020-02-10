#pragma once
#ifndef _scalarBlockGaussSeidelPrecon_Header
#define _scalarBlockGaussSeidelPrecon_Header

#include <BlockGaussSeidelPrecon.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	template<>
	void BlockGaussSeidelPrecon<scalar>::calcInvDiag();


	template<>
	void BlockGaussSeidelPrecon<scalar>::precondition
	(
		Field<scalar>& x,
		const Field<scalar>& b
	) const;


	template<>
	void BlockGaussSeidelPrecon<scalar>::preconditionT
	(
		scalarField& xT,
		const scalarField& bT
	) const;


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_scalarBlockGaussSeidelPrecon_Header
