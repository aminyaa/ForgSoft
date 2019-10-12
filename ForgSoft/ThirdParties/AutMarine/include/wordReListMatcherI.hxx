#pragma once
inline 
AutLib::wordReListMatcher::wordReListMatcher(const UList<wordRe>& lst)
	: reList_(lst)
{}

inline 
AutLib::label AutLib::wordReListMatcher::size() const
{
	return reList_.size();
}


inline 
bool AutLib::wordReListMatcher::empty() const
{
	return reList_.empty();
}


inline 
const AutLib::UList<AutLib::wordRe>& AutLib::wordReListMatcher::operator()() const
{
	return reList_;
}


inline 
bool AutLib::wordReListMatcher::match(const string& str, bool literalMatch) const
{
	const label nElem = reList_.size();
	for (label elemI = 0; elemI < nElem; ++elemI)
	{
		if (reList_[elemI].match(str, literalMatch))
		{
			return true;
		}
	}

	return false;
}