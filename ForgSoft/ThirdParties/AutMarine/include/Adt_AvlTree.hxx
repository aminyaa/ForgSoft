#pragma once
#ifndef _Adt_AvlTree_Header
#define _Adt_AvlTree_Header

#include <Global_Macros.hxx>
#include <Standard_TypeDef.hxx>
#include <Adt_List.hxx>
#include <Stl_Vector.hxx>
#include <Stl_List.hxx>

namespace AutLib
{

	// Forward Declarations
	template<typename Comparable> class Adt_AvlTree;

	template<class Comparable>
	class Adt_AvlTreeNode
	{

		/*Private Data*/

		friend class Adt_AvlTree<Comparable>;

		Comparable theElement_;

		Adt_AvlTreeNode<Comparable>* theLeft_;
		Adt_AvlTreeNode<Comparable>* theRight_;

		Standard_Integer theHeight_;

	public:

		Adt_AvlTreeNode
		(
			const Comparable& Element,
			Adt_AvlTreeNode<Comparable>* Left,
			Adt_AvlTreeNode<Comparable>* Right,
			const Standard_Integer Height = 0
		)
			: theElement_(Element)
			, theLeft_(Left)
			, theRight_(Right)
			, theHeight_(Height)
		{}
	};

	class Adt_AvlTreeBase
	{

		/* Private Data*/

		//- Nb of items in the tree
		Standard_Integer theNbElements_;

	protected:

		void Increment()
		{
			theNbElements_++;
		}

		void Decrement()
		{
			theNbElements_--;
		}

	public:

		Adt_AvlTreeBase()
			: theNbElements_(0)
		{}

		static const Standard_Integer ALLOWED_IMBALANCE = 1;

		Standard_Integer Size() const
		{
			return theNbElements_;
		}

		Standard_Boolean IsEmpty() const
		{
			return !theNbElements_;
		}
	};

