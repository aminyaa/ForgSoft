#pragma once
#ifndef _Geo_PrTree_Header
#define _Geo_PrTree_Header

#include <Entity2d_Box.hxx>
#include <Entity3d_Box.hxx>
#include <Geo_Traits.hxx>
#include <Geo_SearchTree.hxx>
#include <error.hxx>
#include <OSstream.hxx>

#include <list>
#include <vector>

namespace tnbLib
{

	enum Geo_Quadrant
	{
		Geo_Quadrant_SW,
		Geo_Quadrant_SE,
		Geo_Quadrant_NW,
		Geo_Quadrant_NE
	};

	enum Geo_Octant
	{
		Geo_Octant_Fwd_SW,
		Geo_Octant_Fwd_SE,
		Geo_Octant_Fwd_NW,
		Geo_Octant_Fwd_NE,
		Geo_Octant_Bwd_SW,
		Geo_Octant_Bwd_SE,
		Geo_Octant_Bwd_NW,
		Geo_Octant_Bwd_NE
	};

	inline Geo_Quadrant CalcQuadrant
	(
		const Pnt2d& theCoord,
		const Pnt2d& theCentre
	);

	inline Geo_Octant CalcOctant
	(
		const Pnt3d& theCoord,
		const Pnt3d& theCentre
	);

	template<class T>
	class Geo_PrTreeBucket
		: public std::list<T>
	{

		/*Private Data*/

	public:

		Geo_PrTreeBucket()
		{}
	};

	// Forward Declarations
	template<class T, int Dim, bool Balanced> class Geo_PrTreeLeaf;
	template<class T, int Dim> class Geo_PrTreeInternalHub;
	template<class Point> class Geo_PrTreeNode;

	template<class T, int Dim, bool Balanced = false>
	class Geo_PrTreeLeafHub
	{};

	template<class T>
	class Geo_PrTreeLeafHub<T, 3, true>
	{

		/*Private Data*/

		typedef std::list<Geo_PrTreeLeaf<T, 3, true>*> leafList;

		leafList theSNeighbors_;
		leafList theENeighbors_;
		leafList theNNeighbors_;
		leafList theWNeighbors_;
		leafList theFNeighbors_;
		leafList theBNeighbors_;

	public:

		Geo_PrTreeLeafHub()
		{}

		const leafList& SNeighbors() const
		{
			return theSNeighbors_;
		}

		leafList& SNeighbors()
		{
			return theSNeighbors_;
		}

		const leafList& ENeighbors() const
		{
			return theENeighbors_;
		}

		leafList& ENeighbors()
		{
			return theENeighbors_;
		}

		const leafList& NNeighbors() const
		{
			return theNNeighbors_;
		}

		leafList& NNeighbors()
		{
			return theNNeighbors_;
		}

		const leafList& WNeighbors() const
		{
			return theWNeighbors_;
		}

		leafList& WNeighbors()
		{
			return theWNeighbors_;
		}

		const leafList& FNeighbors() const
		{
			return theFNeighbors_;
		}

		leafList& FNeighbors()
		{
			return theFNeighbors_;
		}

		const leafList& BNeighbors() const
		{
			return theBNeighbors_;
		}

		leafList& BNeighbors()
		{
			return theBNeighbors_;
		}
	};

	template<class T>
	class Geo_PrTreeLeafHub<T, 2, true>
	{

		/*Private Data*/

		typedef std::list<Geo_PrTreeLeaf<T, 2, true>*> leafList;

		leafList theSNeighbors_;
		leafList theENeighbors_;
		leafList theNNeighbors_;
		leafList theWNeighbors_;

	public:

		Geo_PrTreeLeafHub()
		{}

		const leafList& SNeighbors() const
		{
			return theSNeighbors_;
		}

		leafList& SNeighbors()
		{
			return theSNeighbors_;
		}

		const leafList& ENeighbors() const
		{
			return theENeighbors_;
		}

		leafList& ENeighbors()
		{
			return theENeighbors_;
		}

		const leafList& NNeighbors() const
		{
			return theNNeighbors_;
		}

		leafList& NNeighbors()
		{
			return theNNeighbors_;
		}

