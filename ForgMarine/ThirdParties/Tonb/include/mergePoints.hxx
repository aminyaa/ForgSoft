#pragma once
#ifndef _mergePoints_Header
#define _mergePoints_Header

#include <scalarField.hxx>
#include <pointField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							   Function mergePoints Declaration
	\*---------------------------------------------------------------------------*/

	//- Sort & merge points. All points closer than/equal mergeTol get merged.
	//  Outputs the new unique points and a map from old to new. Returns
	//  true if anything merged, false otherwise.
	bool mergePoints
	(
		const UList<point>& points,
		const scalar mergeTol,
		const bool verbose,
		labelList& pointMap,
		List<point>& newPoints,
		const point& origin = point::zero
	);

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_mergePoints_Header
