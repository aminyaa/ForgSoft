#pragma once
template<class T>
AutLib::UPtrList<T>::UPtrList()
	:ptrs_()
{
}


template<class T>
AutLib::UPtrList<T>::UPtrList(const label s)
	: ptrs_(s, reinterpret_cast<T*>(0))
{}


template<class T>
AutLib::UPtrList<T>::UPtrList(const Xfer<UPtrList<T> >& lst)
{
	transfer(lst());
}


template<class T>
AutLib::UPtrList<T>::UPtrList(UPtrList<T>& a, bool reUse)
	: ptrs_(a.ptrs_, reUse)
{}

template<class T>
void AutLib::UPtrList<T>::setSize(const label newSize)
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
void AutLib::UPtrList<T>::clear()
{
	ptrs_.clear();
}


// Transfer the contents of the argument List into this List
// and anull the argument list
template<class T>
void AutLib::UPtrList<T>::transfer(UPtrList<T>& a)
{
	ptrs_.transfer(a.ptrs_);
}


template<class T>
void AutLib::UPtrList<T>::reorder(const UList<label>& oldToNew)
{
	if (oldToNew.size() != size())
	{
		FatalErrorIn("UPtrList<T>::reorder(const UList<label>&)")
			<< "Size of map (" << oldToNew.size()
			<< ") not equal to list size (" << size()
			<< ")." << abort(FatalError);
	}

	List<T*> newPtrs_(ptrs_.size(), reinterpret_cast<T*>(0));

	for (label i = 0; i < (*this).size(); i++)
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

	for (label i = 0; i < (newPtrs_).size(); i++)
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

template<class T>
inline AutLib::label AutLib::UPtrList<T>::size() const
{
	return ptrs_.size();
}


template<class T>
inline bool AutLib::UPtrList<T>::empty() const
{
	return ptrs_.empty();
}


template<class T>
inline void AutLib::UPtrList<T>::resize(const label newSize)
{
	this->setSize(newSize);
}


template<class T>
inline bool AutLib::UPtrList<T>::set(const label i) const
{
	return ptrs_[i] != NULL;
}

template<class T>
inline T* AutLib::UPtrList<T>::set(const label i, T* ptr)
{
	T* old = ptrs_[i];
	ptrs_[i] = ptr;
	return old;
}

template<class T>
inline AutLib::Xfer<AutLib::UPtrList<T> > AutLib::UPtrList<T>::xfer()
{
	return xferMove(*this);
}

template<class T>
const T& AutLib::UPtrList<T>::operator[](const label i) const
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
T& AutLib::UPtrList<T>::operator[](const label i)
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
const T* AutLib::UPtrList<T>::operator()(const label i) const
{
	return ptrs_[i];
}

template<class T>
inline AutLib::UPtrList<T>::iterator::iterator(T** ptr)
	:
	ptr_(ptr)
{
}

template<class T>
inline bool AutLib::UPtrList<T>::iterator::operator==(const iterator& iter) const
{
	return ptr_ == iter.ptr_;
}

template<class T>
inline bool AutLib::UPtrList<T>::iterator::operator!=(const iterator& iter) const
{
	return ptr_ != iter.ptr_;
}

template<class T>
inline T& AutLib::UPtrList<T>::iterator::operator*()
{
	return **ptr_;
}

template<class T>
inline T& AutLib::UPtrList<T>::iterator::operator()()
{
	return operator*();
}

template<class T>
inline typename AutLib::UPtrList<T>::iterator
AutLib::UPtrList<T>::iterator::operator++()
{
	++ptr_;
	return *this;
}

template<class T>
inline typename AutLib::UPtrList<T>::iterator
AutLib::UPtrList<T>::iterator::operator++(int)
{
	iterator tmp = *this;
	++ptr_;
	return tmp;
}

template<class T>
inline typename AutLib::UPtrList<T>::iterator
AutLib::UPtrList<T>::iterator::operator--()
{
	--ptr_;
	return *this;
}

template<class T>
inline typename AutLib::UPtrList<T>::iterator
AutLib::UPtrList<T>::iterator::operator--(int)
{
	iterator tmp = *this;
	--ptr_;
	return tmp;
}

template<class T>
inline typename AutLib::UPtrList<T>::iterator
AutLib::UPtrList<T>::iterator::operator+=(label n)
{
	ptr_ += n;
	return *this;
}

namespace AutLib
{
	template<class T>
	inline typename UPtrList<T>::iterator operator+(const typename UPtrList<T>::iterator& iter, label n)
	{
		typename UPtrList<T>::iterator tmp = iter;
		return tmp += n;
	}

	template<class T>
	inline typename UPtrList<T>::iterator operator+(label n, const typename UPtrList<T>::iterator& iter)
	{
		typename UPtrList<T>::iterator tmp = iter;
		return tmp += n;
	}

	template<class T>
	inline typename UPtrList<T>::iterator UPtrList<T>::iterator::operator-=(label n)
	{
		ptr_ -= n;
		return *this;
	}

	template<class T>
	inline typename UPtrList<T>::iterator operator-(const typename UPtrList<T>::iterator& iter, label n)
	{
		typename UPtrList<T>::iterator tmp = iter;
		return tmp -= n;
	}

	template<class T>
	inline label operator-(const typename UPtrList<T>::iterator& iter1, const typename UPtrList<T>::iterator& iter2)
	{
		return (iter1.ptr_ - iter2.ptr_) / sizeof(T*);
	}
}

template<class T>
inline T& AutLib::UPtrList<T>::iterator::operator[](label n)
{
	return *(*this + n);
}

template<class T>
inline bool AutLib::UPtrList<T>::iterator::operator<(const iterator& iter) const
{
	return ptr_ < iter.ptr_;
}

template<class T>
inline bool AutLib::UPtrList<T>::iterator::operator>(const iterator& iter) const
{
	return ptr_ > iter.ptr_;
}

template<class T>
inline bool AutLib::UPtrList<T>::iterator::operator<=(const iterator& iter) const
{
	return ptr_ <= iter.ptr_;
}

template<class T>
inline bool AutLib::UPtrList<T>::iterator::operator>=(const iterator& iter) const
{
	return ptr_ >= iter.ptr_;
}

template<class T>
inline typename AutLib::UPtrList<T>::iterator
AutLib::UPtrList<T>::begin()
{
	return ptrs_.begin();
}

template<class T>
inline typename AutLib::UPtrList<T>::iterator
AutLib::UPtrList<T>::end()
{
	return ptrs_.end();
}

namespace AutLib
{
	template<class T>
	AutLib::Ostream& operator<<(Ostream& os, const UPtrList<T>& L)
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

		// Check state of IOstream
		os.check("Ostream& operator<<(Ostream&, const UPtrList&)");

		return os;
	}
}