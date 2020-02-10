#pragma once
#include <UList.hxx>
#include <SLList.hxx>
#include <contiguous.hxx>

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class T, unsigned Size>
tnbLib::FixedList<T, Size>::FixedList()
{}


template<class T, unsigned Size>
tnbLib::FixedList<T, Size>::FixedList(const T v[Size])
{
	for (register unsigned i = 0; i < Size; i++)
	{
		v_[i] = v[i];
	}
}


template<class T, unsigned Size>
tnbLib::FixedList<T, Size>::FixedList(const T& t)
{
	for (register unsigned i = 0; i < Size; i++)
	{
		v_[i] = t;
	}
}


template<class T, unsigned Size>
tnbLib::FixedList<T, Size>::FixedList(const UList<T>& lst)
{
	checkSize(lst.size());

	for (register unsigned i = 0; i < Size; i++)
	{
		v_[i] = lst[i];
	}
}


template<class T, unsigned Size>
tnbLib::FixedList<T, Size>::FixedList(const SLList<T>& lst)
{
	checkSize(lst.size());

	register label i = 0;
	for
		(
			typename SLList<T>::const_iterator iter = lst.begin();
			iter != lst.end();
			++iter
			)
	{
		operator[](i++) = iter();
	}
}


template<class T, unsigned Size>
tnbLib::FixedList<T, Size>::FixedList(const FixedList<T, Size>& lst)
{
	for (register unsigned i = 0; i < Size; i++)
	{
		v_[i] = lst[i];
	}
}


