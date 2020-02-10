#pragma once
#ifndef _treeDataPoint_Header
#define _treeDataPoint_Header

#include <pointField.hxx>
#include <treeBoundBox.hxx>
#include <linePointRef.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Forward declaration of classes
	template<class Type> class indexedOctree;

	/*---------------------------------------------------------------------------*\
							   Class treeDataPoint Declaration
	\*---------------------------------------------------------------------------*/

	class treeDataPoint
	{
		// Private data

		const pointField& points_;

	public:

		// Declare name of the class and its debug switch
		ClassName("treeDataPoint");


		// Constructors

			//- Construct from components. Holds reference to points!
		treeDataPoint(const pointField& points);


		// Member Functions

			// Access

		label size() const
		{
			return points_.size();
		}

		//- Get representative point cloud for all shapes inside
		//  (one point per shape)
		pointField points() const;


		// Search

			//- Get type (inside,outside,mixed,unknown) of point w.r.t. surface.
			//  Only makes sense for closed surfaces.
		label getVolumeType
		(
			const indexedOctree<treeDataPoint>&,
			const point&
		) const;

		//- Does (bb of) shape at index overlap bb
		bool overlaps
		(
			const label index,
			const treeBoundBox& sampleBb
		) const;

		//- Calculates nearest (to sample) point in shape.
		//  Returns actual point and distance (squared)
		void findNearest
		(
			const labelList& indices,
			const point& sample,

			scalar& nearestDistSqr,
			label& nearestIndex,
			point& nearestPoint
		) const;

		//- Calculates nearest (to line) point in shape.
		//  Returns point and distance (squared)
		void findNearest
		(
			const labelList& indices,
			const linePointRef& ln,

			treeBoundBox& tightest,
			label& minIndex,
			point& linePoint,
			point& nearestPoint
		) const;

		//- Calculate intersection of shape with ray. Sets result
		//  accordingly
		bool intersects
		(
			const label index,
			const point& start,
			const point& end,
			point& result
		) const
		{
			notImplemented
			(
				"treeDataPoint::intersects(const label, const point&,"
				"const point&, point&)"
			);
			return false;
		}

	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_treeDataPoint_Header
