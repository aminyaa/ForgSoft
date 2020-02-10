#pragma once
#ifndef _octreeLine_Header
#define _octreeLine_Header

#include <boolList.hxx>
#include <point.hxx>
#include <pointHitSort.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Forward declaration of classes
	template<class Type> class octree;
	template<class Type> class treeLeaf;


	/*---------------------------------------------------------------------------*\
							   Class octreeLine Declaration
	\*---------------------------------------------------------------------------*/

	template <class Type>
	class octreeLine
	{
		// Private data

			//- Octree reference
		const octree<Type>& tree_;

		//- Start of segment
		const point startPoint_;

		//- End of segment
		const point endPoint_;

		//- Start moved into bb
		point realStartPoint_;

		//- Exit point of intersection with current treeLeaf
		point leafExitPoint_;

		//- Current treeLeaf to be searched in.
		const treeLeaf<Type>* currentLeaf_;

		//- Sorted list of intersections
		List<pointHitSort> sortedIntersections_;

		//- index of last hit in previous treeLeaf. Used so if shape double
		//  it does not get counted twice. Note is not ok for concave shapes
		label lastElem_;

		//- Current hit: index in sortedIntersections_
		label sortedI_;

		// Private Member Functions

			//- Calculate sorted list of intersections
		void calcSortedIntersections();

		//- Searches for leaf with intersected elements.
		//  Return true if found; false otherwise.
		//  Sets currentLeaf_ and sortedIntersections_
		bool getNextLeaf();

	public:

		// Constructors

			//- Construct from components
		octreeLine
		(
			const octree<Type>& tree,
			const point& startPoint,
			const point& endPoint
		);


		// Destructor

		~octreeLine();


		// Member Functions

		const octree<Type>& tree() const
		{
			return tree_;
		}

		const point& leafExitPoint() const
		{
			return leafExitPoint_;
		}

		const point& endPoint() const
		{
			return endPoint_;
		}

		const point& startPoint() const
		{
			return startPoint_;
		}

		const treeLeaf<Type>* currentLeaf() const
		{
			return currentLeaf_;
		}

		const List<pointHitSort>& sortedIntersections() const
		{
			return sortedIntersections_;
		}

		label hitIndex() const
		{
			return sortedIntersections_[sortedI_].index();
		}

		const pointHit& hitInfo() const
		{
			return sortedIntersections_[sortedI_].inter();
		}


		//- go to next intersection. Return false if no intersections.
		bool getIntersection();

	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <octreeLine.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_octreeLine_Header
