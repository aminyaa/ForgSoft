#pragma once
#ifndef _Adt_Ary1d_Header
#define _Adt_Ary1d_Header

#include <Standard_TypeDef.hxx>
#include <Standard_OStream.hxx>
#include <error.hxx>
#include <OSstream.hxx>

namespace AutLib
{

	template<class T>
	class Adt_Ary1d
	{

		/*Private Data*/

		Standard_Integer myLowerBound_;
		Standard_Integer myUpperBound_;
		Standard_Boolean myDeletable_;

		T* vr_;

	public:

		typedef T* iterator;
		typedef const T* const_iterator;

		Adt_Ary1d()
			: myLowerBound_(0)
			, myUpperBound_(-1)
			, myDeletable_(Standard_True)
		{
			T* pBegin = new T[Length()];
			vr_ = pBegin - myLowerBound_;
		}

		explicit Adt_Ary1d(const Standard_Integer theSize)
			: myLowerBound_(0)
			, myUpperBound_(theSize - 1)
			, myDeletable_(Standard_True)
		{
			T* pBegin = new T[Length()];
			vr_ = pBegin - myLowerBound_;
		}

		Adt_Ary1d
		(
			const Standard_Integer theLower,
			const Standard_Integer theUpper
		)
			: myLowerBound_(theLower)
			, myUpperBound_(theUpper)
			, myDeletable_(Standard_True)
		{
			T* pBegin = new T[Length()];
			vr_ = pBegin - theLower;
		}

		Adt_Ary1d
		(
			const T& theBeging,
			const Standard_Integer theLower, 
			const Standard_Integer theUpper
		)
			: myLowerBound_(theLower)
			, myUpperBound_(theUpper)
			, myDeletable_(Standard_False)
		{
			vr_ = (T*)&theBeging - theLower;
		}

		Adt_Ary1d(const Adt_Ary1d<T>& theOther)
			: myLowerBound_(theOther.myLowerBound_)
			, myUpperBound_(theOther.myUpperBound_)
			, myDeletable_(theOther.myDeletable_)
		{
			T* pBegin = new T[Length()];

			vr_ = pBegin - myLowerBound_;

			T* pMyItem = &vr_[myLowerBound_];
			T* const pEndItem = &(theOther.vr_)[theOther.myUpperBound_];
			T* pItem = &(theOther.vr_)[theOther.myLowerBound_];

			while (pItem <= pEndItem) * pMyItem++ = *pItem++;
		}

		~Adt_Ary1d()
		{
			Clear();
		}

		Adt_Ary1d<T>& operator=(const Adt_Ary1d<T>& theOther)
		{
			if (this NOT_EQUAL &theOther)
			{
				Clear();

				myLowerBound_ = theOther.myLowerBound_;
				myUpperBound_ = theOther.myUpperBound_;
				myDeletable_ = theOther.myDeletable_;

				T* pBegin = new T[Length()];

				vr_ = pBegin - myLowerBound_;

				T* pMyItem = &vr_[myLowerBound_];
				T* const pEndItem = &(theOther.vr_)[theOther.myUpperBound_];
				T* pItem = &(theOther.vr_)[theOther.myLowerBound_];

				while (pItem <= pEndItem) * pMyItem++ = *pItem++;
			}
			return *this;
		}

		Adt_Ary1d<T>& operator=(const T& Entity)
		{
			forThose(Index, 0, Length() - 1)
			{
				vr_[Index + Lower()] = Entity;
			}
			return *this;
		}

		Adt_Ary1d<T>& operator+=(const T& Entity)
		{
			forThose(Index, 0, Length() - 1)
			{
				vr_[Index + Lower()] += Entity;
			}
			return *this;
		}

		Adt_Ary1d<T>& operator-=(const T& Entity)
		{
			forThose(Index, 0, Length() - 1)
			{
				vr_[Index + Lower()] -= Entity;
			}
			return *this;
		}

		Adt_Ary1d<T>& operator*=(const T& Entity)
		{
			forThose(Index, 0, Length() - 1)
			{
				vr_[Index + Lower()] *= Entity;
			}
			return *this;
		}

		Adt_Ary1d<T>& operator+=(const Adt_Ary1d<T>& theOther)
		{
			if (Length() NOT_EQUAL theOther.Length())
			{
				FatalErrorIn(" AutLib::ADT_Ary1d<T>& AutLib::ADT_Ary1d<T>::operator+=(const ADT_Ary1d<T>& Other)")
					<< "No match between two array sizes"
					<< abort(FatalError);
			}

			forThose(Index, 0, Length() - 1)
			{
				vr_[Index + Lower()] += theOther[Index + theOther.Lower()];
			}

			return *this;
		}

		Adt_Ary1d<T>& operator-=(const Adt_Ary1d<T>& theOther)
		{
			if (Length() NOT_EQUAL theOther.Length())
			{
				FatalErrorIn(" AutLib::ADT_Ary1d<T>& AutLib::ADT_Ary1d<T>::operator+=(const ADT_Ary1d<T>& Other)")
					<< "No match between two array sizes"
					<< abort(FatalError);
			}

			forThose(Index, 0, Length() - 1)
			{
				vr_[Index + Lower()] -= theOther[Index + theOther.Lower()];
			}

			return *this;
		}

		Adt_Ary1d<T>& operator*=(const Adt_Ary1d<T>& theOther)
		{
			if (Length() NOT_EQUAL theOther.Length())
			{
				FatalErrorIn(" AutLib::ADT_Ary1d<T>& AutLib::ADT_Ary1d<T>::operator+=(const ADT_Ary1d<T>& Other)")
					<< "No match between two array sizes"
					<< abort(FatalError);
			}

			forThose(Index, 0, Length() - 1)
			{
				vr_[Index + Lower()] *= theOther[Index + theOther.Lower()];
			}

			return *this;
		}

