#pragma once
#ifndef _UIndirectList_Header
#define _UIndirectList_Header

#include <List.hxx>

namespace tnbLib
{

	// Forward declaration of friend functions and operators
	template<class T> class UIndirectList;
	template<class T> Ostream& operator<<(Ostream&, const UIndirectList<T>&);

	/*---------------------------------------------------------------------------*\
							Class UIndirectList Declaration
	\*---------------------------------------------------------------------------*/

	template<class T>
	class UIndirectList
	{
		// Private data

		UList<T>& completeList_;
		const UList<label>& addressing_;


	public:

		// Constructors

			//- Construct given the complete list and the addressing array
		UIndirectList(const UList<T>&, const UList<label>&);


		// Member Functions

			// Access

		label size() const;
		bool  empty() const;

		const UList<T>& completeList() const;
		const List<label>& addressing() const;


		// Member Operators

			//- Return the addressed elements as a List
		List<T> operator()() const;

		//- Return non-const access to an element
		T& operator[](const label);

		//- Return const access to an element
		const T& operator[](const label) const;

		//- Assignment from UList of addressed elements
		void operator=(const UList<T>&);

		//- Assignment of all entries to the given value
		void operator=(const T&);


		// Ostream operator

			//- Write UIndirectList to Ostream
			//  Binary output is currently still a bit of a problem
		friend Ostream& operator<< <T>
			(
				Ostream&,
				const UIndirectList<T>&
				);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#include <UIndirectListI.hxx>

#ifdef NoRepository
#   include "UIndirectListIO.cxx"
#endif

#endif // !_UIndirectList_Header