		const leafList& WNeighbors() const
		{
			return theWNeighbors_;
		}

		leafList& WNeighbors()
		{
			return theWNeighbors_;
		}

	};

	template<class Point, int Dim>
	class Geo_PrTreeInternalHub {};

	template<class Point>
	class Geo_PrTreeInternalHub<Point, 3>
	{

		/*Private Data*/
		typedef Geo_PrTreeNode<Point> node;

		node* theFwdSwPtr_;
		node* theFwdSePtr_;
		node* theFwdNePtr_;
		node* theFwdNwPtr_;

		node* theBwdSwPtr_;
		node* theBwdSePtr_;
		node* theBwdNePtr_;
		node* theBwdNwPtr_;

	public:

		Geo_PrTreeInternalHub()
			: theFwdSwPtr_(0)
			, theFwdSePtr_(0)
			, theFwdNePtr_(0)
			, theFwdNwPtr_(0)
			, theBwdSwPtr_(0)
			, theBwdSePtr_(0)
			, theBwdNePtr_(0)
			, theBwdNwPtr_(0)
		{}

		node* FwdSw() const
		{
			return theFwdSwPtr_;
		}

		node*& FwdSw()
		{
			return theFwdSwPtr_;
		}

		node* FwdSe() const
		{
			return theFwdSePtr_;
		}

		node*& FwdSe()
		{
			return theFwdSePtr_;
		}

		node* FwdNe() const
		{
			return theFwdNePtr_;
		}

		node*& FwdNe()
		{
			return theFwdNePtr_;
		}

		node* FwdNw() const
		{
			return theFwdNwPtr_;
		}

		node*& FwdNw()
		{
			return theFwdNwPtr_;
		}

		node* BwdSw() const
		{
			return theBwdSwPtr_;
		}

		node*& BwdSw()
		{
			return theBwdSwPtr_;
		}

		node* BwdSe() const
		{
			return theBwdSePtr_;
		}

		node*& BwdSe()
		{
			return theBwdSePtr_;
		}

		node* BwdNe() const
		{
			return theBwdNePtr_;
		}

		node*& BwdNe()
		{
			return theBwdNePtr_;
		}

		node* BwdNw() const
		{
			return theBwdNwPtr_;
		}

		node*& BwdNw()
		{
			return theBwdNwPtr_;
		}
	};

	template<class Point>
	class Geo_PrTreeInternalHub<Point, 2>
	{

		/*Private Data*/
		typedef Geo_PrTreeNode<Point> node;

		node* theSwPtr_;
		node* theSePtr_;
		node* theNePtr_;
		node* theNwPtr_;

	public:

		Geo_PrTreeInternalHub()
			: theSwPtr_(0)
			, theSePtr_(0)
			, theNePtr_(0)
			, theNwPtr_(0)
		{}

		node* Sw() const
		{
			return theSwPtr_;
		}

		node*& Sw()
		{
			return theSwPtr_;
		}

		node* Se() const
		{
			return theSePtr_;
		}

		node*& Se()
		{
			return theSePtr_;
		}

		node* Ne() const
		{
			return theNePtr_;
		}

		node*& Ne()
		{
			return theNePtr_;
		}

		node* Nw() const
		{
			return theNwPtr_;
		}

		node*& Nw()
		{
			return theNwPtr_;
		}
	};

	template<class Point>
	class Geo_PrTreeNode
	{

		/*Private Data*/

		typedef Entity_Box<Point> BoxType;

		BoxType theBox_;

	public:

		Geo_PrTreeNode()
		{}

		Geo_PrTreeNode(const BoxType& theBox)
			: theBox_(theBox)
		{}

		virtual ~Geo_PrTreeNode()
		{}

		const BoxType& Box() const
		{
			return theBox_;
		}

		BoxType& Box()
		{
			return theBox_;
		}
	};

	template<class T, int Dim, bool Balanced>
	class Geo_PrTreeLeaf
		: public Geo_PrTreeNode<typename remove_pointer<T>::type::ptType>
		, public Geo_PrTreeBucket<T>
		, public Geo_PrTreeLeafHub<T, Dim, Balanced>
	{

		/*Private Data*/

	public:

		Geo_PrTreeLeaf()
		{}

		~Geo_PrTreeLeaf() override
		{}
	};

