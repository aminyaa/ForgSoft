#pragma once
#ifndef _BiIndirectList_Header
#define _BiIndirectList_Header

#include <List.hxx>

namespace AutLib
{

	template<class T>
	class BiIndirectList
	{
		// Private data

		UList<T>& posList_;
		UList<T>& negList_;
		List<label> addressing_;


	public:

		// Constructors

		//- Construct given the complete lists and the addressing array
		BiIndirectList
		(
			const UList<T>& posList,
			const UList<T>& negList,
			const UList<label>&
		);


		// Member Functions

		// Access

		label size() const;
		bool  empty() const;

		const UList<T>& posList() const;
		const UList<T>& negList() const;
		const List<label>& addressing() const;
		List<label>& addressing();

		//- Calculate index given whether index is into posList or negList
		static label posIndex(const label);
		static label negIndex(const label);


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

#include <BiIndirectListI.hxx>

#endif // !_BiIndirectList_Header
