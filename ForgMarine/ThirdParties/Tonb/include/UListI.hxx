#pragma once
#include <pTraits.hxx>
#include <Swap.hxx>
#include <error.hxx>
#include <OSstream.hxx>

// * * * * * * * * * * * * * * * Static Members  * * * * * * * * * * * * * * //

template<class T>
const tnbLib::UList<T> tnbLib::UList<T>::zero;


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class T>
inline tnbLib::UList<T>::UList()
	:
	v_(0),
	size_(0)
{}


template<class T>
inline tnbLib::UList<T>::UList(T* __restrict v, label size)
	:
	v_(v),
	size_(size)
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class T>
inline const tnbLib::UList<T>& tnbLib::UList<T>::null()
{
	return zero;
}


// Reset in slicing.  HJ. 19/Oct/2008
template<class T>
inline void tnbLib::UList<T>::reset(T* __restrict v, label size)
{
	v_ = v;
	size_ = size;
}


template<class T>
inline tnbLib::label tnbLib::UList<T>::fcIndex(const label i) const
{
	return (i == size() - 1 ? 0 : i + 1);
}


template<class T>
inline tnbLib::label tnbLib::UList<T>::rcIndex(const label i) const
{
	return (i ? i - 1 : size() - 1);
}


// Check start is within valid range (0 ... size-1).
template<class T>
inline void tnbLib::UList<T>::checkStart(const label start) const
{
	if (start < 0 || (start && start >= size_))
	{
		FatalErrorIn("UList<T>::checkStart(const label)")
			<< "start " << start << " out of range 0 ... " << max(size_ - 1, 0)
			<< abort(FatalError);
	}
}


// Check size is within valid range (0 ... size).
template<class T>
inline void tnbLib::UList<T>::checkSize(const label size) const
{
	if (size<0 || size>size_)
	{
		FatalErrorIn("UList<T>::checkSize(const label)")
			<< "size " << size << " out of range 0 ... " << size_
			<< abort(FatalError);
	}
}


// Check index i is within valid range (0 ... size-1).
template<class T>
inline void tnbLib::UList<T>::checkIndex(const label i) const
{
	if (!size_)
	{
		FatalErrorIn("UList<T>::checkIndex(const label)")
			<< "attempt to access element from zero sized list"
			<< abort(FatalError);
	}
	else if (i < 0 || i >= size_)
	{
		FatalErrorIn("UList<T>::checkIndex(const label)")
			<< "index " << i << " out of range 0 ... " << size_ - 1
			<< abort(FatalError);
	}
}


template<class T>
inline T& tnbLib::UList<T>::first()
{
	return this->operator[](0);
}


template<class T>
inline const T& tnbLib::UList<T>::first() const
{
	return this->operator[](0);
}


template<class T>
inline T& tnbLib::UList<T>::last()
{
	return this->operator[](this->size() - 1);
}


template<class T>
inline const T& tnbLib::UList<T>::last() const
{
	return this->operator[](this->size() - 1);
}


template<class T>
inline const T* tnbLib::UList<T>::cdata() const
{
	return v_;
}


template<class T>
inline T* tnbLib::UList<T>::data()
{
	return v_;
}


// * * * * * * * * * * * * * * * Member Operators  * * * * * * * * * * * * * //


// element access
template<class T>
inline T& tnbLib::UList<T>::operator[](const label i)
{
#   ifdef FULLDEBUG
	checkIndex(i);
#   endif
	return v_[i];
}


namespace tnbLib
{

	// Template specialization for bool
	template<>
	inline const bool& UList<bool>::operator[](const label i) const
	{
		// lazy evaluation - return false for out-of-range
		if (i < size_)
		{
			return v_[i];
		}
		else
		{
			return pTraits<bool>::zero;
		}
	}

} // end of namespace tnbLib


// const element access
template<class T>
inline const T& tnbLib::UList<T>::operator[](const label i) const
{
#   ifdef FULLDEBUG
	checkIndex(i);
#   endif
	return v_[i];
}


// Allow cast to a const List<T>&
template<class T>
inline tnbLib::UList<T>::operator const tnbLib::List<T>&() const
{
	return *reinterpret_cast<const List<T>*>(this);
}


// * * * * * * * * * * * * * * STL Member Functions  * * * * * * * * * * * * //

template<class T>
inline typename tnbLib::UList<T>::iterator
tnbLib::UList<T>::begin()
{
	return v_;
}

template<class T>
inline typename tnbLib::UList<T>::const_iterator
tnbLib::UList<T>::begin() const
{
	return v_;
}

template<class T>
inline typename tnbLib::UList<T>::const_iterator
tnbLib::UList<T>::cbegin() const
{
	return v_;
}

