#pragma once
#ifndef _SubList_Header
#define _SubList_Header

#include <List.hxx>
#include <UList.hxx>

namespace AutLib
{
	template<class T>
	class List;

	template<class T>
	class SubList
		: public UList<T>
	{

	public:

		// Static Member Functions

		//- Return a null SubList
		//  Dangerous, but no null constructor.  Reconsider.  HJ, 10/Apr/2013
		static const SubList<T>& null();

		// Constructors

		//- Construct from UList and sub-list size
		SubList
		(
			const UList<T>& list,
			const label subSize
		);

		//- Construct from UList, sub-list size and start index
		SubList
		(
			const UList<T>& list,
			const label subSize,
			const label startIndex
		);


		// Member functions

		//- Reset the SubList
		//- Construct from UList and SubList size
		void reset
		(
			const UList<T>& list,
			const label subSize
		);

		//- Construct from UList, start and end indices
		void reset
		(
			const UList<T>& list,
			const label subSize,
			const label startIndex
		);


		// Member operators

		//- Allow cast to a const List<T>&
		operator const AutLib::List<T>&() const;

		//- Assignment of all entries to the given value
		void operator=(const T&);
	};


	template<class T>
	class SubList1
		: public UList<T>
	{

	public:

		

		
	};
}

#include <SubListI.hxx>

#endif // !_SubList_Header
