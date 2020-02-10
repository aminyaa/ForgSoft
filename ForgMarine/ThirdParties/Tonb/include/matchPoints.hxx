#pragma once
#ifndef _matchPoints_Header
#define _matchPoints_Header

#include <scalarField.hxx>
#include <pointField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							   Function matchPoints Declaration
	\*---------------------------------------------------------------------------*/

	//- Determine correspondence between pointFields. Gets passed
	//  local matching distance per point. Returns map from 0 to 1. Returns
	//  true if found corresponding point in 1 for every point in 0; false
	//  otherwise. Compares mag(pt - origin) and does proper comparison for points
	//  with (almost) identical mag. pts0 can be subset of pts1.
	bool matchPoints
	(
		const UList<point>& pts0,
		const UList<point>& pts1,
		const UList<scalar>& matchDistance,
		const bool verbose,
		labelList& from0To1,
		const point& origin = point::zero
	);

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_matchPoints_Header