template<class T>
inline typename tnbLib::UList<T>::iterator
tnbLib::UList<T>::end()
{
	return &v_[size_];
}

template<class T>
inline typename tnbLib::UList<T>::const_iterator
tnbLib::UList<T>::end() const
{
	return &v_[size_];
}

template<class T>
inline typename tnbLib::UList<T>::const_iterator
tnbLib::UList<T>::cend() const
{
	return &v_[size_];
}

template<class T>
inline typename tnbLib::UList<T>::iterator
tnbLib::UList<T>::rbegin()
{
	return &v_[size_ - 1];
}

template<class T>
inline typename tnbLib::UList<T>::const_iterator
tnbLib::UList<T>::rbegin() const
{
	return &v_[size_ - 1];
}

template<class T>
inline typename tnbLib::UList<T>::const_iterator
tnbLib::UList<T>::crbegin() const
{
	return &v_[size_ - 1];
}

template<class T>
inline typename tnbLib::UList<T>::iterator
tnbLib::UList<T>::rend()
{
	return &v_[-1];
}

template<class T>
inline typename tnbLib::UList<T>::const_iterator
tnbLib::UList<T>::rend() const
{
	return &v_[-1];
}

template<class T>
inline typename tnbLib::UList<T>::const_iterator
tnbLib::UList<T>::crend() const
{
	return &v_[-1];
}

template<class T>
inline tnbLib::label tnbLib::UList<T>::size() const
{
	return size_;
}


template<class T>
inline tnbLib::label tnbLib::UList<T>::max_size() const
{
	return labelMax;
}


template<class T>
inline bool tnbLib::UList<T>::empty() const
{
	return !size_;
}


// * * * * * * * * * * * * * * * Global Functions  * * * * * * * * * * * * * //

template<class T>
inline void tnbLib::reverse(UList<T>& ul, const label n)
{
	for (int i = 0; i < n / 2; i++)
	{
		Swap(ul[i], ul[n - 1 - i]);
	}
}

template<class T>
inline void tnbLib::reverse(UList<T>& ul)
{
	reverse(ul, ul.size());
}


// ************************************************************************* //

//- Moved from cxx

#include <ListLoopM.hxx>
#include <error.hxx>
#include <contiguous.hxx>

#include <algorithm>

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class T>
void tnbLib::UList<T>::assign(const UList<T>& a)
{
	if (a.size_ != this->size_)
	{
		FatalErrorIn("UList<T>::assign(const UList<T>&)")
			<< "ULists have different sizes: "
			<< this->size_ << " " << a.size_
			<< abort(FatalError);
	}

	if (this->size_)
	{
#       ifdef USEMEMCPY
		if (contiguous<T>())
		{
			memcpy(this->v_, a.v_, this->byteSize());
		}
		else
#       endif
		{
			List_ACCESS(T, (*this), vp);
			List_CONST_ACCESS(T, a, ap);
			List_FOR_ALL((*this), i)
				List_ELEM((*this), vp, i) = List_ELEM(a, ap, i);
			List_END_FOR_ALL
		}
	}
}


// * * * * * * * * * * * * * * * Member Operators  * * * * * * * * * * * * * //

template<class T>
void tnbLib::UList<T>::operator=(const T& t)
{
	List_ACCESS(T, (*this), vp);
	List_FOR_ALL((*this), i)
		List_ELEM((*this), vp, i) = t;
	List_END_FOR_ALL
}


// * * * * * * * * * * * * * * STL Member Functions  * * * * * * * * * * * * //

