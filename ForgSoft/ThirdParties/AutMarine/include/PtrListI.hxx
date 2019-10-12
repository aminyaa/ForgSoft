#pragma once
//#include <SLPtrList.hxx>
#include <INew.hxx>
template<class T>
AutLib::PtrList<T>::PtrList()
	: ptrs_()
{}


template<class T>
AutLib::PtrList<T>::PtrList(const label s)
	: ptrs_(s, reinterpret_cast<T*>(0))
{}

template<class T>
AutLib::PtrList<T>::PtrList(const PtrList<T>& a)
	: ptrs_(a.size())
{
	for (label i = 0; i < (*this).size(); i++)
	{
		ptrs_[i] = (a[i]).clone().ptr();
	}
}


template<class T>
template<class CloneArg>
AutLib::PtrList<T>::PtrList(const PtrList<T>& a, const CloneArg& cloneArg)
	: ptrs_(a.size())
{
	for (label i = 0; i < (*this).size(); i++)
	{
		ptrs_[i] = (a[i]).clone(cloneArg).ptr();
	}
}


template<class T>
AutLib::PtrList<T>::PtrList(const Xfer<PtrList<T> >& lst)
{
	transfer(lst());
}


template<class T>
AutLib::PtrList<T>::PtrList(PtrList<T>& a, bool reUse)
	: ptrs_(a.size())
{
	if (reUse)
	{
		for (label i = 0; i < (*this).size(); i++)
		{
			ptrs_[i] = a.ptrs_[i];
			a.ptrs_[i] = NULL;
		}
		a.setSize(0);
	}
	else
	{
		for (label i = 0; i < (*this).size(); i++)
		{
			ptrs_[i] = (a[i]).clone().ptr();
		}
	}
}


//template<class T>
//AutLib::PtrList<T>::PtrList(const SLPtrList<T>& sll)
//	:
//	ptrs_(sll.size())
//{
//	if (sll.size())
//	{
//		label i = 0;
//		for
//			(
//				typename SLPtrList<T>::const_iterator iter = sll.begin();
//				iter != sll.end();
//				++iter
//				)
//		{
//			ptrs_[i++] = (iter()).clone().ptr();
//		}
//	}
//}

template<class T>
AutLib::PtrList<T>::~PtrList()
{
	for (label i = 0; i < (*this).size(); i++)
	{
		if (ptrs_[i])
		{
			delete ptrs_[i];
		}
	}
}

template<class T>
void AutLib::PtrList<T>::setSize(const label newSize)
{
	if (newSize < 0)
	{
		FatalErrorIn("PtrList<T>::setSize(const label)")
			<< "bad set size " << newSize
			<< abort(FatalError);
	}

	label oldSize = size();

	if (newSize == 0)
	{
		clear();
	}
	else if (newSize < oldSize)
	{
		register label i;
		for (i = newSize; i < oldSize; i++)
		{
			if (ptrs_[i])
			{
				delete ptrs_[i];
			}
		}

		ptrs_.setSize(newSize);
	}
	else // newSize > oldSize
	{
		ptrs_.setSize(newSize);

		register label i;
		for (i = oldSize; i < newSize; i++)
		{
			ptrs_[i] = NULL;
		}
	}
}

template<class T>
void AutLib::PtrList<T>::clear()
{
	for (AutLib::label i = 0; i < (*this).size(); i++)
	{
		if (ptrs_[i])
		{
			delete ptrs_[i];
		}
	}

	ptrs_.clear();
}


template<class T>
void AutLib::PtrList<T>::transfer(PtrList<T>& a)
{
	clear();
	ptrs_.transfer(a.ptrs_);
}

template<class T>
void AutLib::PtrList<T>::reorder(const UList<label>& oldToNew)
{
	if (oldToNew.size() != size())
	{
		FatalErrorIn("PtrList<T>::reorder(const UList<label>&)")
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
			FatalErrorIn("PtrList<T>::reorder(const UList<label>&)")
				<< "Illegal index " << newI << nl
				<< "Valid indices are 0.." << size() - 1
				<< abort(FatalError);
		}

		if (newPtrs_[newI])
		{
			FatalErrorIn("PtrList<T>::reorder(const UList<label>&)")
				<< "reorder map is not unique; element " << newI
				<< " already set." << abort(FatalError);
		}
		newPtrs_[newI] = ptrs_[i];
	}

	for (label i = 0; i < (newPtrs_).size(); i++)
	{
		if (!newPtrs_[i])
		{
			FatalErrorIn("PtrList<T>::reorder(const UList<label>&)")
				<< "Element " << i << " not set after reordering." << nl
				<< abort(FatalError);
		}
	}

	ptrs_.transfer(newPtrs_);
}

