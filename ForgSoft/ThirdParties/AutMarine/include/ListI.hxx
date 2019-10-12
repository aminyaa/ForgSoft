#pragma once
#include <BiIndirectList.hxx>
#include <UIndirectList.hxx>
#include <IndirectList.hxx>
#include <SLList.hxx>
#include <PtrList.hxx>
#include <typeInfo.hxx>
template<class Type>
const AutLib::List<Type> AutLib::List<Type>::zero;

template<class T>
inline AutLib::List<T>::List()
{}

template<class T>
AutLib::List<T>::List(const label s)
	: UList<T>(NULL, s)
{
	if (this->size_ < 0)
	{
		FatalErrorIn("List<T>::List(const label size)")
			<< "bad size " << this->size_
			<< abort(FatalError);
	}

	if (this->size_)
	{
		this->v_ = new T[this->size_];
	}
}


// Construct with length and single value specified
template<class T>
AutLib::List<T>::List(const label s, const T& a)
	: UList<T>(NULL, s)
{
	if (this->size_ < 0)
	{
		FatalErrorIn("List<T>::List(const label size, const T&)")
			<< "bad size " << this->size_
			<< abort(FatalError);
	}

	if (this->size_)
	{
		this->v_ = new T[this->size_];

		T* vp = ((*this)).begin();
		label i = ((*this)).size(); 
		while (i--) 
		{
			(*vp++) = a;
		}
	}
}


// Construct as copy
template<class T>
AutLib::List<T>::List(const List<T>& a)
	: UList<T>(NULL, a.size_)
{
	if (this->size_)
	{
		this->v_ = new T[this->size_];

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
			label i = ((*this)).size(); 
			while (i--) {
				(*vp++) = (*ap++);
			}
		}
	}
}


// Construct by transferring the parameter contents
template<class T>
AutLib::List<T>::List(const Xfer< List<T> >& lst)
{
	transfer(lst());
}


