#pragma once
#include <error.hxx>

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class T>
tnbLib::label tnbLib::UPtrList<T>::size() const
{
	return ptrs_.size();
}


template<class T>
bool tnbLib::UPtrList<T>::empty() const
{
	return ptrs_.empty();
}


template<class T>
void tnbLib::UPtrList<T>::resize(const label newSize)
{
	this->setSize(newSize);
}


template<class T>
bool tnbLib::UPtrList<T>::set(const label i) const
{
	return ptrs_[i] != NULL;
}

template<class T>
T* tnbLib::UPtrList<T>::set(const label i, T* ptr)
{
	T* old = ptrs_[i];
	ptrs_[i] = ptr;
	return old;
}

template<class T>
tnbLib::Xfer<tnbLib::UPtrList<T>> tnbLib::UPtrList<T>::xfer()
{
	return xferMove(*this);
}


// * * * * * * * * * * * * * * * Member Operators  * * * * * * * * * * * * * //

template<class T>
const T& tnbLib::UPtrList<T>::operator[](const label i) const
{
	if (!ptrs_[i])
	{
		FatalErrorIn("UPtrList::operator[] const")
			<< "hanging pointer, cannot dereference"
			<< abort(FatalError);
	}

	return *(ptrs_[i]);
}


template<class T>
T& tnbLib::UPtrList<T>::operator[](const label i)
{
	if (!ptrs_[i])
	{
		FatalErrorIn("UPtrList::operator[]")
			<< "hanging pointer, cannot dereference"
			<< abort(FatalError);
	}

	return *(ptrs_[i]);
}


template<class T>
const T* tnbLib::UPtrList<T>::operator()(const label i) const
{
	return ptrs_[i];
}


// * * * * * * * * * * * * * * * * STL iterator  * * * * * * * * * * * * * * //

template<class T>
tnbLib::UPtrList<T>::iterator::iterator(T** ptr)
	:
	ptr_(ptr)
{}

template<class T>
bool tnbLib::UPtrList<T>::iterator::operator==(const iterator& iter) const
{
	return ptr_ == iter.ptr_;
}

template<class T>
bool tnbLib::UPtrList<T>::iterator::operator!=(const iterator& iter) const
{
	return ptr_ != iter.ptr_;
}

template<class T>
T& tnbLib::UPtrList<T>::iterator::operator*()
{
	return **ptr_;
}

template<class T>
T& tnbLib::UPtrList<T>::iterator::operator()()
{
	return operator*();
}

template<class T>
typename tnbLib::UPtrList<T>::iterator
tnbLib::UPtrList<T>::iterator::operator++()
{
	++ptr_;
	return *this;
}

template<class T>
typename tnbLib::UPtrList<T>::iterator
tnbLib::UPtrList<T>::iterator::operator++(int)
{
	iterator tmp = *this;
	++ptr_;
	return tmp;
}

template<class T>
typename tnbLib::UPtrList<T>::iterator
tnbLib::UPtrList<T>::iterator::operator--()
{
	--ptr_;
	return *this;
}

template<class T>
typename tnbLib::UPtrList<T>::iterator
tnbLib::UPtrList<T>::iterator::operator--(int)
{
	iterator tmp = *this;
	--ptr_;
	return tmp;
}

template<class T>
typename tnbLib::UPtrList<T>::iterator
tnbLib::UPtrList<T>::iterator::operator+=(label n)
{
	ptr_ += n;
	return *this;
}

template<class T>
typename tnbLib::UPtrList<T>::iterator
tnbLib::operator+(const typename UPtrList<T>::iterator& iter, label n)
{
	typename UPtrList<T>::iterator tmp = iter;
	return tmp += n;
}

template<class T>
typename tnbLib::UPtrList<T>::iterator
tnbLib::operator+(label n, const typename UPtrList<T>::iterator& iter)
{
	typename UPtrList<T>::iterator tmp = iter;
	return tmp += n;
}

template<class T>
typename tnbLib::UPtrList<T>::iterator
tnbLib::UPtrList<T>::iterator::operator-=(label n)
{
	ptr_ -= n;
	return *this;
}

template<class T>
typename tnbLib::UPtrList<T>::iterator
tnbLib::operator-(const typename UPtrList<T>::iterator& iter, label n)
{
	typename UPtrList<T>::iterator tmp = iter;
	return tmp -= n;
}

template<class T>
tnbLib::label tnbLib::operator-
(
	const typename UPtrList<T>::iterator& iter1,
	const typename UPtrList<T>::iterator& iter2
	)
{
	return (iter1.ptr_ - iter2.ptr_) / sizeof(T*);
}

