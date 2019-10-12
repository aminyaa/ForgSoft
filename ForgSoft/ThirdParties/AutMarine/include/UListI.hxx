#pragma once
#include <error.hxx>
#include <OSstream.hxx>
#include <bool.hxx>
#include <contiguous.hxx>
#include <token.hxx>
template<class T>
const AutLib::UList<T> AutLib::UList<T>::zero;

template<class T>
inline AutLib::UList<T>::UList()
	: v_(0)
	, size_(0)
{}


template<class T>
inline AutLib::UList<T>::UList(T* v, label size)
	: v_(v)
	, size_(size)
{}

template<class T>
inline const AutLib::UList<T>& AutLib::UList<T>::null()
{
	return zero;
}


// Reset in slicing.  HJ. 19/Oct/2008
template<class T>
inline void AutLib::UList<T>::reset(T* v, label size)
{
	v_ = v;
	size_ = size;
}


template<class T>
inline AutLib::label AutLib::UList<T>::fcIndex(const label i) const
{
	return (i == size() - 1 ? 0 : i + 1);
}


template<class T>
inline AutLib::label AutLib::UList<T>::rcIndex(const label i) const
{
	return (i ? i - 1 : size() - 1);
}

template<class T>
AutLib::label AutLib::UList<T>::byteSize() const
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

// Check start is within valid range (0 ... size-1).
template<class T>
inline void AutLib::UList<T>::checkStart(const label start) const
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
inline void AutLib::UList<T>::checkSize(const label size) const
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
inline void AutLib::UList<T>::checkIndex(const label i) const
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
void AutLib::UList<T>::writeEntry(Ostream& os) const
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
void AutLib::UList<T>::writeEntry(const word& keyword, Ostream& os) const
{
	os.writeKeyword(keyword);
	writeEntry(os);
	os << token::END_STATEMENT << endl;
}

template<class T>
void AutLib::UList<T>::assign(const UList<T>& a)
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
			T* vp = ((*this)).begin();
			const T* ap = (a).begin();
			label i = ((*this)).size(); while (i--) {
				(*vp++) = (*ap++);
			}
		}
	}
}

template<class T>
inline T& AutLib::UList<T>::first()
{
	return this->operator[](0);
}


template<class T>
inline const T& AutLib::UList<T>::first() const
{
	return this->operator[](0);
}


template<class T>
inline T& AutLib::UList<T>::last()
{
	return this->operator[](this->size() - 1);
}


template<class T>
inline const T& AutLib::UList<T>::last() const
{
	return this->operator[](this->size() - 1);
}


template<class T>
inline const T* AutLib::UList<T>::cdata() const
{
	return v_;
}


template<class T>
inline T* AutLib::UList<T>::data()
{
	return v_;
}

// element access
template<class T>
inline T& AutLib::UList<T>::operator[](const label i)
{
#   ifdef FULLDEBUG
	checkIndex(i);
#   endif
	return v_[i];
}


namespace AutLib
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

} // end of namespace AutLib

 // const element access
template<class T>
inline const T& AutLib::UList<T>::operator[](const label i) const
{
#   ifdef FULLDEBUG
	checkIndex(i);
#   endif
	return v_[i];
}

template<class T>
void AutLib::UList<T>::operator=(const T& t)
{
	T* vp = ((*this)).begin();
	label i = ((*this)).size(); while (i--) {
		(*vp++) = t;
	}
}

// Allow cast to a const List<T>&
//template<class T>
//inline AutLib::UList<T>::operator const AutLib::List<T>&() const
//{
//	return *reinterpret_cast<const List<T>*>(this);
//}

template<class T>
inline const AutLib::List<T>& AutLib::UList<T>::castToList() const
{
	return *reinterpret_cast<const List<T>*>(this);
}

template<class T>
inline typename AutLib::UList<T>::iterator
AutLib::UList<T>::begin()
{
	return v_;
}

template<class T>
inline typename AutLib::UList<T>::const_iterator
AutLib::UList<T>::begin() const
{
	return v_;
}

