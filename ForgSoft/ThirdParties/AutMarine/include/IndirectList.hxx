#pragma once
#ifndef _IndirectList_Header
#define _IndirectList_Header

#include <List.hxx>

namespace AutLib
{

	template<class T>
	class IndirectList
	{
		// Private data

		UList<T>& completeList_;
		List<label> addressing_;


	public:

		// Constructors

		//- Construct given the complete list and the addressing array
		IndirectList(const UList<T>&, const UList<label>&);


		// Member Functions

		// Access

		label size() const;
		bool  empty() const;

		const UList<T>& completeList() const;
		const List<label>& addressing() const;

		// Edit

		//- Reset addressing
		void resetAddressing(const UList<label>&);


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
	};
}

#include <IndirectListI.hxx>

#endif // !_IndirectList_Header
