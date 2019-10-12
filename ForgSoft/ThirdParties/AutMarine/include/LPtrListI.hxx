#pragma once
#include <Istream.hxx>
#include <INew.hxx>
template<class LListBase, class T>
AutLib::LPtrList<LListBase, T>::LPtrList(const LPtrList<LListBase, T>& lst)
	: LList<LListBase, T*>()
{
	for (const_iterator iter = lst.begin(); iter != lst.end(); ++iter)
	{
		this->append(iter().clone().ptr());
	}
}

template<class LListBase, class T>
AutLib::LPtrList<LListBase, T>::~LPtrList()
{
	this->clear();
}

template<class LListBase, class T>
bool AutLib::LPtrList<LListBase, T>::eraseHead()
{
	T* tPtr;
	if ((tPtr = this->removeHead()))
	{
		delete tPtr;
		return true;
	}
	else
	{
		return false;
	}
}


template<class LListBase, class T>
void AutLib::LPtrList<LListBase, T>::clear()
{
	const label oldSize = this->size();
	for (label i = 0; i < oldSize; ++i)
	{
		eraseHead();
	}

	LList<LListBase, T*>::clear();
}


template<class LListBase, class T>
void AutLib::LPtrList<LListBase, T>::transfer(LPtrList<LListBase, T>& lst)
{
	clear();
	LList<LListBase, T*>::transfer(lst);
}

template<class LListBase, class T>
void AutLib::LPtrList<LListBase, T>::operator=(const LPtrList<LListBase, T>& lst)
{
	clear();

	for (const_iterator iter = lst.begin(); iter != lst.end(); ++iter)
	{
		this->append(iter().clone().ptr());
	}
}

template<class LListBase, class T>
template<class INew>
void AutLib::LPtrList<LListBase, T>::read(Istream& is, const INew& iNew)
{
	is.fatalCheck
	(
		"LPtrList<LListBase, T>::read(Istream&, const INew&)"
	);

	token firstToken(is);

	is.fatalCheck
	(
		"LPtrList<LListBase, T>::read(Istream&, const INew&) : "
		"reading first token"
	);

	if (firstToken.isLabel())
	{
		label s = firstToken.labelToken();

		// Read beginning of contents
		char delimiter = is.readBeginList("LPtrList<LListBase, T>");

		if (s)
		{
			if (delimiter == token::BEGIN_LIST)
			{
				for (label i = 0; i < s; ++i)
				{
					this->append(iNew(is).ptr());

					is.fatalCheck
					(
						"LPtrList<LListBase, T>::read(Istream&, const INew&) : "
						"reading entry"
					);
				}
			}
			else
			{
				T* tPtr = iNew(is).ptr();
				this->append(tPtr);

				is.fatalCheck
				(
					"LPtrList<LListBase, T>::read(Istream&, const INew&) : "
					"reading entry"
				);

				for (label i = 1; i < s; ++i)
				{
					this->append(tPtr->clone().ptr());
				}
			}
		}

		// Read end of contents
		is.readEndList("LPtrList<LListBase, T>");
	}
	else if (firstToken.isPunctuation())
	{
		if (firstToken.pToken() != token::BEGIN_LIST)
		{
			FatalIOErrorIn
			(
				"LPtrList<LListBase, T>::read(Istream&, const INew&)",
				is
			) << "incorrect first token, '(', found " << firstToken.info()
				<< exit(FatalIOError);
		}

		token lastToken(is);
		is.fatalCheck("LPtrList<LListBase, T>::read(Istream&, const INew&)");

		while
			(
				!(
					lastToken.isPunctuation()
					&& lastToken.pToken() == token::END_LIST
					)
				)
		{
			is.putBack(lastToken);
			this->append(iNew(is).ptr());

			is >> lastToken;
			is.fatalCheck
			(
				"LPtrList<LListBase, T>::read(Istream&, const INew&)"
			);
		}
	}
	else
	{
		FatalIOErrorIn
		(
			"LPtrList<LListBase, T>::read(Istream&, const INew&)",
			is
		) << "incorrect first token, expected <int> or '(', found "
			<< firstToken.info()
			<< exit(FatalIOError);
	}

	is.fatalCheck("LPtrList<LListBase, T>::read(Istream&, const INew&)");
}

template<class LListBase, class T>
template<class INew>
AutLib::LPtrList<LListBase, T>::LPtrList(Istream& is, const INew& iNew)
{
	this->read(is, iNew);
}


template<class LListBase, class T>
AutLib::LPtrList<LListBase, T>::LPtrList(Istream& is)
{
	this->read(is, INew<T>());
}

namespace AutLib
{
	template<class LListBase, class T>
	Istream& operator>>(Istream& is, LPtrList<LListBase, T>& L)
	{
		L.clear();
		L.read(is, INew<T>());

		return is;
	}

	template<class LListBase, class T>
	Ostream& operator<<(Ostream& os, const LPtrList<LListBase, T>& lst)
	{
		// Write size
		os << nl << lst.size();

		// Write beginning of contents
		os << nl << token::BEGIN_LIST << nl;

		// Write contents
		for
			(
				typename LPtrList<LListBase, T>::const_iterator iter = lst.begin();
				iter != lst.end();
				++iter
				)
		{
			os << iter() << nl;
		}

		// Write end of contents
		os << token::END_LIST;

		// Check state of IOstream
		os.check("Ostream& operator<<(Ostream&, const LPtrList<LListBase, T>&)");

		return os;
	}
}