#pragma once
#ifndef _Stl_SortedVector_Header
#define _Stl_SortedVector_Header

#include <Standard_TypeDef.hxx>
#include <Stl_Vector.hxx>
#include <error.hxx>
#include <OSstream.hxx>

#include <algorithm>

namespace AutLib
{

	template<class T>
	class Stl_SortedVector
	{

		/*Private Data*/

		Stl_Vector<T> theVector_;

		Standard_Boolean IsSorted_;

	protected:

		Standard_Boolean& Change_IsSorted()
		{
			return IsSorted_;
		}

	public:

		Stl_SortedVector()
			: IsSorted_(Standard_False)
		{}

		Stl_SortedVector
		(
			Stl_Vector<T>&& theVec,
			const Standard_Boolean Sorted
		)
			: theVector_{std::move(theVec)}
			, IsSorted_(Sorted)
		{}

		explicit Stl_SortedVector
		(
			const Standard_Integer theSize
		)
			: theVector_(theSize)
			, IsSorted_(Standard_False)
		{}

		Standard_Boolean IsSorted() const
		{
			return IsSorted_;
		}

		Standard_Boolean Check() const
		{
			for (size_t i = 1; i < theVector_.size(); i++)
			{
				if (theVector_[i] < theVector_[i - 1])
					return Standard_True;
			}
			return Standard_False;
		}

		Standard_Integer Size() const
		{
			return (Standard_Integer)theVector_.size();
		}

		Standard_Integer FindSpan(const T x) const
		{
			if (!IsSorted())
			{
				FatalErrorIn(" Standard_Integer FindSpan(const T x) const")
					<< " The vector is not sorted"
					<< abort(FatalError);
			}

			if (x < First() OR x > Last())
			{
				FatalErrorIn(" Standard_Integer FindSpan(const T x) const")
					<< " Invalid parameter; x = " << x << endl
					<< " Lower = " << First() << endl
					<< " Upper = " << Last() << endl;
			}

			auto low = (Standard_Integer)0;
			auto high = (Standard_Integer)theVector_.size() - 1;
			auto mid = (low + high) / 2;

			while (x < Value(mid) OR x >= Value(mid + 1))
			{
				if (x < Value(mid)) high = mid;
				else low = mid;
				mid = (low + high) / 2;
			}
			return mid;
		}

		const Stl_Vector<T>& Vector() const
		{
			return theVector_;
		}

		const T& Value(const Standard_Integer theIndex) const
		{
			return theVector_[theIndex];
		}

		const T& operator()(const Standard_Integer theIndex) const
		{
			return Value(theIndex);
		}

		const Stl_Vector<T>& operator()() const
		{
			return Vector();
		}

		const T& First() const
		{
			return theVector_[0];
		}

		const T& Last() const
		{
			return theVector_[theVector_.size() - 1];
		}

		T& Value(const Standard_Integer theIndex)
		{
			if (IsSorted()) Change_IsSorted() = Standard_False;
			return theVector_[theIndex];
		}

		Stl_Vector<T>& Vector()
		{
			Change_IsSorted() = Standard_False;
			return theVector_;
		}

		void Sort()
		{
			std::sort(theVector_.begin(), theVector_.end());
			Change_IsSorted() = Standard_True;
		}


	};
}

#endif // !_Stl_SortedVector_Header
