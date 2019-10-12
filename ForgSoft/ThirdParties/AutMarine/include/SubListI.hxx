#pragma once
#include <List.hxx>
template<class T>
inline AutLib::SubList<T>::SubList
(
	const UList<T>& list,
	const label subSize
)
	: UList<T>(list.v_, subSize)
{
#   ifdef FULLDEBUG
	list.checkSize(subSize);
#   endif
}


template<class T>
inline AutLib::SubList<T>::SubList
(
	const UList<T>& list,
	const label subSize,
	const label startIndex
)
	: UList<T>(&(list.v_[startIndex]), subSize)
{
#   ifdef FULLDEBUG

	// Artificially allow the start of a zero-sized subList to be
	// one past the end of the original list.
	if (subSize)
	{
		list.checkStart(startIndex);
		list.checkSize(startIndex + subSize);
	}
	else
	{
		// Start index needs to fall between 0 and size.  One position
		// behind the last element is allowed
		list.checkSize(startIndex);
	}
#   endif
}

template<class T>
inline void AutLib::SubList<T>::reset
(
	const UList<T>& list,
	const label subSize
)
{
	UList<T>::reset(list.v_, subSize);

#   ifdef FULLDEBUG
	list.checkSize(subSize);
#   endif
}


template<class T>
inline void AutLib::SubList<T>::reset
(
	const UList<T>& list,
	const label subSize,
	const label startIndex
)
{
	UList<T>::reset(&(list.v_[startIndex]), subSize);

#   ifdef FULLDEBUG

	// Artificially allowing the start of a zero-sized subList to be
	// one past the end of the original list.
	if (subSize > 0)
	{
		list.checkStart(startIndex);
		list.checkSize(startIndex + subSize);
	}
	else
	{
		// Start index needs to fall between 0 and size.  One position
		// behind the last element is allowed
		list.checkSize(startIndex);
	}
#   endif
}


template<class T>
inline const AutLib::SubList<T>& AutLib::SubList<T>::null()
{
	return *reinterpret_cast<SubList<T>*>(0);
}

template<class T>
inline AutLib::SubList<T>::operator const AutLib::List<T>&() const
{
	// Dangerous, but no null constructor.  Reconsider.  HJ, 10/Apr/2013
	return *reinterpret_cast<const List<T>*>(this);
}


template<class T>
inline void AutLib::SubList<T>::operator=(const T& t)
{
	UList<T>::operator=(t);
}