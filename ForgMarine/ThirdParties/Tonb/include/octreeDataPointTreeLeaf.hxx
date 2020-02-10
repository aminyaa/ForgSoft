#pragma once
#ifndef _octreeDataPointTreeLeaf_Header
#define _octreeDataPointTreeLeaf_Header

#include <treeLeaf.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Forward declaration of classes
	class octreeDataPoint;

	template<>
	label treeLeaf<octreeDataPoint>::find
	(
		const octreeDataPoint& shapes,
		const point& sample
	) const;


	template<>
	bool treeLeaf<octreeDataPoint>::findNearest
	(
		const octreeDataPoint& shapes,
		const point& sample,
		treeBoundBox& tightest,
		label& tightestI,
		scalar& tightestDist
	) const;


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_octreeDataPointTreeLeaf_Header
