#pragma once

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class LListBase, class T>
tnbLib::UILList<LListBase, T>::UILList(const UILList<LListBase, T>& lst)
{
	for (const_iterator iter = lst.begin(); iter != lst.end(); ++iter)
	{
		this->append(&iter());
	}
}


// * * * * * * * * * * * * * * * Member Operators  * * * * * * * * * * * * * //

template<class LListBase, class T>
void tnbLib::UILList<LListBase, T>::operator=(const UILList<LListBase, T>& rhs)
{
	LListBase::clear();

	for (const_iterator iter = rhs.begin(); iter != rhs.end(); ++iter)
	{
		this->append(&iter());
	}
}


template<class LListBase, class T>
bool tnbLib::UILList<LListBase, T>::operator==
(
	const UILList<LListBase, T>& rhs
	) const
{
	if (this->size() != rhs.size())
	{
		return false;
	}

	bool equal = true;

	const_iterator iter1 = this->begin();
	const_iterator iter2 = rhs.begin();

	for (; iter1 != this->end(); ++iter1, ++iter2)
	{
		equal = equal && iter1() == iter2();
	}

	return equal;
}


// Comparison for inequality
template<class LListBase, class T>
bool tnbLib::UILList<LListBase, T>::operator!=
(
	const UILList<LListBase, T>& rhs
	) const
{
	return !operator==(rhs);
}


// * * * * * * * * * * * * * * * Friend Operators  * * * * * * * * * * * * * //


#include <Ostream.hxx>
#include <token.hxx>

// * * * * * * * * * * * * * * * Ostream Operator  * * * * * * * * * * * * * //

template<class LListBase, class T>
tnbLib::Ostream& tnbLib::operator<<(Ostream& os, const UILList<LListBase, T>& lst)
{
	// Write size
	os << nl << lst.size();

	// Write beginning of contents
	os << nl << token::BEGIN_LIST << nl;

	// Write contents
	for
		(
			typename UILList<LListBase, T>::const_iterator iter = lst.begin();
			iter != lst.end();
			++iter
			)
	{
		os << iter() << nl;
	}

	// Write end of contents
	os << token::END_LIST;

	// Check state of IOstream
	os.check("Ostream& operator<<(Ostream&, const UILList<LListBase, T>&)");

	return os;
}

// ************************************************************************* //