#pragma once
#include <Istream.hxx>
template<class T>
inline AutLib::Keyed<T>::Keyed()
	: key_(-1)
{}

template<class T>
inline AutLib::Keyed<T>::Keyed(const T& item, const label key)
	: T(item)
	, key_(key)
{}

template<class T>
inline AutLib::Keyed<T>::Keyed(const Xfer<T>& item, const label key)
	: T(item)
	, key_(key)
{}

template<class T>
inline AutLib::Keyed<T>::Keyed(Istream& is)
{
	is >> *this;
}

template<class T>
inline AutLib::label AutLib::Keyed<T>::key() const
{
	return key_;
}

template<class T>
inline AutLib::label& AutLib::Keyed<T>::key()
{
	return key_;
}


template<class T>
inline AutLib::List<AutLib::Keyed<T> >
AutLib::Keyed<T>::createList(const List<T>& lst, const label key)
{
	List<Keyed<T> > newList(lst.size());

	for (label elemI = 0; elemI < (lst).size(); elemI++)
	{
		newList[elemI] = Keyed(lst[elemI], key);
	}
	return newList;
}


template<class T>
inline AutLib::List<AutLib::Keyed<T> >
AutLib::Keyed<T>::createList(const List<T>& lst, const List<label>& keys)
{
	if (lst.size() != keys.size())
	{
		FatalErrorIn
		(
			"AutLib::Keyed<T>::createList(const List<T>&, const List<label>&)"
		)
			<< "size mismatch adding keys to a list:" << nl
			<< "List has size " << lst.size()
			<< " and keys has size " << keys.size() << nl
			<< abort(FatalError);
	}

	List<Keyed<T> > newList(lst.size());

	for (label elemI = 0; elemI < (lst).size(); elemI++)
	{
		newList[elemI] = Keyed(lst[elemI], keys[elemI]);
	}
	return newList;
}

namespace AutLib
{
	template<class T>
	inline AutLib::Istream& operator>>(Istream& is, Keyed<T>& item)
	{
		// Read beginning of Keyed item/key pair
		is.readBegin("Keyed<T>");

		is >> static_cast<T&>(item);
		is >> item.key_;

		// Read end of Keyed item/key pair
		is.readEnd("Keyed<T>");

		// Check state of Ostream
		is.check("Istream& operator>>(Istream&, Keyed&)");

		return is;
	}


	template<class T>
	inline AutLib::Ostream& operator<<(Ostream& os, const Keyed<T>& item)
	{
		os << token::BEGIN_LIST
			<< static_cast<const T&>(item)
			<< token::SPACE << item.key_
			<< token::END_LIST;

		return os;
	}
}