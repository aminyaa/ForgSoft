#pragma once
#ifndef _octree_Header
#define _octree_Header

#include <treeBoundBoxList.hxx>
#include <treeLeaf.hxx>
#include <pointIndexHit.hxx>
#include <linePointRef.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Forward declaration of classes
	template<class Type> class treeNode;

	// Forward declaration of friend functions and operators

	template<class Type>
	Ostream& operator<<(Ostream&, const octree<Type>&);


	/*---------------------------------------------------------------------------*\
							Class octreeName Declaration
	\*---------------------------------------------------------------------------*/

	TemplateName(octree);



	/*---------------------------------------------------------------------------*\
							   Class octree Declaration
	\*---------------------------------------------------------------------------*/

	template <class Type>
	class octree
		: public octreeName
	{
		// Private data

			//- Top treeNode. Modified by lower levels.
		treeNode<Type>* topNode_;

		//- All shapes
		const Type shapes_;

		//- Overall bb of octree
		const treeBoundBox octreeBb_;

		//- Refinement crit: size of leaves. Average number of entries per
		//  leaf.  Should be fine enough for efficient searching
		//  at lowest level.
		const scalar maxLeafRatio_;

		//- Refinement crit: multiplicity of entries (so in how many leaves
		//  each shape is mentioned)
		const scalar maxShapeRatio_;

		//- Refinement crit: min no. of levels
		const label minNLevels_;

		//- Actual depth
		label deepestLevel_;

		//- Total number of (references to) shapes in octree
		//  (shapes can be stored in more than one treeLeaf)
		label nEntries_;

		//- Total number of treeNodes
		label nNodes_;

		//- Total number of treeLeaves
		label nLeaves_;


		// Static data members

			//- Refinement criterion max number of level
		static const label maxNLevels = 20;



		// Private Member Functions

	public:

		// Data types

			//- volume types
		enum volumeType
		{
			UNKNOWN,
			MIXED,
			INSIDE,
			OUTSIDE
		};


		// Static data members

			//- for debugging:return printable representation of volumeType
		static string volType(const label);

		//- Code the vector with respect to the geometry. geomNormal guaranteed
		//  to point outside.
		static label getVolType
		(
			const vector& geomNormal,
			const vector& vec
		);

		// Constructors

			//- Construct from components
		octree
		(
			const treeBoundBox& octreeBb,
			const Type& shapes,
			const label minNLevels,     // minimum number of levels
			const scalar maxLeafRatio,  // max avg. size of leaves
			const scalar maxShapeRatio  // max avg. duplicity.
		);


		// Destructor

		~octree();


		// Member Functions

			// Access

		const Type& shapes() const
		{
			return shapes_;
		}

		const treeBoundBox& octreeBb() const
		{
			return octreeBb_;
		}

		scalar maxShapeRatio() const
		{
			return maxShapeRatio_;
		}

		scalar maxLeafRatio() const
		{
			return maxLeafRatio_;
		}

		label minNLevels() const
		{
			return minNLevels_;
		}

		// After construction: octree statistics

		treeNode<Type>* topNode() const
		{
			return topNode_;
		}

		label deepestLevel() const
		{
			return deepestLevel_;
		}

		label nEntries() const
		{
			return nEntries_;
		}

		label nNodes() const
		{
			return nNodes_;
		}

		label nLeaves() const
		{
			return nLeaves_;
		}

		void setEntries(const label n)
		{
			nEntries_ = n;
		}

		void setNodes(const label n)
		{
			nNodes_ = n;
		}

		void setLeaves(const label n)
		{
			nLeaves_ = n;
		}

		// Queries

			//- Returns type of sample with respect to nearest shape.
			//  Meaning of type is determined by shapes.getSampleType().
			//  Normally based on outwards pointing normal. For e.g.
			//  octreeDataFace returns one of
			//      inside  : on other side of normal on nearest face
			//      outside : on same side as normal on nearest face
			//      unknown : not above nearest face; surface probably not
			//                closed.
			//      mixed   : should never happen
		label getSampleType(const point& sample) const;

		//- Find shape containing point in tree
		//  Returns -1 if not in found. Uses Type::contains.
		label find(const point& sample) const;

		//- Calculate tightest fitting bounding box. Uses
		//  Type::findTightest.
		bool findTightest
		(
			const point& sample,
			treeBoundBox& tightest
		) const;

		//- Find nearest shape. Returns index of shape or -1 if not found.
		//  tightestDist is both input and output. Uses Type::calcNearest.
		label findNearest
		(
			const point& sample,
			treeBoundBox& tightest,
			scalar& tightestDist
		) const;

		//- Find nearest to line. Returns -1 or index of shape and
		//  sets:
		//  - tightest (is both input and output).
		//  - linePoint: point on line (-GREAT,-GREAT,-GREAT if not found)
		//  - shapePoint: point on shape (GREAT, GREAT, GREAT if not found)
		//  Uses Type::calcNearest.
		label findNearest
		(
			const linePointRef& ln,
			treeBoundBox& tightest,
			point& linePoint,
			point& shapePoint
		) const;

		//- Find (in no particular order) indices of all shapes inside or
		//  overlapping bounding box (i.e. all shapes not outside box)
		labelList findBox(const treeBoundBox& bb) const;

		//- Find intersected shape along line. pointIndexHit contains index
		//  of nearest shape intersected and the intersection point. Uses
		//  findLeafLine.
		pointIndexHit findLine(const point& start, const point& end) const;

		//- Like above but just tests whether line hits anything. So
		//   returns first intersection found, not nessecarily nearest.
		pointIndexHit findLineAny(const point& start, const point& end)
			const;

		//- Find leaf along line. Set leafIntPoint to leave point of
		//  treeLeaf.
		const treeLeaf<Type>* findLeafLine
		(
			const point& start,
			const point& end,
			point& leafIntPoint
		) const;


		// Write

			//- Dump graphical representation in .obj format
		void writeOBJ(Ostream& os, label& vertNo) const;

		//- Print some stats on octree
		void printStats(Ostream& os) const;


		// STL iterator

		class iterator;
		friend class iterator;

		//- An STL iterator for octree
		class iterator
		{
			// Private data

				//- Reference to the octree this is an iterator for
			octree& octree_;

			//- List of pointers to treeLeaves
			List<treeLeaf<Type>*> leaves_;

			//- Current treeLeaf index
			label curLeaf_;

		public:

			//- Construct for a given octree
			iterator(octree&);

			//- Contruct for a given octree, at a certain position
			iterator(octree& oc, const label index);


			// Member operators

			void operator=(const iterator&);

			bool operator==(const iterator&) const;
			bool operator!=(const iterator&) const;

			treeLeaf<Type>& operator*();

			iterator& operator++();
			iterator operator++(int);
		};

		//- iterator set to the begining of the octree
		iterator begin();

		//- iterator set to beyond the end of the octree
		const iterator& end();


		// STL const_iterator

		class const_iterator;
		friend class const_iterator;

		//- An STL const_iterator for octree
		class const_iterator
		{
			// Private data

				//- Reference to the list this is an iterator for
			const octree& octree_;

			//- List of treeLeafs
			List<const treeLeaf<Type>*> leaves_;

			//- Current treeLeaf index
			label curLeaf_;

		public:

			//- Construct for a given octree
			const_iterator(const octree&);

			//- Construct for a given octree and index
			const_iterator(const octree&, label);

			// Member operators

			void operator=(const const_iterator&);

			bool operator==(const const_iterator&) const;
			bool operator!=(const const_iterator&) const;

			const treeLeaf<Type>& operator*();

			const_iterator& operator++();
			const_iterator operator++(int);
		};


		//- const_iterator set to the begining of the octree
		inline const_iterator begin() const;
		inline const_iterator cbegin() const;

		//- const_iterator set to beyond the end of the octree
		inline const const_iterator& end() const;
		inline const const_iterator& cend() const;


		// IOstream Operators

		friend Ostream& operator<< <Type>(Ostream&, const octree<Type>&);


	private:

		//- iterator returned by end()
		iterator endIter_;

		//- const_iterator returned by end()
		const_iterator endConstIter_;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <octree.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_octree_Header
