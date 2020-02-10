#pragma once
#ifndef _treeLeaf_Header
#define _treeLeaf_Header

#include <labelList.hxx>
#include <treeElem.hxx>
#include <boolList.hxx>
#include <linePointRef.hxx>
#include <HashSet.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	class treeBoundBox;
	class Ostream;

	template<class Type> class octree;
	template<class Type> class treeLeaf;

	// Forward declaration of friend functions and operators

	template<class Type> Istream& operator>>(Istream&, treeLeaf<Type>&);
	template<class Type> Ostream& operator<<(Ostream&, const treeLeaf<Type>&);


	/*---------------------------------------------------------------------------*\
							Class treeLeafName Declaration
	\*---------------------------------------------------------------------------*/

	TemplateName(treeLeaf);


	/*---------------------------------------------------------------------------*\
							   Class treeLeaf Declaration
	\*---------------------------------------------------------------------------*/

	template <class Type>
	class treeLeaf
		:
		public treeElem<Type>,
		public treeLeafName
	{
		// Private data

			// Keeps real size (at construction time indices_ might be untrimmed)
		label size_;

		// Indices of 'things' whose bb overlaps leaf bb.
		labelList indices_;


		// Private Member Functions

		static void space(Ostream&, const label);

		//- Disallow default bitwise copy construct
		treeLeaf(const treeLeaf&);

		//- Disallow default bitwise assignment
		void operator=(const treeLeaf&);


	public:

		// Constructors

			//- Construct with size
		treeLeaf(const treeBoundBox& bb, const label size);

		//- Construct from list
		treeLeaf(const treeBoundBox& bb, const labelList& indices);

		//- Construct from Istream
		treeLeaf(Istream&);


		// Destructor

		~treeLeaf();


		// Member Functions

			// Access

		label size() const
		{
			return size_;
		}

		const labelList& indices() const
		{
			return indices_;
		}

		// Edit

		void insert(const label index)
		{
			if (size_ >= indices_.size())
			{
				FatalErrorIn
				(
					"treeLeaf<Type>::insert(index)"
				)
					<< "overflow"
					<< "  size_ :" << size_
					<< "  size():" << indices_.size()
					<< abort(FatalError);
			}
			indices_[size_++] = index;
		}

		void trim()
		{
			if (size_ == 0)
			{
				FatalErrorIn
				(
					"treeLeaf<Type>::trim()"
				)
					<< "Trying to trim empty leaf: " << endl
					<< "  size_ :" << size_
					<< "  size():" << indices_.size()
					<< abort(FatalError);
			}
			indices_.setSize(size_);
		}

		//- Take indices at refineLevel and distribute them to lower levels
		treeLeaf<Type>* redistribute
		(
			const label,
			octree<Type>&,
			const Type&
		);

		label setSubNodeType
		(
			const label level,
			octree<Type>& top,
			const Type& shapes
		) const;

		// Search

			//- Get type of sample
		label getSampleType
		(
			const label level,
			const octree<Type>& top,
			const Type& shapes,
			const point& sample
		) const;

		//- Find index of shape containing sample
		label find
		(
			const Type& shapes,
			const point& sample
		) const;

		//- Find tightest fitting bounding box in leaf
		bool findTightest
		(
			const Type& shapes,
			const point& sample,
			treeBoundBox& tightest
		) const;

		//- Find nearest point.
		bool findNearest
		(
			const Type& shapes,
			const point& sample,
			treeBoundBox& tightest,
			label& tightestI,
			scalar& tightestDist
		) const;

		//- Find nearest shape to line
		//  Returns true if found nearer shape and updates nearest and
		//  tightest
		bool findNearest
		(
			const Type& shapes,
			const linePointRef& ln,
			treeBoundBox& tightest,
			label& tightestI,   // index of nearest shape
			point& linePoint,   // nearest point on line
			point& shapePoint   // nearest point on shape
		) const;

		//- Find shapes not outside box. Return true if anything found.
		bool findBox
		(
			const Type& shapes,
			const treeBoundBox& bb,
			labelHashSet& elements
		) const;

		// Write

			//- Debug: print a leaf
		void printLeaf(Ostream&, const label) const;

		//- Debug: Write bb in OBJ format
		void writeOBJ
		(
			Ostream& os,
			const label level,
			label& vertNo
		) const;

		//- debug:
		label countLeaf(Ostream&, const label) const;


		// IOstream Operators

		friend Istream& operator>> <Type>(Istream&, treeLeaf<Type>&);
		friend Ostream& operator<< <Type>(Ostream&, const treeLeaf<Type>&);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <treeLeaf.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <octreeDataPointTreeLeaf.hxx>

#endif // !_treeLeaf_Header
