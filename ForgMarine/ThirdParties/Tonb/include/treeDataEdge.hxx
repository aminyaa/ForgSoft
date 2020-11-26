#pragma once
#ifndef _treeDataEdge_Header
#define _treeDataEdge_Header

#include <treeBoundBoxList.hxx>
#include <linePointRef.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Forward declaration of classes
	template<class Type> class indexedOctree;

	/*---------------------------------------------------------------------------*\
							   Class treeDataEdge Declaration
	\*---------------------------------------------------------------------------*/

	class treeDataEdge
	{
		// Static data

			//- tolerance on linear dimensions
		static scalar tol;


		// Private data

			//- Reference to edgeList
		const edgeList& edges_;

		//- Reference to points
		const pointField& points_;

		//- labels of edges
		const labelList edgeLabels_;

		//- Whether to precalculate and store face bounding box
		const bool cacheBb_;

		//- bbs for all above edges (valid only if cacheBb_)
		treeBoundBoxList bbs_;


		// Private Member Functions

			//- Calculate edge bounding box
		treeBoundBox calcBb(const label edgeI) const;

	public:

		// Declare name of the class and its debug switch
		ClassName("treeDataEdge");


		// Constructors

			//- Construct from selected edges. !Holds references to edges and points
		treeDataEdge
		(
			const bool cacheBb,
			const edgeList& edges,
			const pointField& points,
			const labelList& edgeLabels
		);


		// Member Functions

			// Access

		label size() const
		{
			return edgeLabels_.size();
		}

		//- Get representative point cloud for all shapes inside
		//  (one point per shape)
		pointField points() const;


		// Search

			//- Get type (inside,outside,mixed,unknown) of point w.r.t. surface.
			//  Only makes sense for closed surfaces.
		label getVolumeType
		(
			const indexedOctree<treeDataEdge>&,
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
				"treeDataEdge::intersects(const label, const point&,"
				"const point&, point&)"
			);
			return false;
		}

	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_treeDataEdge_Header
