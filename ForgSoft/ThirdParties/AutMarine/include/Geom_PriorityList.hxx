#pragma once
#ifndef _Geom_PriorityList_Header
#define _Geom_PriorityList_Header

#include <Standard_TypeDef.hxx>
#include <Adt_List.hxx>
#include <Stl_Vector.hxx>

namespace AutLib
{

	class Geom_PriorityListBase
	{

		/*Private Data*/

		Standard_Integer NbItems_;

	public:

		Geom_PriorityListBase()
			: NbItems_(0)
		{}

		void Increment()
		{
			NbItems_++;
		}

		void Decrement()
		{
			NbItems_--;
		}

		Standard_Integer NbPriorities() const
		{
			return NbItems_;
		}
	};

	template<class T>
	class Geom_PriorityList
		: public Geom_PriorityListBase
	{

		/*Private Data*/

		Adt_Ary1d<T> theData_;

		Standard_Real(*LengthValue)(const T&);


		Standard_Boolean overFlow() const
		{
			return NbPriorities() >= theData_.Size();
		}

		Standard_Integer LeftChild(const Standard_Integer Index) { return 2 * Index + 1; }

		Standard_Integer RightChild(const Standard_Integer Index) { return 2 * Index + 2; }

		Standard_Integer Parent(const Standard_Integer Index) { return (Index - 1) / 2; }

		void ShiftUp(const Standard_Integer Index)
		{
			if (Index)
			{
				Standard_Integer ParentIndex = Parent(Index);

				if (LengthValue(theData_[ParentIndex]) > LengthValue(theData_[Index]))
				{
					std::swap(theData_[ParentIndex], theData_[Index]);

					ShiftUp(ParentIndex);
				}
			}
		}

		void ShiftDown(const Standard_Integer Index)
		{
			Standard_Integer
				LeftChildIndex,
				RightChildIndex,
				MinIndex;

			LeftChildIndex = LeftChild(Index);
			RightChildIndex = RightChild(Index);

			if (RightChildIndex >= NbPriorities())
			{
				if (LeftChildIndex >= NbPriorities())
					return;
				else
					MinIndex = LeftChildIndex;
			}
			else
			{
				if (LengthValue(theData_[LeftChildIndex]) <= LengthValue(theData_[RightChildIndex]))
					MinIndex = LeftChildIndex;
				else
					MinIndex = RightChildIndex;
			}

			if (LengthValue(theData_[Index]) > LengthValue(theData_[MinIndex]))
			{
				std::swap(theData_[MinIndex], theData_[Index]);

				ShiftDown(MinIndex);
			}
		}

		T Remove()
		{
			if (theData_.IsEmpty())
			{
				FatalErrorIn(FunctionSIG)
					<< " Heap is empty"
					<< abort(FatalError);
			}

			T Item = theData_[0];
			theData_[0] = theData_[NbPriorities() - 1];
			Decrement();

			if (NbPriorities() > 0) ShiftDown(0);
			MOVE(Item);
		}

	public:

		Geom_PriorityList()
			: LengthValue(NULL)
		{}

		Geom_PriorityList(Standard_Real(*lengthValue)(const T&))
		{
			LengthValue = lengthValue;
		}

		Standard_Integer PrioritySize() const
		{
			return NbPriorities();
		}

		Standard_Boolean IsPriorityEmpty() const
		{
			return !NbPriorities();
		}

		Standard_Boolean RetrieveFromPriority(T& theItem)
		{
			if (IsPriorityEmpty()) return Standard_False;
			else
			{
				theItem = Remove();
				return Standard_True;
			}
		}

		void SetSizeToPriority(const Standard_Integer theSize)
		{
			theData_.Resize(theSize);
		}

		void InsertToPriority(const T& theItem)
		{
			Debug_If_Condition_Message(!LengthValue, " No Set Comparable Function For Heap");
			if (overFlow())
			{
				FatalErrorIn(FunctionSIG)
					<< " Heap's underlying storage is overflow"
					<< abort(FatalError);
			}

			Increment();
			theData_[NbPriorities() - 1] = theItem;

			ShiftUp(NbPriorities() - 1);
		}

		void InsertToPriority(const Adt_Ary1d<T>& theItems)
		{
			theData_.Resize(theItems.Size());
			forThose(Index, 0, MaxIndexOf(theItems))
				InsertToPriority(theItems[Index]);
		}

		void InsertToPriority(const Adt_Queue<T>& theItems)
		{
			theData_.Resize(theItems.Size());
			for (const auto& item : theItems)
				InsertToPriority(item);
		}

		void InsertToPriority(const Stl_Vector<T>& theItems)
		{
			theData_.Resize((Standard_Integer)theItems.size());
			for (const auto& item : theItems)
				InsertToPriority(item);
		}

		void SetPrioritySize(const Standard_Integer Size)
		{
			theData_.Resize(Size);
		}

		void SetPriorityFunction(Standard_Real(*lengthValue)(const T&))
		{
			LengthValue = lengthValue;
		}
	};
}

#endif // !_Geom_PriorityList_Header
