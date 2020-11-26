#pragma once
#ifndef _Geo_AdTree_Header
#define _Geo_AdTree_Header

#include <Geo_SearchTree.hxx>
#include <Geo_Tools.hxx>
#include <Entity2d_Box.hxx>

#include <vector>
#include <list>

namespace tnbLib
{

	template<class T, class Point>
	class Geo_AdTreeNode
	{

		/*Private Data*/

		typedef Geo_AdTreeNode<T, Point> NodeType;

		NodeType* theLeft_;
		NodeType* theRight_;

		Entity_Box<Point> theRegion_;

		T theData_;

		Standard_Integer theLevel_;

	public:

		Geo_AdTreeNode()
			: theLeft_(0)
			, theRight_(0)
		{}

		Geo_AdTreeNode
		(
			const T& theItem,
			const Entity_Box<Point>& theRegion,
			const Standard_Integer theLevel
		)
			: theData_(theItem)
			, theRegion_(theRegion)
			, theLevel_(theLevel)
			, theLeft_(0)
			, theRight_(0)
		{}

		NodeType* LeftPtr() const
		{
			return theLeft_;
		}

		NodeType*& LeftPtr()
		{
			return theLeft_;
		}

		NodeType* RightPtr() const
		{
			return theRight_;
		}

		NodeType*& RightPtr()
		{
			return theRight_;
		}

		const Entity_Box<Point>& Box() const
		{
			return theRegion_;
		}

		Entity_Box<Point>& Box()
		{
			return theRegion_;
		}

		const T& Data() const
		{
			return theData_;
		}

		T& Data()
		{
			return theData_;
		}

		Standard_Integer Level() const
		{
			return theLevel_;
		}

		Standard_Integer& Level()
		{
			return theLevel_;
		}
	};

