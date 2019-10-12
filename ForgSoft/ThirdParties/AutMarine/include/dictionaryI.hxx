#pragma once
#include <primitiveEntry.hxx>
template<class T>
T AutLib::dictionary::lookupOrDefault
(
	const word& keyword,
	const T& deflt,
	bool recursive,
	bool patternMatch
) const
{
	const entry* entryPtr = lookupEntryPtr(keyword, recursive, patternMatch);

	if (entryPtr)
	{
		return pTraits<T>(entryPtr->stream());
	}
	else
	{
		return deflt;
	}
}


template<class T>
T AutLib::dictionary::lookupOrAddDefault
(
	const word& keyword,
	const T& deflt,
	bool recursive,
	bool patternMatch
)
{
	const entry* entryPtr = lookupEntryPtr(keyword, recursive, patternMatch);

	if (entryPtr)
	{
		return pTraits<T>(entryPtr->stream());
	}
	else
	{
		add(new primitiveEntry(keyword, deflt));
		return deflt;
	}
}


template<class T>
bool AutLib::dictionary::readIfPresent
(
	const word& k,
	T& val,
	bool recursive,
	bool patternMatch
) const
{
	const entry* entryPtr = lookupEntryPtr(k, recursive, patternMatch);

	if (entryPtr)
	{
		entryPtr->stream() >> val;
		return true;
	}
	else
	{
		return false;
	}
}


template<class T>
void AutLib::dictionary::add(const keyType& k, const T& t, bool overwrite)
{
	add(new primitiveEntry(k, t), overwrite);
}


template<class T>
void AutLib::dictionary::set(const keyType& k, const T& t)
{
	set(new primitiveEntry(k, t));
}