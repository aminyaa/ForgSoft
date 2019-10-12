#pragma once
#ifndef _UIndirectList_Header
#define _UIndirectList_Header

#include <List.hxx>

namespace AutLib
{

	template<class T>
	class UIndirectList
	{
		// Private data

		UList<T>& completeList_;
		const UList<label>& addressing_;


	public:

		// Constructors

		//- Construct given the complete list and the addressing array
		inline UIndirectList(const UList<T>&, const UList<label>&);


		// Member Functions

		// Access

		inline label size() const;
		inline bool  empty() const;

		inline const UList<T>& completeList() const;
		inline const List<label>& addressing() const;


		// Member Operators

		//- Return the addressed elements as a List
		inline List<T> operator()() const;

		//- Return non-const access to an element
		inline T& operator[](const label);

		//- Return const access to an element
		inline const T& operator[](const label) const;

		//- Assignment from UList of addressed elements
		inline void operator=(const UList<T>&);

		//- Assignment of all entries to the given value
		inline void operator=(const T&);


		// Ostream operator

		//- Write UIndirectList to Ostream
		//  Binary output is currently still a bit of a problem
		template<class T>
		friend Ostream& operator<<(Ostream&, const UIndirectList<T>&);
	};
}

#include <UIndirectListI.hxx>

#endif // !_UIndirectList_Header