// Construct as copy or re-use as specified.
template<class T>
AutLib::List<T>::List(List<T>& a, bool reUse)
	: UList<T>(NULL, a.size_)
{
	if (reUse)
	{
		this->v_ = a.v_;
		a.v_ = 0;
		a.size_ = 0;
	}
	else if (this->size_)
	{
		this->v_ = new T[this->size_];

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

// Construct as subset
template<class T>
AutLib::List<T>::List(const UList<T>& a, const unallocLabelList& map)
	: UList<T>(NULL, map.size())
{
	if (this->size_)
	{
		// Note:cannot use List_ELEM since third argument has to be index.

		this->v_ = new T[this->size_];

		for (label i = 0; i < (*this).size(); i++)
		{
			this->v_[i] = a[map[i]];
		}
	}
}


// Construct given start and end iterators.
template<class T>
template<class InputIterator>
AutLib::List<T>::List(InputIterator first, InputIterator last)
{
	label s = 0;
	for (InputIterator iter = first; iter != last; ++iter)
	{
		s++;
	}

	setSize(s);

	s = 0;

	for (InputIterator iter = first; iter != last; ++iter)
	{
		this->operator[](s++) = iter();
	}
}

// Construct as copy of FixedList<T, Size>
template<class T>
template<unsigned Size>
AutLib::List<T>::List(const FixedList<T, Size>& lst)
	: UList<T>(NULL, Size)
{
	if (this->size_)
	{
		this->v_ = new T[this->size_];

		for (label i = 0; i < (*this).size(); i++)
		{
			this->operator[](i) = lst[i];
		}
	}
}


// Construct as copy of PtrList<T>
template<class T>
AutLib::List<T>::List(const PtrList<T>& lst)
	: UList<T>(NULL, lst.size())
{
	if (this->size_)
	{
		this->v_ = new T[this->size_];

		for (AutLib::label i = 0; i < (*this).size(); i++)
		{
			this->operator[](i) = lst[i];
		}
	}
}


// Construct as copy of SLList<T>
template<class T>
AutLib::List<T>::List(const SLList<T>& lst)
	: UList<T>(NULL, lst.size())
{
	if (this->size_)
	{
		this->v_ = new T[this->size_];

		label i = 0;
		for
			(
				typename SLList<T>::const_iterator iter = lst.begin();
				iter != lst.end();
				++iter
				)
		{
			this->operator[](i++) = iter();
		}
	}
}

// Construct as copy of IndirectList<T>
template<class T>
AutLib::List<T>::List(const IndirectList<T>& lst)
	:
	UList<T>(NULL, lst.size())
{
	if (this->size_)
	{
		this->v_ = new T[this->size_];

		for (AutLib::label i = 0; i < (*this).size(); i++)
		{
			this->operator[](i) = lst[i];
		}
	}
}

// Construct as copy of UIndirectList<T>
template<class T>
AutLib::List<T>::List(const UIndirectList<T>& lst)
	: UList<T>(NULL, lst.size())
{
	if (this->size_)
	{
		this->v_ = new T[this->size_];

		for (AutLib::label i = 0; i < (*this).size(); i++)
		{
			this->operator[](i) = lst[i];
		}
	}
}


// Construct as copy of BiIndirectList<T>
template<class T>
AutLib::List<T>::List(const BiIndirectList<T>& lst)
	: UList<T>(NULL, lst.size())
{
	if (this->size_)
	{
		this->v_ = new T[this->size_];

		for (AutLib::label i = 0; i < (*this).size(); i++)
		{
			this->operator[](i) = lst[i];
		}
	}
}

template<class T>
AutLib::List<T>::List(Istream& is)
	: UList<T>(NULL, 0)
{
	operator>>(is, *this);
}

// Destroy list elements
template<class T>
AutLib::List<T>::~List()
{
	if (this->v_) delete[] this->v_;
}


template<class T>
void AutLib::List<T>::operator=(const T & t)
{
	register T* vp = ((*this)).begin();
	register label i = ((*this)).size(); while (i--) {
		(*vp++) = t;
	}
}



template<class T>
void AutLib::List<T>::setSize(const label newSize)
{
	if (newSize < 0)
	{
		FatalErrorIn("List<T>::setSize(const label)")
			<< "bad set size " << newSize
			<< abort(FatalError);
	}

	if (newSize != this->size_)
	{
		if (newSize > 0)
		{
			T* nv = new T[label(newSize)];

			if (this->size_)
			{
				register label i = min(this->size_, newSize);

#               ifdef USEMEMCPY
				if (contiguous<T>())
				{
					memcpy(nv, this->v_, i * sizeof(T));
				}
				else
#               endif
				{
					register T* vv = &this->v_[i];
					register T* av = &nv[i];
					while (i--) *--av = *--vv;
				}
			}
			if (this->v_) delete[] this->v_;

			this->size_ = newSize;
			this->v_ = nv;
		}
		else
		{
			clear();
		}
	}
}


template<class T>
void AutLib::List<T>::setSize(const label newSize, const T& a)
{
	label oldSize = this->size_;
	this->setSize(newSize);

	if (newSize > oldSize)
	{
		register label i = newSize - oldSize;
		register T* vv = &this->v_[newSize];
		while (i--) *--vv = a;
	}
}


template<class T>
void AutLib::List<T>::clear()
{
	if (this->v_) delete[] this->v_;
	this->size_ = 0;
	this->v_ = 0;
}


// Transfer the contents of the argument List into this List
// and anull the argument list
template<class T>
void AutLib::List<T>::transfer(List<T>& a)
{
	if (this->v_) delete[] this->v_;
	this->size_ = a.size_;
	this->v_ = a.v_;

	a.size_ = 0;
	a.v_ = 0;
}


// Transfer the contents of the argument DynamicList into this List
// and anull the argument list
template<class T>
template<unsigned SizeInc, unsigned SizeMult, unsigned SizeDiv>
void AutLib::List<T>::transfer(DynamicList<T, SizeInc, SizeMult, SizeDiv>& a)
{
	// shrink the allocated space to the number of elements used
	a.shrink();
	transfer(static_cast<List<T>&>(a));
	a.clearStorage();
}


// Transfer the contents of the argument SortableList into this List
// and anull the argument list
template<class T>
void AutLib::List<T>::transfer(SortableList<T>& a)
{
	// shrink away the sort indices
	a.shrink();
	transfer(static_cast<List<T>&>(a));
}

// Assignment to UList operator. Takes linear time.
template<class T>
void AutLib::List<T>::operator=(const UList<T>& a)
{
	if (a.size_ != this->size_)
	{
		if (this->v_) delete[] this->v_;
		this->v_ = 0;
		this->size_ = a.size_;
		if (this->size_) this->v_ = new T[this->size_];
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
			register T* vp = ((*this)).begin();
			register const T* ap = (a).begin();
			register label i = ((*this)).size(); while (i--) {
				(*vp++) = (*ap++);
			}
		}
	}
}


// Assignment operator. Takes linear time.
template<class T>
void AutLib::List<T>::operator=(const List<T>& a)
{
	if (this == &a)
	{
		FatalErrorIn("List<T>::operator=(const List<T>&)")
			<< "attempted assignment to self"
			<< abort(FatalError);
	}

	operator=(static_cast<const UList<T>&>(a));
}


// Assignment operator. Takes linear time.
template<class T>
void AutLib::List<T>::operator=(const SLList<T>& lst)
{
	if (lst.size() != this->size_)
	{
		if (this->v_) delete[] this->v_;
		this->v_ = 0;
		this->size_ = lst.size();
		if (this->size_) this->v_ = new T[this->size_];
	}

	if (this->size_)
	{
		label i = 0;
		for
			(
				typename SLList<T>::const_iterator iter = lst.begin();
				iter != lst.end();
				++iter
				)
		{
			this->operator[](i++) = iter();
		}
	}
}

// Assignment operator. Takes linear time.
template<class T>
void AutLib::List<T>::operator=(const IndirectList<T>& lst)
{
	if (lst.size() != this->size_)
	{
		if (this->v_) delete[] this->v_;
		this->v_ = 0;
		this->size_ = lst.size();
		if (this->size_) this->v_ = new T[this->size_];
	}

	for (AutLib::label i = 0; i < (*this).size(); i++)
	{
		this->operator[](i) = lst[i];
	}
}


// Assignment operator. Takes linear time.
template<class T>
void AutLib::List<T>::operator=(const UIndirectList<T>& lst)
{
	if (lst.size() != this->size_)
	{
		if (this->v_) delete[] this->v_;
		this->v_ = 0;
		this->size_ = lst.size();
		if (this->size_) this->v_ = new T[this->size_];
	}

	for (AutLib::label i = 0; i < (*this).size(); i++)
	{
		this->operator[](i) = lst[i];
	}
}

// Assignment operator. Takes linear time.
template<class T>
void AutLib::List<T>::operator=(const BiIndirectList<T>& lst)
{
	if (lst.size() != this->size_)
	{
		if (this->v_) delete[] this->v_;
		this->v_ = 0;
		this->size_ = lst.size();
		if (this->size_) this->v_ = new T[this->size_];
	}

	for (AutLib::label i = 0; i < (*this).size(); i++)
	{
		this->operator[](i) = lst[i];
	}
}

template<class T>
inline AutLib::autoPtr<AutLib::List<T> > AutLib::List<T>::clone() const
{
	return autoPtr<List<T> >(new List<T>(*this));
}

template<class T>
inline const AutLib::List<T>& AutLib::List<T>::null()
{
	return zero;
}


template<class T>
inline void AutLib::List<T>::resize(const label newSize)
{
	this->setSize(newSize);
}


template<class T>
inline void AutLib::List<T>::resize(const label newSize, const T& a)
{
	this->setSize(newSize, a);
}


template<class T>
inline T& AutLib::List<T>::newElmt(const label i)
{
	if (i >= this->size())
	{
		setSize(2 * this->size());
	}

	return UList<T>::operator[](i);
}


template<class T>
inline void AutLib::List<T>::size(const label n)
{
	UList<T>::size_ = n;
}


template<class T>
inline AutLib::label AutLib::List<T>::size() const
{
	return UList<T>::size_;
}


template<class T>
inline AutLib::Xfer< AutLib::List<T> > AutLib::List<T>::xfer()
{
	return xferMove(*this);
}


template<class T>
inline void AutLib::List<T>::append(const UList<T>& lst)
{
	if (this == &lst)
	{
		FatalErrorIn
		(
			"List<T>::append(const UList<T>&)"
		) << "attempted appending to self" << abort(FatalError);
	}

	label nextFree = this->size();
	setSize(nextFree + lst.size());

	for (AutLib::label elemI = 0; elemI < (lst).size(); elemI++)
	{
		this->operator[](nextFree++) = lst[elemI];
	}
}

namespace AutLib
{
	template<class T>
	Istream& operator>>(Istream& is, List<T>& L)
	{
		// Anull list
		L.setSize(0);

		is.fatalCheck("operator>>(Istream&, List<T>&)");

		token firstToken(is);

		is.fatalCheck("operator>>(Istream&, List<T>&) : reading first token");

		if (firstToken.isCompound())
		{
			L.transfer(dynamicCast<token::Compound<List<T> >>(firstToken.transferCompoundToken()));
		}
		else if (firstToken.isLabel())
		{
			label s = firstToken.labelToken();

			// Set list length to that read
			L.setSize(s);

			// Read list contents depending on data format

			if (is.format() == IOstream::ASCII || !contiguous<T>())
			{
				// Read beginning of contents
				char delimiter = is.readBeginList("List");

				if (s)
				{
					if (delimiter == token::BEGIN_LIST)
					{
						for (register label i = 0; i < s; i++)
						{
							is >> L[i];

							is.fatalCheck("operator>>(Istream&, List<T>&) : reading entry");
						}
					}
					else
					{
						T element;
						is >> element;

						is.fatalCheck("operator>>(Istream&, List<T>&) : ""reading the single entry");

						for (register label i = 0; i < s; i++)
						{
							L[i] = element;
						}
					}
				}

				// Read end of contents
				is.readEndList("List");
			}
			else
			{
				if (s)
				{
					is.read(reinterpret_cast<char*>(L.data()), s * sizeof(T));

					is.fatalCheck("operator>>(Istream&, List<T>&) : reading the binary block");
				}
			}
		}
		else if (firstToken.isPunctuation())
		{
			if (firstToken.pToken() != token::BEGIN_LIST)
			{
				FatalIOErrorIn("operator>>(Istream&, List<T>&)", is)
					<< "incorrect first token, expected '(', found "
					<< firstToken.info()
					<< exit(FatalIOError);
			}

			// Putback the openning bracket
			is.putBack(firstToken);

			// Now read as a singly-linked list
			SLList<T> sll(is);

			// Convert the singly-linked list to this list
			L = sll;
		}
		else
		{
			FatalIOErrorIn("operator>>(Istream&, List<T>&)", is)
				<< "incorrect first token, expected <int> or '(', found "
				<< firstToken.info()
				<< exit(FatalIOError);
		}

		return is;
	}
}

template<class T>
AutLib::List<T> AutLib::readList(Istream& is)
{
	List<T> L;
	token firstToken(is);
	is.putBack(firstToken);

	if (firstToken.isPunctuation())
	{
		if (firstToken.pToken() != token::BEGIN_LIST)
		{
			FatalIOErrorIn("readList<T>(Istream&)", is)
				<< "incorrect first token, expected '(', found "
				<< firstToken.info()
				<< exit(FatalIOError);
		}

		// read via a singly-linked list
		L = SLList<T>(is);
	}
	else
	{
		// create list with a single item
		L.setSize(1);

		is >> L[0];
	}

	return L;
}