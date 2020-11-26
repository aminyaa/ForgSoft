#pragma once
#ifndef _scalarConstraint_Header
#define _scalarConstraint_Header

#include <scalar.hxx>
#include <constraint.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

	template<>
	scalar constraint<scalar>::componentOfValue
	(
		const scalar& v,
		const direction
	) const;

	template<>
	void constraint<scalar>::combine
	(
		const constraint<scalar>& e
	);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_scalarConstraint_Header