template<class T>
inline typename AutLib::UList<T>::const_iterator
AutLib::UList<T>::cbegin() const
{
	return v_;
}

template<class T>
inline typename AutLib::UList<T>::iterator
AutLib::UList<T>::end()
{
	return &v_[size_];
}

template<class T>
inline typename AutLib::UList<T>::const_iterator
AutLib::UList<T>::end() const
{
	return &v_[size_];
}

template<class T>
inline typename AutLib::UList<T>::const_iterator
AutLib::UList<T>::cend() const
{
	return &v_[size_];
}

template<class T>
inline typename AutLib::UList<T>::iterator
AutLib::UList<T>::rbegin()
{
	return &v_[size_ - 1];
}

template<class T>
inline typename AutLib::UList<T>::const_iterator
AutLib::UList<T>::rbegin() const
{
	return &v_[size_ - 1];
}

template<class T>
inline typename AutLib::UList<T>::const_iterator
AutLib::UList<T>::crbegin() const
{
	return &v_[size_ - 1];
}

template<class T>
inline typename AutLib::UList<T>::iterator
AutLib::UList<T>::rend()
{
	return &v_[-1];
}

template<class T>
inline typename AutLib::UList<T>::const_iterator
AutLib::UList<T>::rend() const
{
	return &v_[-1];
}

template<class T>
inline typename AutLib::UList<T>::const_iterator
AutLib::UList<T>::crend() const
{
	return &v_[-1];
}

template<class T>
inline AutLib::label AutLib::UList<T>::size() const
{
	return size_;
}


template<class T>
inline AutLib::label AutLib::UList<T>::max_size() const
{
	return labelMax;
}


template<class T>
inline bool AutLib::UList<T>::empty() const
{
	return !size_;
}

template<class T>
void AutLib::UList<T>::swap(UList<T>& a)
{
	if (a.size_ != this->size_)
	{
		FatalErrorIn("UList<T>::swap(const UList<T>&)")
			<< "ULists have different sizes: "
			<< this->size_ << " " << a.size_
			<< abort(FatalError);
	}

	T* vp = ((*this)).begin();
	T* ap = (a).begin();
	T tmp;
	label i = ((*this)).size(); while (i--) {
		tmp = (*vp++);
		(*vp++) = (*ap++);
		(*ap++) = tmp;
	}
}

template<class T>
bool AutLib::UList<T>::operator==(const UList<T>& a) const
{
	if (this->size_ != a.size_)
	{
		return false;
	}

	bool equal = true;

	register const T* vp = ((*this)).begin();
	register const T* ap = ((a)).begin();

	register label i = ((*this)).size(); while (i--) {
		equal = equal && ((*vp++) == (*ap++));
	}

	return equal;
}


template<class T>
bool AutLib::UList<T>::operator!=(const UList<T>& a) const
{
	return !operator==(a);
}


template<class T>
bool AutLib::UList<T>::operator<(const UList<T>& a) const
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
bool AutLib::UList<T>::operator>(const UList<T>& a) const
{
	return a.operator<(*this);
}


template<class T>
bool AutLib::UList<T>::operator<=(const UList<T>& a) const
{
	return !operator>(a);
}


template<class T>
bool AutLib::UList<T>::operator>=(const UList<T>& a) const
{
	return !operator<(a);
}

namespace AutLib
{
	template<class T>
	Ostream & operator<<(Ostream & os, const UList<T>& L)
	{

		if (os.format() == IOstream::ASCII || !contiguous<T>())
		{
			bool uniform = false;

			if (L.size() > 1 && contiguous<T>())
			{
				uniform = true;

				for (AutLib::label i = 0; i < (L).size(); i++)
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
				for (label i = 0; i < (L).size(); i++)
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
				for (label i = 0; i < (L).size(); i++)
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
}

template<class T>
inline void AutLib::reverse(UList<T>& ul, const label n)
{
	for (int i = 0; i < n / 2; i++)
	{
		Swap(ul[i], ul[n - 1 - i]);
	}
}

template<class T>
inline void AutLib::reverse(UList<T>& ul)
{
	reverse(ul, ul.size());
}