template<class T>
void tnbLib::UList<T>::swap(UList<T>& a)
{
	if (a.size_ != this->size_)
	{
		FatalErrorIn("UList<T>::swap(const UList<T>&)")
			<< "ULists have different sizes: "
			<< this->size_ << " " << a.size_
			<< abort(FatalError);
	}

	List_ACCESS(T, (*this), vp);
	List_ACCESS(T, a, ap);
	T tmp;
	List_FOR_ALL((*this), i)
		tmp = List_ELEM((*this), vp, i);
	List_ELEM((*this), vp, i) = List_ELEM(a, ap, i);
	List_ELEM(a, ap, i) = tmp;
	List_END_FOR_ALL
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class T>
tnbLib::label tnbLib::UList<T>::byteSize() const
{
	if (!contiguous<T>())
	{
		FatalErrorIn("UList<T>::byteSize()")
			<< "Cannot return the binary size of a list of "
			"non-primitive elements"
			<< abort(FatalError);
	}

	return this->size_ * sizeof(T);
}


template<class T>
void tnbLib::sort(UList<T>& a)
{
	std::sort(a.begin(), a.end());
}


template<class T, class Cmp>
void tnbLib::sort(UList<T>& a, const Cmp& cmp)
{
	std::sort(a.begin(), a.end(), cmp);
}


template<class T>
void tnbLib::stableSort(UList<T>& a)
{
	std::stable_sort(a.begin(), a.end());
}


template<class T, class Cmp>
void tnbLib::stableSort(UList<T>& a, const Cmp& cmp)
{
	std::stable_sort(a.begin(), a.end(), cmp);
}


// * * * * * * * * * * * * * * * Member Operators  * * * * * * * * * * * * * //

template<class T>
bool tnbLib::UList<T>::operator==(const UList<T>& a) const
{
	if (this->size_ != a.size_)
	{
		return false;
	}

	bool equal = true;

	List_CONST_ACCESS(T, (*this), vp);
	List_CONST_ACCESS(T, (a), ap);

	List_FOR_ALL((*this), i)
		equal = equal && (List_ELEM((*this), vp, i) == List_ELEM((a), ap, i));
	List_END_FOR_ALL

		return equal;
}


template<class T>
bool tnbLib::UList<T>::operator!=(const UList<T>& a) const
{
	return !operator==(a);
}


template<class T>
bool tnbLib::UList<T>::operator<(const UList<T>& a) const
{
	for
		(
			const_iterator vi = begin(), ai = a.begin();
			vi < end() && ai < a.end();
			vi++, ai++
			)
	{
		if (*vi < *ai)
		{
			return true;
		}
		else if (*vi > *ai)
		{
			return false;
		}
	}

	if (this->size_ < a.size_)
	{
		return true;
	}
	else
	{
		return false;
	}
}


template<class T>
bool tnbLib::UList<T>::operator>(const UList<T>& a) const
{
	return a.operator<(*this);
}


template<class T>
bool tnbLib::UList<T>::operator<=(const UList<T>& a) const
{
	return !operator>(a);
}


template<class T>
bool tnbLib::UList<T>::operator>=(const UList<T>& a) const
{
	return !operator<(a);
}


// * * * * * * * * * * * * * * * *  IOStream operators * * * * * * * * * * * //

//- moved from io.cxx

#include <Ostream.hxx>
#include <token.hxx>
#include <contiguous.hxx>

// * * * * * * * * * * * * * * * Ostream Operator *  * * * * * * * * * * * * //

template<class T>
void tnbLib::UList<T>::writeEntry(Ostream& os) const
{
	if
		(
			size()
			&& token::compound::isCompound
			(
				"List<" + word(pTraits<T>::typeName) + '>'
			)
			)
	{
		os << word("List<" + word(pTraits<T>::typeName) + '>') << " ";
	}

	os << *this;
}


template<class T>
void tnbLib::UList<T>::writeEntry(const word& keyword, Ostream& os) const
{
	os.writeKeyword(keyword);
	writeEntry(os);
	os << token::END_STATEMENT << endl;
}


template<class T>
tnbLib::Ostream& tnbLib::operator<<(tnbLib::Ostream& os, const tnbLib::UList<T>& L)
{
	// Write list contents depending on data format
	if (os.format() == IOstream::ASCII || !contiguous<T>())
	{
		bool uniform = false;

		if (L.size() > 1 && contiguous<T>())
		{
			uniform = true;

			forAll(L, i)
			{
				if (L[i] != L[0])
				{
					uniform = false;
					break;
				}
			}
		}

		if (uniform)
		{
			// Write size and start delimiter
			os << L.size() << token::BEGIN_BLOCK;

			// Write contents
			os << L[0];

			// Write end delimiter
			os << token::END_BLOCK;
		}
		else if (L.size() < 11 && contiguous<T>())
		{
			// Write size and start delimiter
			os << L.size() << token::BEGIN_LIST;

			// Write contents
			forAll(L, i)
			{
				if (i > 0) os << token::SPACE;
				os << L[i];
			}

			// Write end delimiter
			os << token::END_LIST;
		}
		else
		{
			// Write size and start delimiter
			os << nl << L.size() << nl << token::BEGIN_LIST;

			// Write contents
			forAll(L, i)
			{
				os << nl << L[i];
			}

			// Write end delimiter
			os << nl << token::END_LIST << nl;
		}
	}
	else
	{
		os << nl << L.size() << nl;
		if (L.size())
		{
			os.write(reinterpret_cast<const char*>(L.v_), L.byteSize());
		}
	}

	// Check state of IOstream
	os.check("Ostream& operator<<(Ostream&, const UList&)");

	return os;
}


// ************************************************************************* //