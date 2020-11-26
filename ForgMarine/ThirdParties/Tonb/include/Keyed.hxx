#pragma once
#ifndef _Keyed_Header
#define _Keyed_Header

#include <List.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Forward declaration of friend functions and operators

	template<class T> class Keyed;

	template<class T> Istream& operator>>(Istream&, Keyed<T>&);
	template<class T> Ostream& operator<<(Ostream&, const Keyed<T>&);

	/*---------------------------------------------------------------------------*\
						   Class Keyed Declaration
	\*---------------------------------------------------------------------------*/

	template<class T>
	class Keyed
		:
		public T
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

		friend Istream& operator>> <T>(Istream&, Keyed<T>&);
		friend Ostream& operator<< <T>(Ostream&, const Keyed<T>&);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <KeyedI.hxx>

#endif // !_Keyed_Header
