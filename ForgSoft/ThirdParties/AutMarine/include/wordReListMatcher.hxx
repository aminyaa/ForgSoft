#pragma once
#ifndef _wordReListMatcher_Header
#define _wordReListMatcher_Header

#include <wordList.hxx>
#include <wordRe.hxx>

namespace AutLib
{

	class wordReListMatcher
	{
		// Private data

		//- Reference to underlying list
		const UList<wordRe>& reList_;

	public:

		// Constructors

		//- Construct from a List of wordRe
		wordReListMatcher(const UList<wordRe>&);


		// Member Functions

		// Access

		label size() const;
		bool  empty() const;

		//- Return underlying list of wordRe
		const UList<wordRe>& operator()() const;


		// Searching

		//- Return true if string matches any of the regular expressions
		//  Smart match as regular expression or as a string.
		//  Optionally specify a literal match only.
		bool match(const string&, bool literalMatch = false) const;

	};
}

#include <wordReListMatcherI.hxx>

#endif // !_wordReListMatcher_Header
