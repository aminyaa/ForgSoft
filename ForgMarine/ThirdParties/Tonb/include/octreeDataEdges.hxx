#pragma once
#ifndef _octreeDataEdges_Header
#define _octreeDataEdges_Header

#include <line.hxx>
#include <linePointRef.hxx>
#include <treeBoundBoxList.hxx>
#include <labelList.hxx>
#include <className.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Forward declaration of classes
	template<class Type> class octree;

	/*---------------------------------------------------------------------------*\
						   Class octreeDataEdges Declaration
	\*---------------------------------------------------------------------------*/

	class octreeDataEdges
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
		labelList edgeLabels_;

		//- bbs for all above edges
		treeBoundBoxList allBb_;


	public:

		// Declare name of the class and its debug switch
		ClassName("octreeDataEdges");

		// Constructors

			//- Construct from selected edges. !Holds references to edges and points
		octreeDataEdges
		(
			const edgeList& edges,
			const pointField& points,
			const labelList& edgeLabels
		);

		//- Construct as copy
		octreeDataEdges(const octreeDataEdges&);


		// Destructor

		~octreeDataEdges();


		// Member Functions

			// Access

		const edgeList& edges() const
		{
			return edges_;
		}

		const pointField& points() const
		{
			return points_;
		}

		const labelList& edgeLabels() const
		{
			return edgeLabels_;
		}

		const treeBoundBoxList& allBb() const
		{
			return allBb_;
		}

		label size() const
		{
			return allBb_.size();
		}


		// Search

			//- Get type of sample
		label getSampleType
		(
			const octree<octreeDataEdges>&,
			const point&
		) const;

		//- Does (bb of) shape at index overlap bb
		bool overlaps
		(
			const label index,
			const treeBoundBox& sampleBb
		) const;

		//- Does shape at index contain sample
		bool contains
		(
			const label index,
			const point& sample
		) const;

		//- Segment (from start to end) intersection with shape at index.
		//  If intersects returns true and sets intersectionPoint
		bool intersects
		(
			const label index,
			const point& start,
			const point& end,
			point& intersectionPoint
		) const;

		//- Sets newTightest to bounding box (and returns true) if
		//  nearer to sample than tightest bounding box. Otherwise
		//  returns false.
		bool findTightest
		(
			const label index,
			const point& sample,
			treeBoundBox& tightest
		) const;

		//- Given index get unit normal and calculate (numerical) sign
		//  of sample.
		//  Used to determine accuracy of calcNearest or inside/outside.
		scalar calcSign
		(
			const label index,
			const point& sample,
			vector& n
		) const;

		//- Calculates nearest (to sample) point in shape.
		//  Returns point and mag(nearest - sample).
		scalar calcNearest
		(
			const label index,
			const point& sample,
			point& nearest
		) const;

		//- Calculates nearest (to line segment) point in shape.
		//  Returns distance and both point.
		scalar calcNearest
		(
			const label index,
			const linePointRef& ln,
			point& linePt,          // nearest point on line
			point& shapePt          // nearest point on shape
		) const;


		// Write

			//- Write shape at index
		void write(Ostream& os, const label index) const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_octreeDataEdges_Header