template<class T>
AutLib::PtrList<T>& AutLib::PtrList<T>::operator=(const PtrList<T>& a)
{
	if (this == &a)
	{
		FatalErrorIn("PtrList<T>::operator=(const PtrList<T>&)")
			<< "attempted assignment to self"
			<< abort(FatalError);
	}

	if (size() == 0)
	{
		setSize(a.size());

		for (label i = 0; i < (*this).size(); i++)
		{
			ptrs_[i] = (a[i]).clone().ptr();
		}
	}
	else if (a.size() == size())
	{
		for (label i = 0; i < (*this).size(); i++)
		{
			(*this)[i] = a[i];
		}
	}
	else
	{
		FatalErrorIn("PtrList::operator=(const PtrList<T>&)")
			<< "bad size: " << a.size()
			<< abort(FatalError);
	}


	return *this;
}


template<class T>
inline AutLib::label AutLib::PtrList<T>::size() const
{
	return ptrs_.size();
}


template<class T>
inline bool AutLib::PtrList<T>::empty() const
{
	return ptrs_.empty();
}


template<class T>
inline void AutLib::PtrList<T>::resize(const label newSize)
{
	this->setSize(newSize);
}


template<class T>
inline bool AutLib::PtrList<T>::set(const label i) const
{
	return ptrs_[i] != NULL;
}


template<class T>
inline AutLib::autoPtr<T> AutLib::PtrList<T>::set(const label i, T* ptr)
{
	autoPtr<T> old(ptrs_[i]);

	ptrs_[i] = ptr;

	return old;
}


template<class T>
inline AutLib::autoPtr<T> AutLib::PtrList<T>::set
(
	const label i,
	const autoPtr<T>& aptr
)
{
	return set(i, const_cast<autoPtr<T>&>(aptr).ptr());
}


template<class T>
inline AutLib::autoPtr<T> AutLib::PtrList<T>::set
(
	const label i,
	const tmp<T>& t
)
{
	return set(i, const_cast<tmp<T>&>(t).ptr());
}


template<class T>
inline AutLib::Xfer<AutLib::PtrList<T> > AutLib::PtrList<T>::xfer()
{
	return xferMove(*this);
}

template<class T>
const T& AutLib::PtrList<T>::operator[](const label i) const
{
	if (!ptrs_[i])
	{
		FatalErrorIn("PtrList::operator[] const")
			<< "hanging pointer, cannot dereference"
			<< abort(FatalError);
	}

	return *(ptrs_[i]);
}


template<class T>
T& AutLib::PtrList<T>::operator[](const label i)
{
	if (!ptrs_[i])
	{
		FatalErrorIn("PtrList::operator[]")
			<< "hanging pointer, cannot dereference"
			<< abort(FatalError);
	}

	return *(ptrs_[i]);
}


template<class T>
const T* AutLib::PtrList<T>::operator()(const label i) const
{
	return ptrs_[i];
}

template<class T>
inline AutLib::PtrList<T>::iterator::iterator(T** ptr)
	:
	ptr_(ptr)
{
}

template<class T>
inline bool AutLib::PtrList<T>::iterator::operator==(const iterator& iter) const
{
	return ptr_ == iter.ptr_;
}

template<class T>
inline bool AutLib::PtrList<T>::iterator::operator!=(const iterator& iter) const
{
	return ptr_ != iter.ptr_;
}

template<class T>
inline T& AutLib::PtrList<T>::iterator::operator*()
{
	return **ptr_;
}

template<class T>
inline T& AutLib::PtrList<T>::iterator::operator()()
{
	return operator*();
}

template<class T>
inline typename AutLib::PtrList<T>::iterator
AutLib::PtrList<T>::iterator::operator++()
{
	++ptr_;
	return *this;
}

template<class T>
inline typename AutLib::PtrList<T>::iterator
AutLib::PtrList<T>::iterator::operator++(int)
{
	iterator tmp = *this;
	++ptr_;
	return tmp;
}

template<class T>
inline typename AutLib::PtrList<T>::iterator
AutLib::PtrList<T>::iterator::operator--()
{
	--ptr_;
	return *this;
}

template<class T>
inline typename AutLib::PtrList<T>::iterator
AutLib::PtrList<T>::iterator::operator--(int)
{
	iterator tmp = *this;
	--ptr_;
	return tmp;
}

template<class T>
inline typename AutLib::PtrList<T>::iterator
AutLib::PtrList<T>::iterator::operator+=(label n)
{
	ptr_ += n;
	return *this;
}

template<class T>
inline T& AutLib::PtrList<T>::iterator::operator[](label n)
{
	return *(*this + n);
}

template<class T>
inline bool AutLib::PtrList<T>::iterator::operator<(const iterator& iter) const
{
	return ptr_ < iter.ptr_;
}

template<class T>
inline bool AutLib::PtrList<T>::iterator::operator>(const iterator& iter) const
{
	return ptr_ > iter.ptr_;
}

template<class T>
inline bool AutLib::PtrList<T>::iterator::operator<=(const iterator& iter) const
{
	return ptr_ <= iter.ptr_;
}