	template<class Point, int Dim>
	class Geo_PrTreeInternal
		: public Geo_PrTreeNode<Point>
		, public Geo_PrTreeInternalHub<Point, Dim>
	{

		/*Private Data*/

	public:

		Geo_PrTreeInternal()
		{}

		~Geo_PrTreeInternal() override
		{}
	};

	class Geo_PrTreeBase
		: public Geo_SearchTree_Base
	{

		/*Private Data*/

		Standard_Integer theNbSubDivide_;

	protected:

		Geo_PrTreeBase()
			: theNbSubDivide_(0)
		{}

		Standard_Integer NbSubdivide() const
		{
			return theNbSubDivide_;
		}

		Standard_Integer& NbSubdivide()
		{
			return theNbSubDivide_;
		}
	};

	struct Geo_PrTreeInfo
	{
		int BUCKET_SIZE;
		int MAX_INNER_SUBDIVIDE;

		Geo_PrTreeInfo()
			: BUCKET_SIZE(8)
			, MAX_INNER_SUBDIVIDE(20)
		{}
	};

	template
		<
		class T,
		bool Balanced = false
		>
		class Geo_PrTree
		: public Geo_PrTreeBase
		, public Geo_SearchTree<T>
		, public Geo_PrTreeInfo
	{

		/*Private Data*/

		typedef typename remove_pointer<T>::type Type;
		typedef typename Type::ptType Point;

		typedef Geo_PrTreeBase Base;
		typedef Geo_SearchTree<T> geom;

		typedef Geo_PrTreeNode<Point> node;
		typedef Geo_PrTreeLeaf<T, (int)Point::dim, Balanced> leafNode;
		typedef Geo_PrTreeInternal<Point, (int)Point::dim> internalNode;
		typedef Entity_Box<Point> boxType;

		template< bool cond, typename U >
		using resolvedType = typename std::enable_if< cond, U >::type;

		node* theRoot_;

		Standard_Boolean IsFull(const leafNode* t) const
		{
			return t->size() >= BUCKET_SIZE;
		}

		template<class U = void>
		resolvedType
			<
			is_two_dimension<(int)Point::dim>::value, U
			>
			SwitchToClear(internalNode*& t)
		{
			if (t->Sw()) Clear(t->Sw());
			if (t->Se()) Clear(t->Se());
			if (t->Ne()) Clear(t->Ne());
			if (t->Nw()) Clear(t->Nw());
		}

		template<class U = void>
		resolvedType
			<
			is_three_dimension<(int)Point::dim>::value, U
			>
			SwitchToClear(internalNode*& t);

		void Clear(node*& t)
		{
			leafNode* leaf =
				dynamic_cast<leafNode*>(t);

			if (leaf)
			{
				delete t;
				t = nullptr;
			}
			else
			{
				internalNode* Internal =
					dynamic_cast<internalNode*>(t);

				SwitchToClear(Internal);
				delete t;
				t = nullptr;
			}
		}

		template<class U = void>
		resolvedType
			<
			is_two_dimension<(int)Point::dim>::value, U
			>
			SwitchToInsert
			(
				const T& theItem,
				const Point& theCentre,
				const boxType& theBox,
				internalNode*& t
			)
		{
			switch (CalcQuadrant(geom::CoordinateOf(theItem), theCentre))
			{
			case Geo_Quadrant_SW:
				Insert(theItem, theBox.SubDivide(Box2d_SubDivideAlgorithm_Quad_SW), t->Sw());
				break;
			case Geo_Quadrant_SE:
				Insert(theItem, theBox.SubDivide(Box2d_SubDivideAlgorithm_Quad_SE), t->Se());
				break;
			case Geo_Quadrant_NE:
				Insert(theItem, theBox.SubDivide(Box2d_SubDivideAlgorithm_Quad_NE), t->Ne());
				break;
			case Geo_Quadrant_NW:
				Insert(theItem, theBox.SubDivide(Box2d_SubDivideAlgorithm_Quad_NW), t->Nw());
				break;
			}
		}

		template<class U = void>
		resolvedType
			<
			is_three_dimension<(int)Point::dim>::value, U
			>
			SwitchToInsert
			(
				const T& theItem,
				const Point& theCentre,
				const boxType& theBox,
				internalNode*& t
			)
		{
			switch (CalcOctant(geom::CoordinateOf(theItem), theCentre))
			{
			case Geo_Octant_Bwd_SW:
				Insert(theItem, theBox.SubDivide(Box3d_SubDivideAlgorithm_Aft_SW), t->BwdSw());
				break;
			case Geo_Octant_Bwd_SE:
				Insert(theItem, theBox.SubDivide(Box3d_SubDivideAlgorithm_Aft_SE), t->BwdSe());
				break;
			case Geo_Octant_Bwd_NE:
				Insert(theItem, theBox.SubDivide(Box3d_SubDivideAlgorithm_Aft_NE), t->BwdNe());
				break;
			case Geo_Octant_Bwd_NW:
				Insert(theItem, theBox.SubDivide(Box3d_SubDivideAlgorithm_Aft_NW), t->BwdNw());
				break;
			case Geo_Octant_Fwd_SW:
				Insert(theItem, theBox.SubDivide(Box3d_SubDivideAlgorithm_Fwd_SW), t->FwdSw());
				break;
			case Geo_Octant_Fwd_SE:
				Insert(theItem, theBox.SubDivide(Box3d_SubDivideAlgorithm_Fwd_SE), t->FwdSe());
				break;
			case Geo_Octant_Fwd_NE:
				Insert(theItem, theBox.SubDivide(Box3d_SubDivideAlgorithm_Fwd_NE), t->FwdNe());
				break;
			case Geo_Octant_Fwd_NW:
				Insert(theItem, theBox.SubDivide(Box3d_SubDivideAlgorithm_Fwd_NW), t->FwdNw());
				break;

			}
		}

		void Insert
		(
			const T& theItem,
			const boxType& theBox,
			node*& t
		)
		{
			if (!t)
			{
				leafNode* leaf = new leafNode;
				leaf->Box() = theBox;
				leaf->push_back(theItem);

				t = leaf;

				Base::Increment();
				return;
			}

			leafNode* leaf = dynamic_cast<leafNode*>(t);
			if (leaf)
			{
				if (IsFull(leaf))
				{
					Base::NbSubdivide()++;

					if (NbSubdivide() >= MAX_INNER_SUBDIVIDE)
					{
						FatalErrorIn(FunctionSIG)
							<< " Max Inner Subdivision EXCEEDED: Items are close too much!"
							<< abort(FatalError);
					}

					internalNode* Internal = new internalNode;
					Internal->Box() = std::move(t->Box());

					Base::ChangeNbItems() -= BUCKET_SIZE;

					const auto& box = Internal->Box();
					const auto& coord = box.CalcCentre();

					for (const auto& item : *leaf)
					{
						SwitchToInsert(item, coord, box, Internal);
					}

					SwitchToInsert(theItem, coord, box, Internal);

					delete t;
					t = Internal;
				}
				else
				{
					leaf->push_back(theItem);

					Base::Increment();
					return;
				}
			}
			else
			{
				internalNode* Internal =
					dynamic_cast<internalNode*>(t);

				SwitchToInsert
				(
					theItem,
					Internal->Box().CalcCentre(),
					Internal->Box(),
					Internal
				);
			}
		}

		template<class U = void>
		resolvedType
			<
			is_two_dimension<(int)Point::dim>::value, U
			>
			SwitchToRemove
			(
				const T& theItem,
				internalNode*& t
			)
		{
			switch (CalcQuadrant(geom::CoordinateOf(theItem), t->Box().CalcCentre()))
			{
			case Geo_Quadrant_SW:
				Remove(theItem, t->Sw());
				break;
			case Geo_Quadrant_SE:
				Remove(theItem, t->Se());
				break;
			case Geo_Quadrant_NE:
				Remove(theItem, t->Ne());
				break;
			case Geo_Quadrant_NW:
				Remove(theItem, t->Nw());
				break;
			}
		}

		template<class U = void>
		resolvedType
			<
			is_three_dimension<(int)Point::dim>::value, U
			>
			SwitchToRemove
			(
				const T& theItem,
				internalNode*& t
			)
		{
			switch (CalcOctant(geom::CoordinateOf(theItem), t->Box().CalcCentre()))
			{
			case Geo_Octant_Bwd_SW:
				Remove(theItem, t->BwdSw());
				break;
			case Geo_Octant_Bwd_SE:
				Remove(theItem, t->BwdSe());
				break;
			case Geo_Octant_Bwd_NE:
				Remove(theItem, t->BwdNe());
				break;
			case Geo_Octant_Bwd_NW:
				Remove(theItem, t->BwdNw());
				break;
			case Geo_Octant_Fwd_SW:
				Remove(theItem, t->FwdSw());
				break;
			case Geo_Octant_Fwd_SE:
				Remove(theItem, t->FwdSe());
				break;
			case Geo_Octant_Fwd_NE:
				Remove(theItem, t->FwdNe());
				break;
			case Geo_Octant_Fwd_NW:
				Remove(theItem, t->FwdNw());
				break;
			}
		}

		void Remove(const T& theItem, node*& t)
		{
			if (!t)
			{
				FatalErrorIn(FunctionSIG)
					<< "Item is not in tree"
					<< abort(FatalError);
			}

			leafNode* leaf =
				dynamic_cast<leafNode*>(t);

			if (leaf)
			{
				Standard_Integer bSize = leaf->size();
				leaf->remove(theItem);

				if (leaf->size() >= bSize)
				{
					FatalErrorIn(FunctionSIG)
						<< "Item is not in tree"
						<< abort(FatalError);
				}

				Base::Decrement();

				if (leaf->empty())
				{
					delete t;
					t = nullptr;
				}
			}
			else
			{
				internalNode* Internal =
					dynamic_cast<internalNode*>(t);

				SwitchToRemove(theItem, Internal);

				if
					(
						!Internal->Sw() &&
						!Internal->Se() &&
						!Internal->Ne() &&
						!Internal->Nw()
						)
				{
					delete t;
					t = nullptr;
				}
			}
		}

		template<class U = void>
		resolvedType
			<
			is_two_dimension<(int)Point::dim>::value, U
			>
			SwitchToRetrieveTo
			(
				internalNode* Internal,
				std::list<T>& theItems
			) const
		{
			if (Internal->Sw()) RetrieveTo(Internal->Sw(), theItems);
			if (Internal->Se()) RetrieveTo(Internal->Se(), theItems);
			if (Internal->Ne()) RetrieveTo(Internal->Ne(), theItems);
			if (Internal->Nw()) RetrieveTo(Internal->Nw(), theItems);
		}

		template<class U = void>
		resolvedType
			<
			is_three_dimension<(int)Point::dim>::value, U
			>
			SwitchToRetrieveTo
			(
				internalNode* Internal,
				std::list<T>& theItems
			) const
		{
			if (Internal->BwdSw()) RetrieveTo(Internal->BwdSw(), theItems);
			if (Internal->BwdSe()) RetrieveTo(Internal->BwdSe(), theItems);
			if (Internal->BwdNe()) RetrieveTo(Internal->BwdNe(), theItems);
			if (Internal->BwdNw()) RetrieveTo(Internal->BwdNw(), theItems);

			if (Internal->FwdSw()) RetrieveTo(Internal->FwdSw(), theItems);
			if (Internal->FwdSe()) RetrieveTo(Internal->FwdSe(), theItems);
			if (Internal->FwdNe()) RetrieveTo(Internal->FwdNe(), theItems);
			if (Internal->FwdNw()) RetrieveTo(Internal->FwdNw(), theItems);
		}

		void RetrieveTo(node* t, std::list<T>& theItems) const
		{
			leafNode* leaf = dynamic_cast<leafNode*>(t);

			if (leaf)
			{
				for (const auto& item : *leaf)
					theItems.push_back(item);
			}
			else
			{
				internalNode* Internal =
					dynamic_cast<internalNode*>(t);

				SwitchToRetrieveTo(Internal, theItems);
			}
		}

		template<class U = void>
		resolvedType
			<
			is_two_dimension<(int)Point::dim>::value, U
			>
			SwitchToSearch
			(
				const boxType& theRegion,
				internalNode* t,
				std::list<T>& theItems
			) const
		{
			if (t->Sw())
			{
				if (theRegion.IsIntersect(t->Sw()->Box()))
					Search(theRegion, t->Sw(), theItems);
			}

			if (t->Se())
			{
				if (theRegion.IsIntersect(t->Se()->Box()))
					Search(theRegion, t->Se(), theItems);
			}

			if (t->Ne())
			{
				if (theRegion.IsIntersect(t->Ne()->Box()))
					Search(theRegion, t->Ne(), theItems);
			}

			if (t->Nw())
			{
				if (theRegion.IsIntersect(t->Nw()->Box()))
					Search(theRegion, t->Nw(), theItems);
			}
		}

		template<class U = void>
		resolvedType
			<
			is_two_dimension<(int)Point::dim>::value, U
			>
			SwitchToSearch
			(
				const boxType& theRegion,
				internalNode* t,
				std::vector<T>& theItems
			) const
		{
			if (t->Sw())
			{
				if (theRegion.IsIntersect(t->Sw()->Box()))
					Search(theRegion, t->Sw(), theItems);
			}

			if (t->Se())
			{
				if (theRegion.IsIntersect(t->Se()->Box()))
					Search(theRegion, t->Se(), theItems);
			}

			if (t->Ne())
			{
				if (theRegion.IsIntersect(t->Ne()->Box()))
					Search(theRegion, t->Ne(), theItems);
			}

			if (t->Nw())
			{
				if (theRegion.IsIntersect(t->Nw()->Box()))
					Search(theRegion, t->Nw(), theItems);
			}
		}

		template<class U = void>
		resolvedType
			<
			is_three_dimension<(int)Point::dim>::value, U
			>
			SwitchToSearch
			(
				const boxType& theRegion,
				internalNode* t,
				std::list<T>& theItems
			) const
		{
			if (t->BwdSw())
			{
				if (theRegion.IsIntersect(t->BwdSw()->Box()))
					Search(theRegion, t->BwdSw(), theItems);
			}

			if (t->BwdSe())
			{
				if (theRegion.IsIntersect(t->BwdSe()->Box()))
					Search(theRegion, t->BwdSe(), theItems);
			}

			if (t->BwdNe())
			{
				if (theRegion.IsIntersect(t->BwdNe()->Box()))
					Search(theRegion, t->BwdNe(), theItems);
			}

			if (t->BwdNw())
			{
				if (theRegion.IsIntersect(t->BwdNw()->Box()))
					Search(theRegion, t->BwdNw(), theItems);
			}

			if (t->FwdSw())
			{
				if (theRegion.IsIntersect(t->FwdSw()->Box()))
					Search(theRegion, t->FwdSw(), theItems);
			}

			if (t->FwdSe())
			{
				if (theRegion.IsIntersect(t->FwdSe()->Box()))
					Search(theRegion, t->FwdSe(), theItems);
			}

			if (t->FwdNe())
			{
				if (theRegion.IsIntersect(t->FwdNe()->Box()))
					Search(theRegion, t->FwdNe(), theItems);
			}

			if (t->FwdNw())
			{
				if (theRegion.IsIntersect(t->FwdNw()->Box()))
					Search(theRegion, t->FwdNw(), theItems);
			}
		}

		template<class U = void>
		resolvedType
			<
			is_three_dimension<(int)Point::dim>::value, U
			>
			SwitchToSearch
			(
				const boxType& theRegion,
				internalNode* t,
				std::vector<T>& theItems
			) const
		{
			if (t->BwdSw())
			{
				if (theRegion.IsIntersect(t->BwdSw()->Box()))
					Search(theRegion, t->BwdSw(), theItems);
			}

			if (t->BwdSe())
			{
				if (theRegion.IsIntersect(t->BwdSe()->Box()))
					Search(theRegion, t->BwdSe(), theItems);
			}

			if (t->BwdNe())
			{
				if (theRegion.IsIntersect(t->BwdNe()->Box()))
					Search(theRegion, t->BwdNe(), theItems);
			}

			if (t->BwdNw())
			{
				if (theRegion.IsIntersect(t->BwdNw()->Box()))
					Search(theRegion, t->BwdNw(), theItems);
			}

			if (t->FwdSw())
			{
				if (theRegion.IsIntersect(t->FwdSw()->Box()))
					Search(theRegion, t->FwdSw(), theItems);
			}

			if (t->FwdSe())
			{
				if (theRegion.IsIntersect(t->FwdSe()->Box()))
					Search(theRegion, t->FwdSe(), theItems);
			}

			if (t->FwdNe())
			{
				if (theRegion.IsIntersect(t->FwdNe()->Box()))
					Search(theRegion, t->FwdNe(), theItems);
			}

			if (t->FwdNw())
			{
				if (theRegion.IsIntersect(t->FwdNw()->Box()))
					Search(theRegion, t->FwdNw(), theItems);
			}
		}

		void Search
		(
			const boxType& theBox,
			node* t,
			std::list<T>& theItems
		) const
		{
			leafNode* leaf = dynamic_cast<leafNode*>(t);

			if (leaf)
			{
				for (const auto& item : *leaf)
				{
					if (theBox.IsInside(geom::CoordinateOf(item)))
					{
						theItems.push_back(item);
					}
				}
			}
			else
			{
				internalNode* Internal =
					dynamic_cast<internalNode*>(t);

				SwitchToSearch(theBox, Internal, theItems);
			}
		}

		void Search
		(
			const boxType& theBox,
			node* t,
			std::vector<T>& theItems
		) const
		{
			leafNode* leaf = dynamic_cast<leafNode*>(t);

			if (leaf)
			{
				for (const auto& item : *leaf)
				{
					if (theBox.IsInside(geom::CoordinateOf(item)))
					{
						theItems.push_back(item);
					}
				}
			}
			else
			{
				internalNode* Internal =
					dynamic_cast<internalNode*>(t);

				SwitchToSearch(theBox, Internal, theItems);
			}
		}

	public:

		Geo_PrTree()
			: theRoot_(nullptr)
		{}

		~Geo_PrTree()
		{
			Clear();
		}

		Standard_Integer Size() const
		{
			return Base::NbItems();
		}

		Standard_Boolean IsEmpty() const
		{
			return !theRoot_;
		}

		void InsertToGeometry(const T& theItem)
		{
			Debug_If_Condition_Message
			(
				!geom::CoordinateOf, " No coordinate function for Pr-Tree"
			);
			Insert(theItem, geom::GeometryBoundingBox(), theRoot_);
		}

		void InsertToGeometry(const std::vector<T>& theItems)
		{
			for (const auto& item : theItems)
				InsertToGeometry(item);
		}

		void RemoveFromGeometry(const T& theItem)
		{
			Remove(theItem, theRoot_);
		}

		void RetrieveFromGeometryTo(std::list<T>& theItems) const
		{
			RetrieveTo(theRoot_, theItems);
		}

		void RetrieveFromGeometryTo
		(
			std::vector<T>& theItems
		) const
		{
			RetrieveTo(theRoot_, theItems);
		}

		void GeometrySearch
		(
			const Standard_Real theRadius,
			const Point& theCentre,
			std::list<T>& theList
		) const
		{
			Search
			(
				Entity_Box<Point>::Box(theCentre, theRadius),
				theRoot_,
				theList
			);
		}

		void GeometrySearch
		(
			const Standard_Real theRadius,
			const Point& theCentre,
			std::vector<T>& theList
		) const
		{
			Search
			(
				Entity_Box<Point>::Box(theCentre, theRadius),
				theRoot_,
				theList
			);
		}

		void GeometrySearch
		(
			const Entity_Box<Point>& theRegion,
			std::list<T>& theList
		) const
		{
			Search
			(
				theRegion,
				theRoot_,
				theList
			);
		}

		void GeometrySearch
		(
			const Entity_Box<Point>& theRegion,
			std::vector<T>& theList
		) const
		{
			Search
			(
				theRegion,
				theRoot_,
				theList
			);
		}

		void Clear()
		{
			Clear(theRoot_);
		}

	};


}

#include <Geo_PrTreeI.hxx>

#endif // !_Geo_PrTree_Header