template<class T>
T& tnbLib::UPtrList<T>::iterator::operator[](label n)
{
	return *(*this + n);
}

template<class T>
bool tnbLib::UPtrList<T>::iterator::operator<(const iterator& iter) const
{
	return ptr_ < iter.ptr_;
}

template<class T>
bool tnbLib::UPtrList<T>::iterator::operator>(const iterator& iter) const
{
	return ptr_ > iter.ptr_;
}

template<class T>
bool tnbLib::UPtrList<T>::iterator::operator<=(const iterator& iter) const
{
	return ptr_ <= iter.ptr_;
}

template<class T>
bool tnbLib::UPtrList<T>::iterator::operator>=(const iterator& iter) const
{
	return ptr_ >= iter.ptr_;
}

template<class T>
typename tnbLib::UPtrList<T>::iterator
tnbLib::UPtrList<T>::begin()
{
	return ptrs_.begin();
}

template<class T>
typename tnbLib::UPtrList<T>::iterator
tnbLib::UPtrList<T>::end()
{
	return ptrs_.end();
}


// ************************************************************************* //

//- moved from cxx

#include <error.hxx>

// * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * * //

template<class T>
tnbLib::UPtrList<T>::UPtrList()
	:
	ptrs_()
{}


template<class T>
tnbLib::UPtrList<T>::UPtrList(const label s)
	:
	ptrs_(s, reinterpret_cast<T*>(0))
{}


template<class T>
tnbLib::UPtrList<T>::UPtrList(const Xfer<UPtrList<T> >& lst)
{
	transfer(lst());
}


template<class T>
tnbLib::UPtrList<T>::UPtrList(UPtrList<T>& a, bool reUse)
	:
	ptrs_(a.ptrs_, reUse)
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class T>
void tnbLib::UPtrList<T>::setSize(const label newSize)
{
	label oldSize = size();

	if (newSize <= 0)
	{
		clear();
	}
	else if (newSize != oldSize)
	{
		ptrs_.setSize(newSize);
	}

	if (newSize > oldSize)
	{
		// set new elements to NULL
		for (register label i = oldSize; i < newSize; i++)
		{
			ptrs_[i] = NULL;
		}
	}
}


template<class T>
void tnbLib::UPtrList<T>::clear()
{
	ptrs_.clear();
}


// Transfer the contents of the argument List into this List
// and anull the argument list
template<class T>
void tnbLib::UPtrList<T>::transfer(UPtrList<T>& a)
{
	ptrs_.transfer(a.ptrs_);
}


template<class T>
void tnbLib::UPtrList<T>::reorder(const UList<label>& oldToNew)
{
	if (oldToNew.size() != size())
	{
		FatalErrorIn("UPtrList<T>::reorder(const UList<label>&)")
			<< "Size of map (" << oldToNew.size()
			<< ") not equal to list size (" << size()
			<< ")." << abort(FatalError);
	}

	List<T*> newPtrs_(ptrs_.size(), reinterpret_cast<T*>(0));

	forAll(*this, i)
	{
		label newI = oldToNew[i];

		if (newI < 0 || newI >= size())
		{
			FatalErrorIn("UPtrList<T>::reorder(const UList<label>&)")
				<< "Illegal index " << newI << nl
				<< "Valid indices are 0.." << size() - 1
				<< abort(FatalError);
		}

		if (newPtrs_[newI])
		{
			FatalErrorIn("UPtrList<T>::reorder(const UList<label>&)")
				<< "reorder map is not unique; element " << newI
				<< " already set." << abort(FatalError);
		}
		newPtrs_[newI] = ptrs_[i];
	}

	forAll(newPtrs_, i)
	{
		if (!newPtrs_[i])
		{
			FatalErrorIn("UPtrList<T>::reorder(const UList<label>&)")
				<< "Element " << i << " not set after reordering." << nl
				<< abort(FatalError);
		}
	}

	ptrs_.transfer(newPtrs_);
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

//- moved from io.cxx

#include <Ostream.hxx>

// * * * * * * * * * * * * * * * Ostream Operators * * * * * * * * * * * * * //

template<class T>
tnbLib::Ostream& tnbLib::operator<<(Ostream& os, const UPtrList<T>& L)
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

	// Check state of IOstream
	os.check("Ostream& operator<<(Ostream&, const UPtrList&)");

	return os;
}


// ************************************************************************* //