	template<typename Comparable>
	class Adt_AvlTree
		: public Adt_AvlTreeBase
	{

		/*Private Data*/

		//- Root of the tree
		Adt_AvlTreeNode<Comparable>* theRoot_;

		//- A function that compares between two items in tree
		Standard_Boolean(*IsLessPtr)(const Comparable&, const Comparable&);

		//- Disallow Bitwise copy constructor and copy assignment
		DisallowBitWiseCopy(Adt_AvlTree);


		Standard_Integer Height(Adt_AvlTreeNode<Comparable>* t) const
		{
			return t IS_EQUAL nullptr ? -1 : t->theHeight_;
		}

		void Insert
		(
			const Comparable & x,
			Adt_AvlTreeNode<Comparable>*& t
		)
		{
			if (t == nullptr)
			{
				t = new Adt_AvlTreeNode<Comparable>(x, 0, 0);
				Increment();
			}
			else if (IsLessPtr(x, t->theElement_))
				Insert(x, t->theLeft_);
			else if (IsLessPtr(t->theElement_, x))
				Insert(x, t->theRight_);
			else
			{
				FatalErrorIn(FunctionSIG)
					<< "Duplicate Data"
					<< abort(FatalError);
			}

			Balance(t);
		}

		void InsertIgnoreWarning
		(
			const Comparable & x,
			Adt_AvlTreeNode<Comparable>*& t
		)
		{
			if (t == nullptr)
			{
				t = new Adt_AvlTreeNode<Comparable>(x, 0, 0);

				Increment();
			}
			else if (IsLessPtr(x, t->theElement_))
				InsertIgnoreWarning(x, t->theLeft_);
			else if (IsLessPtr(t->theElement_, x))
				InsertIgnoreWarning(x, t->theRight_);
			else
			{
				return;  // duplicate data
			}

			Balance(t);
		}

		void Remove
		(
			const Comparable & x,
			Adt_AvlTreeNode<Comparable>*& t
		)
		{
			if (t == nullptr)
			{
				FatalErrorIn(FunctionSIG)
					<< " Item not found"
					<< abort(FatalError);
				return;
			}

			if (IsLessPtr(x, t->theElement_))
				Remove(x, t->theLeft_);
			else if (IsLessPtr(t->theElement_, x))
				Remove(x, t->theRight_);
			else if (t->theLeft_ != nullptr && t->theRight_ != nullptr) // Two children
			{
				t->theElement_ = FindMin(t->theRight_)->theElement_;
				Remove(t->theElement_, t->theRight_);
			}
			else
			{
				Adt_AvlTreeNode<Comparable> *oldNode = t;
				t = (t->theLeft_ != nullptr) ? t->theLeft_ : t->theRight_;
				delete oldNode;
				oldNode = NULL;

				Decrement();
			}

			Balance(t);
		}

		Standard_Boolean RemoveIgnoreWarning
		(
			const Comparable & x,
			Adt_AvlTreeNode<Comparable>*& t
		)
		{
			if (t == nullptr)
			{
				return Standard_True;
			}

			if (IsLessPtr(x, t->theElement_))
				return RemoveIgnoreWarning(x, t->theLeft_);
			else if (IsLessPtr(t->theElement_, x))
				return RemoveIgnoreWarning(x, t->theRight_);
			else if (t->theLeft_ != nullptr && t->theRight_ != nullptr) // Two children
			{
				t->theElement_ = FindMin(t->theRight_)->theElement_;
				return RemoveIgnoreWarning(t->theElement_, t->theRight_);
			}
			else
			{
				Adt_AvlTreeNode<Comparable> *oldNode = t;
				t = (t->theLeft_ != nullptr) ? t->theLeft_ : t->theRight_;
				delete oldNode;
				oldNode = NULL;

				Decrement();
			}

			Balance(t);
			return Standard_False;
		}

		void Balance(Adt_AvlTreeNode<Comparable>*& t)
		{
			if (t == nullptr)
				return;

			if (Height(t->theLeft_) - Height(t->theRight_) > ALLOWED_IMBALANCE)
				if (Height(t->theLeft_->theLeft_) >= Height(t->theLeft_->theRight_))
					RotateWithLeftChild(t);
				else
					DoubleWithLeftChild(t);
			else
				if (Height(t->theRight_) - Height(t->theLeft_) > ALLOWED_IMBALANCE)
					if (Height(t->theRight_->theRight_) >= Height(t->theRight_->theLeft_))
						RotateWithRightChild(t);
					else
						DoubleWithRightChild(t);

			t->theHeight_ = MAX(Height(t->theLeft_), Height(t->theRight_)) + 1;
		}

		void Clear(Adt_AvlTreeNode<Comparable>*& t)
		{
			if (t NOT_EQUAL nullptr)
			{
				Clear(t->theLeft_);
				Clear(t->theRight_);

				Decrement();

				delete t;
			}
			t = NULL;
		}

		Standard_Boolean IsContains(const Comparable & x, Adt_AvlTreeNode<Comparable>* t) const
		{
			if (t == nullptr)
				return Standard_False;
			else if (IsLessPtr(x, t->theElement_))
				return IsContains(x, t->theLeft_);
			else if (IsLessPtr(t->theElement_, x))
				return IsContains(x, t->theRight_);
			else
				return Standard_True;    // Match
		}

		void RotateWithLeftChild(Adt_AvlTreeNode<Comparable>*& k2)
		{
			Adt_AvlTreeNode<Comparable> *k1 = k2->theLeft_;
			k2->theLeft_ = k1->theRight_;
			k1->theRight_ = k2;
			k2->theHeight_ = MAX(Height(k2->theLeft_), Height(k2->theRight_)) + 1;
			k1->theHeight_ = MAX(Height(k1->theLeft_), k2->theHeight_) + 1;
			k2 = k1;
		}

		void RotateWithRightChild(Adt_AvlTreeNode<Comparable>*& k1)
		{
			Adt_AvlTreeNode<Comparable> *k2 = k1->theRight_;
			k1->theRight_ = k2->theLeft_;
			k2->theLeft_ = k1;
			k1->theHeight_ = MAX(Height(k1->theLeft_), Height(k1->theRight_)) + 1;
			k2->theHeight_ = MAX(Height(k2->theRight_), k1->theHeight_) + 1;
			k1 = k2;
		}

		void DoubleWithLeftChild(Adt_AvlTreeNode<Comparable>*& k3)
		{
			RotateWithRightChild(k3->theLeft_);
			RotateWithLeftChild(k3);
		}

		void DoubleWithRightChild(Adt_AvlTreeNode<Comparable>*& k1)
		{
			RotateWithLeftChild(k1->theRight_);
			RotateWithRightChild(k1);
		}

		void RetrieveTo
		(
			Adt_AvlTreeNode<Comparable>* t,
			Adt_Queue<Comparable>& Queue
		) const
		{
			if (t NOT_EQUAL nullptr)
			{
				RetrieveTo(t->theLeft_, Queue);
				Queue.EnQueue(t->theElement_);
				RetrieveTo(t->theRight_, Queue);
			}
		}

		void RetrieveTo
		(
			Adt_AvlTreeNode<Comparable>* t, 
			Stl_List<Comparable>& List
		) const
		{
			if (t NOT_EQUAL nullptr)
			{
				RetrieveTo(t->theLeft_, List);
				List.push_back(t->theElement_);
				RetrieveTo(t->theRight_, List);
			}
		}

		void RetrieveTo
		(
			Adt_AvlTreeNode<Comparable>* t,
			Stl_Vector<Comparable>& List
		) const
		{
			if (t NOT_EQUAL nullptr)
			{
				RetrieveTo(t->theLeft_, List);
				List.push_back(t->theElement_);
				RetrieveTo(t->theRight_, List);
			}
		}

		Adt_Ary1d<Comparable> Retrieve() const
		{
			Adt_Ary1d<Comparable> Array;
			RetrieveTo(Array);
			MOVE(Array);
		}

		Adt_AvlTreeNode<Comparable>* FindMin(Adt_AvlTreeNode<Comparable>* t) const
		{
			if (t IS_EQUAL nullptr)
				return nullptr;
			if (t->theLeft_ IS_EQUAL nullptr)
				return t;
			return FindMin(t->theLeft_);
		}

		Adt_AvlTreeNode<Comparable>* FindMax(Adt_AvlTreeNode<Comparable>* t) const
		{
			if (t NOT_EQUAL nullptr)
				while (t->theRight_ NOT_EQUAL nullptr)
					t = t->theRight_;
			return t;
		}

	public:

		Adt_AvlTree()
			: theRoot_(nullptr)
		{}

		Standard_Boolean IsContains(const Comparable& Element) const
		{
			return IsContains(Element, theRoot_);
		}

		void Insert(const Comparable & Element)
		{
			Debug_If_Condition_Message(IsLessPtr IS_EQUAL NULL, "No Set Comparable function");
			Insert(Element, theRoot_);
		}

		void Insert(const Adt_Ary1d<Comparable>& Elements)
		{
			Debug_If_Condition_Message(IsLessPtr IS_EQUAL NULL, "No Set Comparable function");
			forThose(Index, 0, MaxIndexOf(Elements))
			{
				Insert(Elements[Index], theRoot_);
			}
		}

		void Insert(const Stl_Vector<Comparable>& Elements)
		{
			Debug_If_Condition_Message(IsLessPtr IS_EQUAL NULL, "No Set Comparable function");
			forThose(Index, 0, Elements.size() - 1)
			{
				Insert(Elements[Index], theRoot_);
			}
		}

		void InsertIgnoreDup(const Comparable & Element)
		{
			Debug_If_Condition_Message(IsLessPtr IS_EQUAL NULL, "No Set Comparable function");
			InsertIgnoreWarning(Element, theRoot_);
		}

		void InsertIgnoreDup(const Adt_Ary1d<Comparable>& Elements)
		{
			Debug_If_Condition_Message(IsLessPtr IS_EQUAL NULL, "No Set Comparable function");
			forThose(Index, 0, MaxIndexOf(Elements))
			{
				InsertIgnoreWarning(Elements[Index], theRoot_);
			}
		}

		void Remove(const Comparable & Element)
		{
			Debug_If_Condition_Message(IsLessPtr IS_EQUAL NULL, "No Set Comparable function");
			Try_Exception_Handle_ReThrow(Remove(Element, theRoot_));
		}

		void Remove(const Adt_Ary1d<Comparable>& Elements)
		{
			Debug_If_Condition_Message(IsLessPtr IS_EQUAL NULL, "No Set Comparable function");
			forThose(Index, 0, MaxIndexOf(Elements))
				Remove(Elements[Index], theRoot_);
		}

		Standard_Boolean RemoveIgnoreWarning(const Comparable & Element)
		{
			Debug_If_Condition_Message(IsLessPtr IS_EQUAL NULL, "No Set Comparable function");
			return RemoveIgnoreWarning(Element, theRoot_);
		}

		void RemoveIgnoreWarning(const Adt_Ary1d<Comparable>& Elements)
		{
			Debug_If_Condition_Message(IsLessPtr IS_EQUAL NULL, "No Set Comparable function");
			forThose(Index, 0, MaxIndexOf(Elements))
				RemoveIgnoreWarning(Elements[Index], theRoot_);
		}

		void Root(Comparable & Element)
		{
			if (IsEmpty())
			{
				FatalErrorIn(FunctionSIG)
					<< "The tree is empty"
					<< abort(FatalError);
			}
			Element = theRoot_->theElement_;
		}

		void RetrieveTo(Adt_Queue<Comparable>& Queue) const
		{
			RetrieveTo(theRoot_, Queue);
		}

		void RetrieveTo(Adt_Ary1d<Comparable>& Array) const
		{
			Adt_Queue<Comparable> Queue;
			RetrieveTo(theRoot_, Queue);
			Queue.RetrieveTo(Array);
		}

		void RetrieveTo(Stl_List<Comparable>& List) const
		{
			RetrieveTo(theRoot_, List);
		}

		void RetrieveTo
		(
			Stl_Vector<Comparable>& List
		) const
		{
			RetrieveTo(theRoot_, List);
		}

		void RetrieveTo
		(
			Stl_Vector<Comparable>& Vector,
			Standard_Integer thePlus
		) const
		{
			Stl_List<Comparable> List;
			RetrieveTo(List);

			if (List.size() + thePlus > Vector.size())
				Vector.reserve(List.size() + thePlus);
			std::copy(std::begin(List), std::end(List), std::back_inserter(Vector));
		}

		void SetComparableFunction
		(
			Standard_Boolean(*IsLess)(const Comparable&, const Comparable&)
		)
		{
			IsLessPtr = IsLess;
		}

		void Clear()
		{
			Clear(theRoot_);
		}
	};
}

#endif // !_Adt_AvlTree_Header