template<class T, unsigned Size>
tnbLib::autoPtr< tnbLib::FixedList<T, Size>>
tnbLib::FixedList<T, Size>::clone() const
{
	return autoPtr< FixedList<T, Size>>(new FixedList<T, Size>(*this));
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class T, unsigned Size>
const tnbLib::FixedList<T, Size>& tnbLib::FixedList<T, Size>::null()
{
	return zero;
}


template<class T, unsigned Size>
tnbLib::label tnbLib::FixedList<T, Size>::fcIndex(const label i) const
{
	return (i == Size - 1 ? 0 : i + 1);
}


template<class T, unsigned Size>
tnbLib::label tnbLib::FixedList<T, Size>::rcIndex(const label i) const
{
	return (i ? i - 1 : Size - 1);
}


// Check start is within valid range (0 ... size-1).
template<class T, unsigned Size>
void tnbLib::FixedList<T, Size>::checkStart(const label start) const
{
	if (start < 0 || (start && unsigned(start) >= Size))
	{
		FatalErrorIn("FixedList<T, Size>::checkStart(const label)")
			<< "start " << start << " out of range 0 ... " << (Size - 1)
			<< abort(FatalError);
	}
}


// Check size is within valid range (0 ... size).
template<class T, unsigned Size>
void tnbLib::FixedList<T, Size>::checkSize(const label size) const
{
	if (size < 0 || unsigned(size) > Size)
	{
		FatalErrorIn("FixedList<T, Size>::checkSize(const label)")
			<< "size " << size << " out of range 0 ... " << (Size)
			<< abort(FatalError);
	}
}


// Check index i is within valid range (0 ... size-1)
// The check for zero-sized list is already done in static assert
template<class T, unsigned Size>
void tnbLib::FixedList<T, Size>::checkIndex(const label i) const
{
	if (i < 0 || unsigned(i) >= Size)
	{
		FatalErrorIn("FixedList<T, Size>::checkIndex(const label)")
			<< "index " << i << " out of range 0 ... " << (Size - 1)
			<< abort(FatalError);
	}
}


template<class T, unsigned Size>
void tnbLib::FixedList<T, Size>::resize(const label s)
{
#   ifdef FULLDEBUG
	checkSize(s);
#   endif
}

template<class T, unsigned Size>
void tnbLib::FixedList<T, Size>::setSize(const label s)
{
#   ifdef FULLDEBUG
	checkSize(s);
#   endif
}

template<class T, unsigned Size>
void tnbLib::FixedList<T, Size>::transfer(const FixedList<T, Size>& lst)
{
	for (register unsigned i = 0; i < Size; i++)
	{
		v_[i] = lst[i];
	}
}


template<class T, unsigned Size>
const T*
tnbLib::FixedList<T, Size>::cdata() const
{
	return v_;
}


template<class T, unsigned Size>
T*
tnbLib::FixedList<T, Size>::data()
{
	return v_;
}


// * * * * * * * * * * * * * * * Member Operators  * * * * * * * * * * * * * //

// element access
template<class T, unsigned Size>
T& tnbLib::FixedList<T, Size>::operator[](const label i)
{
#   ifdef FULLDEBUG
	checkIndex(i);
#   endif
	return v_[i];
}


// const element access
template<class T, unsigned Size>
const T& tnbLib::FixedList<T, Size>::operator[](const label i) const
{
#   ifdef FULLDEBUG
	checkIndex(i);
#   endif
	return v_[i];
}


template<class T, unsigned Size>
void tnbLib::FixedList<T, Size>::operator=(const T lst[Size])
{
	for (register unsigned i = 0; i < Size; i++)
	{
		v_[i] = lst[i];
	}
}

template<class T, unsigned Size>
void tnbLib::FixedList<T, Size>::operator=(const UList<T>& lst)
{
	checkSize(lst.size());

	for (register unsigned i = 0; i < Size; i++)
	{
		v_[i] = lst[i];
	}
}

template<class T, unsigned Size>
void tnbLib::FixedList<T, Size>::operator=(const SLList<T>& lst)
{
	checkSize(lst.size());

	register label i = 0;
	for
		(
			typename SLList<T>::const_iterator iter = lst.begin();
			iter != lst.end();
			++iter
			)
	{
		operator[](i++) = iter();
	}
}

template<class T, unsigned Size>
void tnbLib::FixedList<T, Size>::operator=(const T& t)
{
	for (register unsigned i = 0; i < Size; i++)
	{
		v_[i] = t;
	}
}


// * * * * * * * * * * * * * * STL Member Functions  * * * * * * * * * * * * //

template<class T, unsigned Size>
typename tnbLib::FixedList<T, Size>::iterator
tnbLib::FixedList<T, Size>::begin()
{
	return v_;
}


template<class T, unsigned Size>
typename tnbLib::FixedList<T, Size>::const_iterator
tnbLib::FixedList<T, Size>::begin() const
{
	return v_;
}


template<class T, unsigned Size>
typename tnbLib::FixedList<T, Size>::const_iterator
tnbLib::FixedList<T, Size>::cbegin() const
{
	return v_;
}


template<class T, unsigned Size>
typename tnbLib::FixedList<T, Size>::iterator
tnbLib::FixedList<T, Size>::end()
{
	return &v_[Size];
}


template<class T, unsigned Size>
typename tnbLib::FixedList<T, Size>::const_iterator
tnbLib::FixedList<T, Size>::end() const
{
	return &v_[Size];
}


template<class T, unsigned Size>
typename tnbLib::FixedList<T, Size>::const_iterator
tnbLib::FixedList<T, Size>::cend() const
{
	return &v_[Size];
}


template<class T, unsigned Size>
typename tnbLib::FixedList<T, Size>::iterator
tnbLib::FixedList<T, Size>::rbegin()
{
	return &v_[Size - 1];
}


template<class T, unsigned Size>
typename tnbLib::FixedList<T, Size>::const_iterator
tnbLib::FixedList<T, Size>::rbegin() const
{
	return &v_[Size - 1];
}


template<class T, unsigned Size>
typename tnbLib::FixedList<T, Size>::const_iterator
tnbLib::FixedList<T, Size>::crbegin() const
{
	return &v_[Size - 1];
}


template<class T, unsigned Size>
typename tnbLib::FixedList<T, Size>::iterator
tnbLib::FixedList<T, Size>::rend()
{
	return &v_[-1];
}


template<class T, unsigned Size>
typename tnbLib::FixedList<T, Size>::const_iterator
tnbLib::FixedList<T, Size>::rend() const
{
	return &v_[-1];
}


template<class T, unsigned Size>
typename tnbLib::FixedList<T, Size>::const_iterator
tnbLib::FixedList<T, Size>::crend() const
{
	return &v_[-1];
}


template<class T, unsigned Size>
tnbLib::label tnbLib::FixedList<T, Size>::size() const
{
	return Size;
}


template<class T, unsigned Size>
tnbLib::label tnbLib::FixedList<T, Size>::max_size() const
{
	return Size;
}


template<class T, unsigned Size>
bool tnbLib::FixedList<T, Size>::empty() const
{
	return false;
}


template<class T, unsigned Size>
template<class HashT>
unsigned tnbLib::FixedList<T, Size>::Hash<HashT>::operator()
(
	const FixedList<T, Size>& lst,
	unsigned seed
	) const
{
	if (contiguous<T>())
	{
		// hash directly
		return Hasher(lst.v_, sizeof(lst.v_), seed);
	}
	else
	{
		// hash incrementally
		unsigned val = seed;

		for (register unsigned i = 0; i < Size; i++)
		{
			val = HashT()(lst[i], val);
		}

		return val;
	}
}


// ************************************************************************* //

//- moved from cxx

#include <ListLoopM.hxx>

// * * * * * * * * * * * * * * * Static Members  * * * * * * * * * * * * * * //

template<class T, unsigned Size>
const tnbLib::FixedList<T, Size> tnbLib::FixedList<T, Size>::zero;


// * * * * * * * * * * * * * * STL Member Functions  * * * * * * * * * * * * //

template<class T, unsigned Size>
void tnbLib::FixedList<T, Size>::swap(FixedList<T, Size>& a)
{
	List_ACCESS(T, (*this), vp);
	List_ACCESS(T, a, ap);
	T tmp;
	List_FOR_ALL((*this), i)
		tmp = List_ELEM((*this), vp, i);
	List_ELEM((*this), vp, i) = List_ELEM(a, ap, i);
	List_ELEM(a, ap, i) = tmp;
	List_END_FOR_ALL
}


// * * * * * * * * * * * * * * * Member Operators  * * * * * * * * * * * * * //

template<class T, unsigned Size>
bool tnbLib::FixedList<T, Size>::operator==(const FixedList<T, Size>& a) const
{
	bool equal = true;

	List_CONST_ACCESS(T, (*this), vp);
	List_CONST_ACCESS(T, (a), ap);

	List_FOR_ALL((*this), i)
		equal = equal && (List_ELEM((*this), vp, i) == List_ELEM((a), ap, i));
	List_END_FOR_ALL

		return equal;
}


template<class T, unsigned Size>
bool tnbLib::FixedList<T, Size>::operator!=(const FixedList<T, Size>& a) const
{
	return !operator==(a);
}


template<class T, unsigned Size>
bool tnbLib::FixedList<T, Size>::operator<(const FixedList<T, Size>& a) const
{
	for
		(
			const_iterator vi = cbegin(), ai = a.cbegin();
			vi < cend() && ai < a.cend();
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

	if (Size < a.Size)
	{
		return true;
	}
	else
	{
		return false;
	}
}


template<class T, unsigned Size>
bool tnbLib::FixedList<T, Size>::operator>(const FixedList<T, Size>& a) const
{
	return a.operator<(*this);
}


template<class T, unsigned Size>
bool tnbLib::FixedList<T, Size>::operator<=(const FixedList<T, Size>& a) const
{
	return !operator>(a);
}


template<class T, unsigned Size>
bool tnbLib::FixedList<T, Size>::operator>=(const FixedList<T, Size>& a) const
{
	return !operator<(a);
}


// * * * * * * * * * * * * * * * *  IOStream operators * * * * * * * * * * * //

//- moved from io.cxx

#include <Istream.hxx>
#include <Ostream.hxx>
#include <token.hxx>
#include <contiguous.hxx>

// * * * * * * * * * * * * * * * IOstream Operators  * * * * * * * * * * * * //

template<class T, unsigned Size>
tnbLib::FixedList<T, Size>::FixedList(Istream& is)
{
	operator>>(is, *this);
}


template<class T, unsigned Size>
tnbLib::Istream& tnbLib::operator>>(tnbLib::Istream& is, FixedList<T, Size>& L)
{
	is.fatalCheck("operator>>(Istream&, FixedList<T, Size>&)");

	if (is.format() == IOstream::ASCII || !contiguous<T>())
	{
		token firstToken(is);

		is.fatalCheck
		(
			"operator>>(Istream&, FixedList<T, Size>&) : reading first token"
		);

		if (firstToken.isCompound())
		{
			L = dynamicCast<token::Compound<List<T>>>
				(
					firstToken.transferCompoundToken()
					);
		}
		else if (firstToken.isLabel())
		{
			label s = firstToken.labelToken();

			// Set list length to that read
			L.checkSize(s);
		}
		else if (!firstToken.isPunctuation())
		{
			FatalIOErrorIn("operator>>(Istream&, FixedList<T, Size>&)", is)
				<< "incorrect first token, expected <label> "
				"or '(' or '{', found "
				<< firstToken.info()
				<< exit(FatalIOError);
		}
		else
		{
			// Putback the opening bracket
			is.putBack(firstToken);
		}

		// Read beginning of contents
		char delimiter = is.readBeginList("FixedList");

		if (delimiter == token::BEGIN_LIST)
		{
			for (register unsigned i = 0; i < Size; i++)
			{
				is >> L[i];

				is.fatalCheck
				(
					"operator>>(Istream&, FixedList<T, Size>&) : "
					"reading entry"
				);
			}
		}
		else
		{
			T element;
			is >> element;

			is.fatalCheck
			(
				"operator>>(Istream&, FixedList<T, Size>&) : "
				"reading the single entry"
			);

			for (register unsigned i = 0; i < Size; i++)
			{
				L[i] = element;
			}
		}

		// Read end of contents
		is.readEndList("FixedList");
	}
	else
	{
		is.read(reinterpret_cast<char*>(L.data()), Size * sizeof(T));

		is.fatalCheck
		(
			"operator>>(Istream&, FixedList<T, Size>&) : "
			"reading the binary block"
		);
	}

	return is;
}


// * * * * * * * * * * * * * * * Ostream Operator *  * * * * * * * * * * * * //

template<class T, unsigned Size>
void tnbLib::FixedList<T, Size>::writeEntry(Ostream& os) const
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


template<class T, unsigned Size>
void tnbLib::FixedList<T, Size>::writeEntry
(
	const word& keyword,
	Ostream& os
) const
{
	os.writeKeyword(keyword);
	writeEntry(os);
	os << token::END_STATEMENT << endl;
}


template<class T, unsigned Size>
tnbLib::Ostream& tnbLib::operator<<(Ostream& os, const FixedList<T, Size>& L)
{
	// Write list contents depending on data format
	if (os.format() == IOstream::ASCII || !contiguous<T>())
	{
		bool uniform = false;

		if (Size > 1 && contiguous<T>())
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
			// Write size (so it is valid dictionary entry) and start delimiter
			os << L.size() << token::BEGIN_BLOCK;

			// Write contents
			os << L[0];

			// Write end delimiter
			os << token::END_BLOCK;
		}
		else if (Size < 11 && contiguous<T>())
		{
			// Write start delimiter
			os << token::BEGIN_LIST;

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
			// Write start delimiter
			os << nl << token::BEGIN_LIST;

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
		os.write(reinterpret_cast<const char*>(L.cdata()), Size * sizeof(T));
	}

	// Check state of IOstream
	os.check("Ostream& operator<<(Ostream&, const FixedList&)");

	return os;
}


// ************************************************************************* //