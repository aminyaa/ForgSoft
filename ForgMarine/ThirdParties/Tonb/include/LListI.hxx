#pragma once

#include <error.hxx>
#include <OSstream.hxx>

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class LListBase, class T>
tnbLib::LList<LListBase, T>::LList(const LList<LListBase, T>& lst)
	:
	LListBase()
{
	for (const_iterator iter = lst.begin(); iter != lst.end(); ++iter)
	{
		this->append(iter());
	}
}


template<class LListBase, class T>
tnbLib::LList<LListBase, T>::~LList()
{
	this->clear();
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class LListBase, class T>
void tnbLib::LList<LListBase, T>::clear()
{
	label oldSize = this->size();
	for (label i = 0; i < oldSize; ++i)
	{
		this->removeHead();
	}

	LListBase::clear();
}


template<class LListBase, class T>
void tnbLib::LList<LListBase, T>::transfer(LList<LListBase, T>& lst)
{
	clear();
	LListBase::transfer(lst);
}


// * * * * * * * * * * * * * * * Member Operators  * * * * * * * * * * * * * //

template<class LListBase, class T>
void tnbLib::LList<LListBase, T>::operator=(const LList<LListBase, T>& lst)
{
	this->clear();

	for (const_iterator iter = lst.begin(); iter != lst.end(); ++iter)
	{
		this->append(iter());
	}
}


// * * * * * * * * * * * * * * * Friend Operators  * * * * * * * * * * * * * //


#include <Istream.hxx>
#include <Ostream.hxx>

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class LListBase, class T>
tnbLib::LList<LListBase, T>::LList(Istream& is)
{
	operator>>(is, *this);
}


// * * * * * * * * * * * * * * * Istream Operator  * * * * * * * * * * * * * //

template<class LListBase, class T>
tnbLib::Istream& tnbLib::operator>>(Istream& is, LList<LListBase, T>& L)
{
	// A null list
	L.clear();

	is.fatalCheck(" operator>>(Istream&, LList<LListBase, T>&)");

	token firstToken(is);

	is.fatalCheck
	(
		" operator>>(Istream&, LList<LListBase, T>&) : reading first token"
	);

	if (firstToken.isLabel())
	{
		label s = firstToken.labelToken();

		// Read beginning of contents
		char delimiter = is.readBeginList("LList<LListBase, T>");

		if (s)
		{
			if (delimiter == token::BEGIN_LIST)
			{
				for (label i = 0; i < s; ++i)
				{
					T element;
					is >> element;
					L.append(element);
				}
			}
			else
			{
				T element;
				is >> element;

				for (label i = 0; i < s; ++i)
				{
					L.append(element);
				}
			}
		}

		// Read end of contents
		is.readEndList("LList");
	}
	else if (firstToken.isPunctuation())
	{
		if (firstToken.pToken() != token::BEGIN_LIST)
		{
			FatalIOErrorIn
			(
				" operator>>(Istream&, LList<LListBase, T>&)",
				is
			) << "incorrect first token, '(', found " << firstToken.info()
				<< exit(FatalIOError);
		}

		token lastToken(is);
		is.fatalCheck(" operator>>(Istream&, LList<LListBase, T>&)");

		while
			(
				!(
					lastToken.isPunctuation()
					&& lastToken.pToken() == token::END_LIST
					)
				)
		{
			is.putBack(lastToken);
			T element;
			is >> element;
			L.append(element);

			is >> lastToken;
			is.fatalCheck(" operator>>(Istream&, LList<LListBase, T>&)");
		}
	}
	else
	{
		FatalIOErrorIn(" operator>>(Istream&, LList<LListBase, T>&)", is)
			<< "incorrect first token, expected <int> or '(', found "
			<< firstToken.info()
			<< exit(FatalIOError);
	}

	// Check state of IOstream
	is.fatalCheck(" operator>>(Istream&, LList<LListBase,>&)");

	return is;
}


// * * * * * * * * * * * * * * * Ostream Operator  * * * * * * * * * * * * * //

template<class LListBase, class T>
tnbLib::Ostream& tnbLib::operator<<(Ostream& os, const LList<LListBase, T>& lst)
{
	// Write size
	os << nl << lst.size();

	// Write beginning of contents
	os << nl << token::BEGIN_LIST << nl;

	// Write contents
	for
		(
			typename LList<LListBase, T>::const_iterator iter = lst.begin();
			iter != lst.end();
			++iter
			)
	{
		os << iter() << nl;
	}

	// Write end of contents
	os << token::END_LIST;

	// Check state of IOstream
	os.check("Ostream& operator<<(Ostream&, const LList<LListBase, T>&)");

	return os;
}


// ************************************************************************* //