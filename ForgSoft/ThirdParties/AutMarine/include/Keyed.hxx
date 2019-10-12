#pragma once
#ifndef _Keyed_Header
#define _Keyed_Header

#include <List.hxx>

namespace AutLib
{

	template<class T>
	class Keyed
		: public T
	{

		// Private data

		label key_;

	public:

		// Static Members

		//- Add labels to a list of values
		static List<Keyed<T> > createList
		(
			const List<T>&,
			const label key = 0
		);

		//- Add labels to a list of values
		static List<Keyed<T> > createList
		(
			const List<T>&,
			const List<label>& keys
		);


		// Constructors

		//- Construct null
		Keyed();

		//- Construct as a copy of item, with a key
		Keyed(const T& item, const label key = 0);

		//- Construct by transferring the item, with a key
		Keyed(const Xfer<T>& item, const label key = 0);

		//- Construct from Istream
		Keyed(Istream&);


		// Member Functions

		// Access

		//- Return const access to the integer key
		label key() const;

		//- Return non-const access to the integer key
		label& key();


		// IOstream Operators
		template<class T>
		friend Istream& operator>>(Istream&, Keyed<T>&);
		template<class T>
		friend Ostream& operator<<(Ostream&, const Keyed<T>&);
	};
}

#include <KeyedI.hxx>

#endif // !_Keyed_Header
