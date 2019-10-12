#pragma once
#include <sys/types.h>
#define PCRE_STATIC
#include <pcre.h>
#include <pcreposix.h>
namespace AutLib
{

	template<class StringList>
	inline labelList findStrings(const string& regexp, const StringList& sl)
	{
		labelList matches(sl.size());

		regex_t *preg = new regex_t;

		if (regcomp(preg, regexp.c_str(), REG_EXTENDED) != 0)
		{
			WarningIn("findStrings(const string& regexp, const stringList& sl)")
				<< "Failed to compile regular expression " << regexp
				<< endl;

			return matches;
		}

		size_t nmatch = 1;
		regmatch_t pmatch[1];

		label matchi = 0;
		for (label i = 0; i < (sl).size(); i++)
		{
			if (regexec(preg, sl[i].c_str(), nmatch, pmatch, 0) == 0 && (pmatch[0].rm_so == 0 && pmatch[0].rm_eo == label(sl[i].size())))
			{
				matches[matchi++] = i;
			}
		}

		matches.setSize(matchi);

		regfree(preg);
		delete preg;

		return matches;
	}
}

template<class Matcher, class StringType>
AutLib::labelList AutLib::findMatchingStrings
(
	const Matcher& matcher,
	const UList<StringType>& lst,
	const bool invert
)
{
	labelList indices(lst.size());

	label nElem = 0;
	for (label elemI = 0; elemI < (lst).size(); elemI++)
	{
		if (matcher.match(lst[elemI]) ? !invert : invert)
		{
			indices[nElem++] = elemI;
		}
	}
	indices.setSize(nElem);

	return indices;
}


template<class Matcher, class StringListType>
StringListType AutLib::subsetMatchingStrings
(
	const Matcher& matcher,
	const StringListType& lst,
	const bool invert
)
{
	StringListType newLst(lst.size());

	label nElem = 0;
	for (label elemI = 0; elemI < (lst).size(); elemI++)
	{
		if (matcher.match(lst[elemI]) ? !invert : invert)
		{
			newLst[nElem++] = lst[elemI];
		}
	}
	newLst.setSize(nElem);

	return newLst;
}


template<class Matcher, class StringListType>
void AutLib::inplaceSubsetMatchingStrings
(
	const Matcher& matcher,
	StringListType& lst,
	const bool invert
)
{
	label nElem = 0;
	for (label elemI = 0; elemI < (lst).size(); elemI++)
	{
		if (matcher.match(lst[elemI]) ? !invert : invert)
		{
			lst[nElem++] = lst[elemI];
		}
	}
	lst.setSize(nElem);
}