template<class T>
inline bool AutLib::PtrList<T>::iterator::operator>=(const iterator& iter) const
{
	return ptr_ >= iter.ptr_;
}

template<class T>
inline typename AutLib::PtrList<T>::iterator
AutLib::PtrList<T>::begin()
{
	return ptrs_.begin();
}

template<class T>
inline typename AutLib::PtrList<T>::iterator
AutLib::PtrList<T>::end()
{
	return ptrs_.end();
}

namespace AutLib
{
	template<class T>
	inline typename AutLib::PtrList<T>::iterator operator+(const typename PtrList<T>::iterator& iter, label n)
	{
		typename PtrList<T>::iterator tmp = iter;
		return tmp += n;
	}

	template<class T>
	inline typename AutLib::PtrList<T>::iterator operator+(label n, const typename PtrList<T>::iterator& iter)
	{
		typename PtrList<T>::iterator tmp = iter;
		return tmp += n;
	}

	template<class T>
	inline typename AutLib::PtrList<T>::iterator PtrList<T>::iterator::operator-=(label n)
	{
		ptr_ -= n;
		return *this;
	}

	template<class T>
	inline typename AutLib::PtrList<T>::iterator operator-(const typename PtrList<T>::iterator& iter, label n)
	{
		typename PtrList<T>::iterator tmp = iter;
		return tmp -= n;
	}

	template<class T>
	inline AutLib::label operator-(const typename PtrList<T>::iterator& iter1, const typename PtrList<T>::iterator& iter2)
	{
		return (iter1.ptr_ - iter2.ptr_) / sizeof(T*);
	}
}

template<class T>
template<class INew>
void AutLib::PtrList<T>::read(Istream& is, const INew& inewt)
{
	is.fatalCheck("PtrList<T>::read(Istream&, const INew&)");

	token firstToken(is);

	is.fatalCheck
	(
		"PtrList<T>::read(Istream&, const INew&) : "
		"reading first token"
	);

	if (firstToken.isLabel())
	{
		// Read size of list
		label s = firstToken.labelToken();

		setSize(s);

		// Read beginning of contents
		char delimiter = is.readBeginList("PtrList");

		if (s)
		{
			if (delimiter == token::BEGIN_LIST)
			{
				for (AutLib::label i = 0; i < (*this).size(); i++)
				{
					set(i, inewt(is));

					is.fatalCheck
					(
						"PtrList<T>::read(Istream&, const INew&) : "
						"reading entry"
					);
				}
			}
			else
			{
				T* tPtr = inewt(is).ptr();
				set(0, tPtr);

				is.fatalCheck
				(
					"PtrList<T>::read(Istream&, const INew&) : "
					"reading the single entry"
				);

				for (label i = 1; i < s; i++)
				{
					set(i, tPtr->clone());
				}
			}
		}

		// Read end of contents
		is.readEndList("PtrList");
	}
	else if (firstToken.isPunctuation())
	{
		if (firstToken.pToken() != token::BEGIN_LIST)
		{
			FatalIOErrorIn
			(
				"PtrList<T>::read(Istream&, const INew&)",
				is
			) << "incorrect first token, '(', found " << firstToken.info()
				<< exit(FatalIOError);
		}

		SLList<T*> sllPtrs;

		token lastToken(is);
		while
			(
				!(
					lastToken.isPunctuation()
					&& lastToken.pToken() == token::END_LIST
					)
				)
		{
			is.putBack(lastToken);
			sllPtrs.append(inewt(is).ptr());
			is >> lastToken;
		}

		setSize(sllPtrs.size());

		label i = 0;
		for
			(
				typename SLList<T*>::iterator iter = sllPtrs.begin();
				iter != sllPtrs.end();
				++iter
				)
		{
			set(i++, iter());
		}
	}
	else
	{
		FatalIOErrorIn
		(
			"PtrList<T>::read(Istream&, const INew&)",
			is
		) << "incorrect first token, expected <int> or '(', found "
			<< firstToken.info()
			<< exit(FatalIOError);
	}
}

template<class T>
template<class INew>
AutLib::PtrList<T>::PtrList(Istream& is, const INew& inewt)
{
	read(is, inewt);
}


template<class T>
AutLib::PtrList<T>::PtrList(Istream& is)
{
	read(is, INew<T>());
}

namespace AutLib
{

	template<class T>
	Istream& operator>>(Istream& is, PtrList<T>& L)
	{
		L.clear();
		L.read(is, INew<T>());

		return is;
	}

	template<class T>
	Ostream& operator<<(Ostream& os, const PtrList<T>& L)
	{
		// Write size and start delimiter
		os << nl << L.size() << nl << token::BEGIN_LIST;

		// Write contents
		for (AutLib::label i = 0; i < (L).size(); i++)
		{
			os << nl << L[i];
		}

		// Write end delimiter
		os << nl << token::END_LIST << nl;

		// Check state of IOstream
		os.check("Ostream& operator<<(Ostream&, const PtrList&)");

		return os;
	}
}