	template<class T>
	class Geo_AdTree
		: public Geo_SearchTree<T>
	{
		/*Private Data*/

		typedef typename remove_pointer<T>::type::ptType Point;
		typedef Geo_AdTreeNode<T, Point> NodeType;

		NodeType* theRoot_;

		void CheckFun() const
		{
			if (!Geo_SearchTree<T>::CoordinateOf)
			{
				FatalErrorIn("void CheckFun()")
					<< "No geometry coordinate function has been specified!"
					<< abort(FatalError);
			}
		}

		void FindLeaf
		(
			NodeType* t,
			NodeType*& Leaf
		) const
		{
			if (!t)
				Leaf = 0;
			else if (t->LeftPtr() == 0 && t->RightPtr() == 0)
				Leaf = t;
			else if (t->LeftPtr())
				FindLeaf(t->LeftPtr(), Leaf);
			else
				FindLeaf(t->RightPtr(), Leaf);
		}

		void RetrieveTo
		(
			NodeType* t,
			std::list<T>& theItems
		) const
		{
			if (t)
			{
				RetrieveTo(t->LeftPtr(), theItems);
				theItems.push_back(t->Data());
				RetrieveTo(t->RightPtr(), theItems);
			}
		}

		void RetrieveTo
		(
			NodeType* t,
			std::vector<T>& theItems
		) const
		{
			if (t)
			{
				RetrieveTo(t->LeftPtr(), theItems);
				theItems.push_back(t->Data());
				RetrieveTo(t->RightPtr(), theItems);
			}
		}

		void Insert
		(
			const T& theItem,
			const Entity_Box<Point>& theRegion,
			const Standard_Integer theLevel,
			NodeType*& t
		)
		{
			if (!t)
			{
				t = new NodeType
				(
					theItem,
					theRegion,
					theLevel
				);
				Geo_SearchTree<T>::Increment();
				return;
			}

			Standard_Integer Index = IndexLevel(theLevel);
			Standard_Real X, Lower, Upper;
			X = Geo_SearchTree<T>::CoordinateOf(theItem).Coord(Index + 1);
			theRegion.GetBound(Index, Lower, Upper);

			Standard_Boolean Left =
				(X >= Lower && X < (Standard_Real)0.5*(Lower + Upper));

			Insert
			(
				theItem,
				theRegion.Half
				(
					Index,
					Left
					? Box2d_SubDivideAlgorithm_Half_Left
					: Box2d_SubDivideAlgorithm_Half_Right
				),
				t->Level() + 1,
				Left ? t->LeftPtr() : t->RightPtr()
			);
		}

		void Remove
		(
			const T& theItem,
			NodeType*& t
		)
		{
			if (!t)
			{
				FatalErrorIn(FunctionSIG)
					<< " The Item is not in the tree"
					<< abort(FatalError);
			}

			if (theItem == t->Data())
			{
				if (t->RightPtr())
				{
					NodeType* Leaf(0);
					FindLeaf(t->RightPtr(), Leaf);

					t->Data() = Leaf->Data();
					Remove(t->Data(), t->RightPtr());
				}
				else if (t->LeftPtr())
				{
					NodeType* Leaf(0);
					FindLeaf(t->LeftPtr(), Leaf);

					t->Data() = Leaf->Data();
					Remove(t->Data(), t->LeftPtr());
				}
				else
				{
					NodeType* Old = t;
					t = (t->LeftPtr()) ? t->LeftPtr() : t->RightPtr();
					delete Old;

					Geo_SearchTree<T>::Decrement();
				}
			}
			else
			{
				const auto& Coord = Geo_SearchTree<T>::CoordinateOf(theItem);

				Standard_Integer Index = IndexLevel(t->Level());
				Standard_Real X, Lower, Upper;

				X = Coord.Coord(Index + 1);
				t->Box().GetBound(Index, Lower, Upper);

				if (X >= Lower && X < (Standard_Real)0.5*(Lower + Upper))
					Remove(theItem, t->LeftPtr());
				else
					Remove(theItem, t->RightPtr());
			}
		}

		void Search
		(
			const Entity_Box<Point>& theRegion,
			NodeType* t,
			std::vector<T>& theItems
		) const
		{
			if (!t) return;

			Standard_Integer Index = IndexLevel(t->Level());

			if (theRegion.IsInside(Geo_SearchTree<T>::CoordinateOf(t->Data())))
				theItems.push_back(t->Data());

			Standard_Real Xm, Lower, Upper;
			t->Box().GetBound(Index, Lower, Upper);
			Xm = (Standard_Real)0.5*(Lower + Upper);

			Standard_Real X0, X1;
			theRegion.GetBound(Index, X0, X1);

			if (Processor::IsIntersect(X0, X1, Lower, Xm))
				Search(theRegion, t->LeftPtr(), theItems);

			if (Processor::IsIntersect(X0, X1, Xm, Upper))
				Search(theRegion, t->RightPtr(), theItems);
		}

		void Search
		(
			const Entity_Box<Point>& theRegion,
			NodeType* t,
			std::list<T>& theItems
		) const
		{
			if (!t) return;

			Standard_Integer Index = IndexLevel(t->Level());

			if (theRegion.IsInside(Geo_SearchTree<T>::CoordinateOf(t->Data())))
				theItems.push_back(t->Data());

			Standard_Real Xm, Lower, Upper;
			t->Box().GetBound(Index, Lower, Upper);
			Xm = (Standard_Real)0.5*(Lower + Upper);

			Standard_Real X0, X1;
			theRegion.GetBound(Index, X0, X1);

			if (Processor::IsIntersect(X0, X1, Lower, Xm))
				Search(theRegion, t->LeftPtr(), theItems);

			if (Processor::IsIntersect(X0, X1, Xm, Upper))
				Search(theRegion, t->RightPtr(), theItems);
		}

		void Clear(NodeType*& t)
		{
			if (!t)
			{
				Clear(t->LeftPtr());
				Clear(t->RightPtr());

				Geo_SearchTree<T>::Decrement();
				delete t;
			}
			t = 0;
		}

	protected:

		Standard_Integer IndexLevel(const Standard_Integer theLevel) const
		{
			return theLevel % Point::nbCmpts;
		}

	public:

		Geo_AdTree()
			: theRoot_(0)
		{}

		Standard_Integer Size() const
		{
			return Geo_SearchTree<T>::NbItems();
		}

		Standard_Boolean IsEmpty() const
		{
			return !theRoot_;
		}

		void InsertToGeometry(const T& theItem)
		{
#if MESH_DEBUG
			CheckFun();
#endif			
			Insert(theItem, Geo_SearchTree<T>::GeometryBoundingBox(), 0, theRoot_);
		}

		void InsertToGeometry(const Adt_Ary1d<T>& theItems)
		{

			for (const auto& item : theItems)
			{
				InsertToGeometry(item);
			}
		}

		void InsertToGeometry(const std::vector<T>& theItems)
		{
			for (const auto& item : theItems)
			{
				InsertToGeometry(item);
			}
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
			std::list<T> List;
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
	};
}

#endif // !_Geo_AdTree_Header