		Adt_Ary1d<T>& operator/=(const Adt_Ary1d<T>& theOther)
		{
			if (Length() NOT_EQUAL theOther.Length())
			{
				FatalErrorIn(" AutLib::ADT_Ary1d<T>& AutLib::ADT_Ary1d<T>::operator+=(const ADT_Ary1d<T>& Other)")
					<< "No match between two array sizes"
					<< abort(FatalError);
			}

			forThose(Index, 0, Length() - 1)
			{
				vr_[Index + Lower()] /= theOther[Index + theOther.Lower()];
			}

			return *this;
		}

		Adt_Ary1d<T>& operator+()
		{
			return *this;
		}

		Adt_Ary1d<T> operator-()
		{
			Adt_Ary1d<T> Zero(Lower(), Upper());
			Zero.Init(0);
			auto Temp = Zero - *this;
			MOVE(Temp);
		}

		iterator begin()
		{
			return &vr_[0];
		}

		const_iterator begin() const
		{
			return &vr_[0];
		}

		iterator end()
		{
			return &vr_[myUpperBound_];
		}

		const_iterator end() const
		{
			return &vr_[myUpperBound_];
		}

		const T& First() const
		{
			return vr_[myLowerBound_];
		}

		T& First()
		{
			return vr_[myLowerBound_];
		}

		const T& Last() const
		{
			return vr_[myUpperBound_];
		}

		T& Last()
		{
			return vr_[myUpperBound_];
		}

		const T& Value(const Standard_Integer Index) const
		{
			Debug_Bad_Index(Index, myLowerBound_, myUpperBound_);

			return vr_[Index];
		}

		T& Value(const Standard_Integer Index)
		{
			Debug_Bad_Index(Index, myLowerBound_, myUpperBound_);

			return vr_[Index];
		}

		const T& operator[](const Standard_Integer Index) const
		{
			Debug_Bad_Index(Index, myLowerBound_, myUpperBound_);

			return vr_[Index];
		}

		T& operator[](const Standard_Integer Index)
		{
			Debug_Bad_Index(Index, myLowerBound_, myUpperBound_);

			return vr_[Index];
		}

		const T& operator()(const Standard_Integer theIndex) const
		{
			if (NOT INSIDE(theIndex, Lower(), Upper()))
			{
				FatalErrorIn(__FUNCSIG__) 
					<< " Bad Subscript" 
					<< AutLib::abort(FatalError);
			}

			return vr_[theIndex];
		}

		T& operator()(const Standard_Integer theIndex)
		{
			if (NOT INSIDE(theIndex, Lower(), Upper()))
			{
				FatalErrorIn(__FUNCSIG__)
					<< " Bad Subscript"
					<< AutLib::abort(FatalError);
			}

			return vr_[theIndex];
		}

		Standard_Integer Size() const
		{
			return Length();
		}

		Standard_Integer Length() const
		{
			return (myUpperBound_ - myLowerBound_ + 1);
		}

		Standard_Integer Lower() const
		{
			return myLowerBound_;
		}

		Standard_Integer Upper() const
		{
			return myUpperBound_;
		}

		Standard_Boolean IsEmpty() const
		{
			return !Length();
		}

		void SetValue
		(
			const Standard_Integer theIndex,
			const T & theValue
		)
		{
			Debug_Bad_Index(theIndex, myLowerBound_, myUpperBound_);
			vr_[theIndex] = theValue;
		}

		void SetFirst(const T& theValue)
		{
			First() = theValue;
		}

		void SetLast(const T& theValue)
		{
			Last() = theValue;
		}

		void Init(const T& theValue)
		{
			*this = theValue;
		}

		void Resize(const Standard_Integer theSize)
		{
			Clear();

			myLowerBound_ = 0;
			myUpperBound_ = theSize - 1;

			T* pBegin = new T[theSize];
			vr_ = pBegin - myLowerBound_;
		}

		void DynResize(const Standard_Integer theSize)
		{
			Adt_Ary1d<T> Temp = *this;

			Clear();

			myLowerBound_ = 0;
			myUpperBound_ = theSize - 1;

			T* pBegin = new T[Length()];
			vr_ = pBegin - myLowerBound_;

			if (Length() <= Temp.Length())
			{
				forThose(Index, 0, Length() - 1)
				{
					vr_[Index + Lower()] = Temp[Index + Temp.Lower()];
				}
			}
			else
			{
				forThose(Index, 0, MaxIndexOf(Temp))
				{
					vr_[Index + Lower()] = Temp[Index + Temp.Lower()];
				}
			}
		}

		void Reverse()
		{
			Standard_Integer size = Size();
			forThose(Index, 0, Size() / 2 - 1)
			{
				std::swap(vr_[Index + Lower()], vr_[size - 1 - Index]);
			}
		}

		void Print(Standard_OStream & Output) const
		{
			forThose(Index, 0, Length() - 1)
			{
				Output << vr_[Index + Lower()] << "  ";
				if (Index % 10 IS_EQUAL 9) Output << endl;
			}
		}

		void Clear()
		{
			if (myDeletable_) delete[] & (vr_[myLowerBound_]);
			myUpperBound_ = myLowerBound_ = 0;
		}

	};


}

#include <Adt_Ary1dI.hxx>

#endif // !_Adt_Ary1d_Header
