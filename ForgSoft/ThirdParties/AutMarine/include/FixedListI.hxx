#pragma once
#include <UList.hxx>
#include <SLList.hxx>
#include <contiguous.hxx>
#include <error.hxx>
#include <OSstream.hxx>
#include <uint.hxx>
template<class T, unsigned Size>
const AutLib::FixedList<T, Size> AutLib::FixedList<T, Size>::zero;

template<class T, unsigned Size>
inline AutLib::FixedList<T, Size>::FixedList()
{}


template<class T, unsigned Size>
inline AutLib::FixedList<T, Size>::FixedList(const T v[Size])
{
	for (unsigned i = 0; i < Size; i++)
	{
		v_[i] = v[i];
	}
}


template<class T, unsigned Size>
inline AutLib::FixedList<T, Size>::FixedList(const T& t)
{
	for (unsigned i = 0; i < Size; i++)
	{
		v_[i] = t;
	}
}


template<class T, unsigned Size>
inline AutLib::FixedList<T, Size>::FixedList(const UList<T>& lst)
{
	checkSize(lst.size());

	for (unsigned i = 0; i < Size; i++)
	{
		v_[i] = lst[i];
	}
}


template<class T, unsigned Size>
inline AutLib::FixedList<T, Size>::FixedList(const SLList<T>& lst)
{
	checkSize(lst.size());

	label i = 0;
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
inline AutLib::FixedList<T, Size>::FixedList(const FixedList<T, Size>& lst)
{
	for (unsigned i = 0; i < Size; i++)
	{
		v_[i] = lst[i];
	}
}


template<class T, unsigned Size>
AutLib::FixedList<T, Size>::FixedList(Istream& is)
{
	operator>>(is, *this);
}

template<class T, unsigned Size>
inline AutLib::autoPtr< AutLib::FixedList<T, Size> >
AutLib::FixedList<T, Size>::clone() const
{
	return autoPtr< FixedList<T, Size> >(new FixedList<T, Size>(*this));
}

template<class T, unsigned Size>
inline const AutLib::FixedList<T, Size>& AutLib::FixedList<T, Size>::null()
{
	return zero;
}


template<class T, unsigned Size>
inline AutLib::label AutLib::FixedList<T, Size>::fcIndex(const label i) const
{
	return (i == Size - 1 ? 0 : i + 1);
}


template<class T, unsigned Size>
inline AutLib::label AutLib::FixedList<T, Size>::rcIndex(const label i) const
{
	return (i ? i - 1 : Size - 1);
}


// Check start is within valid range (0 ... size-1).
template<class T, unsigned Size>
inline void AutLib::FixedList<T, Size>::checkStart(const label start) const
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
inline void AutLib::FixedList<T, Size>::checkSize(const label size) const
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
inline void AutLib::FixedList<T, Size>::checkIndex(const label i) const
{
	if (i < 0 || unsigned(i) >= Size)
	{
		FatalErrorIn("FixedList<T, Size>::checkIndex(const label)")
			<< "index " << i << " out of range 0 ... " << (Size - 1)
			<< abort(FatalError);
	}
}


template<class T, unsigned Size>
inline void AutLib::FixedList<T, Size>::resize(const label s)
{
#   ifdef FULLDEBUG
	checkSize(s);
#   endif
}

template<class T, unsigned Size>
inline void AutLib::FixedList<T, Size>::setSize(const label s)
{
#   ifdef FULLDEBUG
	checkSize(s);
#   endif
}

template<class T, unsigned Size>
inline void AutLib::FixedList<T, Size>::transfer(const FixedList<T, Size>& lst)
{
	for (unsigned i = 0; i < Size; i++)
	{
		v_[i] = lst[i];
	}
}

template<class T, unsigned Size>
void AutLib::FixedList<T, Size>::writeEntry(Ostream& os) const
{
	if(size()&& token::compound::isCompound("List<" + word(pTraits<T>::typeName) + '>'))
	{
		os << word("List<" + word(pTraits<T>::typeName) + '>') << " ";
	}

	os << *this;
}


template<class T, unsigned Size>
void AutLib::FixedList<T, Size>::writeEntry
(const word& keyword, Ostream& os) const
{
	os.writeKeyword(keyword);
	writeEntry(os);
	os << token::END_STATEMENT << endl;
}

template<class T, unsigned Size>
inline const T*
AutLib::FixedList<T, Size>::cdata() const
{
	return v_;
}


template<class T, unsigned Size>
inline T*
AutLib::FixedList<T, Size>::data()
{
	return v_;
}

namespace AutLib
{
	// element access
	template<class T, unsigned Size>
	inline T& FixedList<T, Size>::operator[](const label i)
	{
#   ifdef FULLDEBUG
		checkIndex(i);
#   endif
		return v_[i];
	}


	// const element access
	template<class T, unsigned Size>
	inline const T& FixedList<T, Size>::operator[](const label i) const
	{
#   ifdef FULLDEBUG
		checkIndex(i);
#   endif
		return v_[i];
	}


	template<class T, unsigned Size>
	inline void FixedList<T, Size>::operator=(const T lst[Size])
	{
		for (unsigned i = 0; i < Size; i++)
		{
			v_[i] = lst[i];
		}
	}

	template<class T, unsigned Size>
	inline void FixedList<T, Size>::operator=(const UList<T>& lst)
	{
		checkSize(lst.size());

		for (unsigned i = 0; i < Size; i++)
		{
			v_[i] = lst[i];
		}
	}

	template<class T, unsigned Size>
	inline void FixedList<T, Size>::operator=(const SLList<T>& lst)
	{
		checkSize(lst.size());

		label i = 0;
		for (typename SLList<T>::const_iterator iter = lst.begin(); iter != lst.end(); ++iter)
		{
			operator[](i++) = iter();
		}
	}

	template<class T, unsigned Size>
	inline void FixedList<T, Size>::operator=(const T& t)
	{
		for (unsigned i = 0; i < Size; i++)
		{
			v_[i] = t;
		}
	}
}

template<class T, unsigned Size>
inline typename AutLib::FixedList<T, Size>::iterator
AutLib::FixedList<T, Size>::begin()
{
	return v_;
}


template<class T, unsigned Size>
inline typename AutLib::FixedList<T, Size>::const_iterator
AutLib::FixedList<T, Size>::begin() const
{
	return v_;
}


template<class T, unsigned Size>
inline typename AutLib::FixedList<T, Size>::const_iterator
AutLib::FixedList<T, Size>::cbegin() const
{
	return v_;
}


template<class T, unsigned Size>
inline typename AutLib::FixedList<T, Size>::iterator
AutLib::FixedList<T, Size>::end()
{
	return &v_[Size];
}


template<class T, unsigned Size>
inline typename AutLib::FixedList<T, Size>::const_iterator
AutLib::FixedList<T, Size>::end() const
{
	return &v_[Size];
}


template<class T, unsigned Size>
inline typename AutLib::FixedList<T, Size>::const_iterator
AutLib::FixedList<T, Size>::cend() const
{
	return &v_[Size];
}


template<class T, unsigned Size>
inline typename AutLib::FixedList<T, Size>::iterator
AutLib::FixedList<T, Size>::rbegin()
{
	return &v_[Size - 1];
}


template<class T, unsigned Size>
inline typename AutLib::FixedList<T, Size>::const_iterator
AutLib::FixedList<T, Size>::rbegin() const
{
	return &v_[Size - 1];
}


template<class T, unsigned Size>
inline typename AutLib::FixedList<T, Size>::const_iterator
AutLib::FixedList<T, Size>::crbegin() const
{
	return &v_[Size - 1];
}


template<class T, unsigned Size>
inline typename AutLib::FixedList<T, Size>::iterator
AutLib::FixedList<T, Size>::rend()
{
	return &v_[-1];
}


template<class T, unsigned Size>
inline typename AutLib::FixedList<T, Size>::const_iterator
AutLib::FixedList<T, Size>::rend() const
{
	return &v_[-1];
}


template<class T, unsigned Size>
inline typename AutLib::FixedList<T, Size>::const_iterator
AutLib::FixedList<T, Size>::crend() const
{
	return &v_[-1];
}


template<class T, unsigned Size>
inline AutLib::label AutLib::FixedList<T, Size>::size() const
{
	return Size;
}


template<class T, unsigned Size>
inline AutLib::label AutLib::FixedList<T, Size>::max_size() const
{
	return Size;
}


template<class T, unsigned Size>
inline bool AutLib::FixedList<T, Size>::empty() const
{
	return false;
}

template<class T, unsigned Size>
void AutLib::FixedList<T, Size>::swap(FixedList<T, Size>& a)
{
	register T* vp = ((*this)).begin();
	register T* ap = (a).begin();
	T tmp;
	register label i = ((*this)).size(); while (i--) 
	{
		tmp = (*vp++);
		(*vp++) = (*ap++);
		(*ap++) = tmp;
	}
}

namespace AutLib
{
	template<class T, unsigned Size>
	bool FixedList<T, Size>::operator==(const FixedList<T, Size>& a) const
	{
		bool equal = true;

		register const T* vp = ((*this)).begin();
		register const T* ap = ((a)).begin();

		register label i = ((*this)).size(); while (i--) {
			equal = equal && ((*vp++) == (*ap++));
		}

		return equal;
	}


	template<class T, unsigned Size>
	bool FixedList<T, Size>::operator!=(const FixedList<T, Size>& a) const
	{
		return !operator==(a);
	}


	template<class T, unsigned Size>
	bool FixedList<T, Size>::operator<(const FixedList<T, Size>& a) const
	{
		for(const_iterator vi = cbegin(), ai = a.cbegin(); vi < cend() && ai < a.cend(); vi++, ai++)
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
	bool FixedList<T, Size>::operator>(const FixedList<T, Size>& a) const
	{
		return a.operator<(*this);
	}


	template<class T, unsigned Size>
	bool FixedList<T, Size>::operator<=(const FixedList<T, Size>& a) const
	{
		return !operator>(a);
	}


	template<class T, unsigned Size>
	bool FixedList<T, Size>::operator>=(const FixedList<T, Size>& a) const
	{
		return !operator<(a);
	}
}


namespace AutLib
{
	template<class T, unsigned Size>
	template<class HashT>
	inline unsigned FixedList<T, Size>::Hash<HashT>::operator()(const FixedList<T, Size>& lst, unsigned seed) const
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
			//CloseProgram("inline unsigned AutLib::FixedList<T, Size>::Hash<HashT>::operator() not supposed to be run yet");
			for (unsigned i = 0; i<Size; i++)
			{
				val = HashT()(lst[i], val);
			}

			return val;
		}
	}

	template<class T, unsigned Size>
	Istream& operator>>(Istream& is, FixedList<T, Size>& L)
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
				L = dynamicCast<token::Compound<List<T> > >
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

	template<class T, unsigned Size>
	Ostream& operator<<(Ostream& os, const FixedList<T, Size>& L)
	{
		// Write list contents depending on data format
		if (os.format() == IOstream::ASCII || !contiguous<T>())
		{
			bool uniform = false;

			if (Size > 1 && contiguous<T>())
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
				for (AutLib::label i = 0; i < (L).size(); i++)
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
				for (AutLib::label i = 0; i < (L).size(); i++)
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
}