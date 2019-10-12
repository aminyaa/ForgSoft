#pragma once
#ifndef _DynamicList_Header
#define _DynamicList_Header

#include <List.hxx>

namespace AutLib
{

	template<class T, unsigned SizeInc = 0, unsigned SizeMult = 2, unsigned SizeDiv = 1>
	class DynamicList
		: public List<T>
	{

		// Private data

		//- The capacity (allocated size) of the underlying list.
		label capacity_;

	public:

		// Related types

		//- Declare friendship with the List class
		friend class List<T>;

		// Constructors

		//- Construct null
		DynamicList();

		//- Construct given size.
		explicit DynamicList(const label);

		//- Construct copy
		DynamicList
		(
			const DynamicList<T, SizeInc, SizeMult, SizeDiv>&
		);

		//- Construct from UList. Size set to UList size.
		//  Also constructs from DynamicList with different sizing parameters.
		explicit DynamicList(const UList<T>&);

		//- Construct from UIndirectList. Size set to UIndirectList size.
		explicit DynamicList(const UIndirectList<T>&);

		//- Construct by transferring the parameter contents
		explicit DynamicList(const Xfer< List<T> >&);

		//- Construct from Istream. Size set to size of read list.
		explicit DynamicList(Istream&);


		// Member Functions

		// Access

		//- Size of the underlying storage.
		label capacity() const;

		// Edit

		//- Alter the size of the underlying storage.
		//  The addressed size will be truncated if needed to fit, but will
		//  remain otherwise untouched.
		//  Use this or reserve() in combination with append().
		void setCapacity(const label);

		//- Alter the addressed list size.
		//  New space will be allocated if required.
		//  Use this to resize the list prior to using the operator[] for
		//  setting values (as per List usage).
		void setSize(const label);

		//- Alter the addressed list size and fill new space with a constant.
		void setSize(const label, const T&);

		//- Alter the addressed list size.
		//  New space will be allocated if required.
		//  Use this to resize the list prior to using the operator[] for
		//  setting values (as per List usage).
		void resize(const label);

		//- Alter the addressed list size and fill new space with a constant.
		void resize(const label, const T&);

		//- Reserve allocation space for at least this size.
		//  Never shrinks the allocated size, use setCapacity() for that.
		void reserve(const label);

		//- Clear the addressed list, i.e. set the size to zero.
		//  Allocated size does not change
		void clear();

		//- Clear the list and delete storage.
		void clearStorage();

		//- Shrink the allocated space to the number of elements used.
		//  Returns a reference to the DynamicList.
		DynamicList<T, SizeInc, SizeMult, SizeDiv>& shrink();

		//- Transfer contents of the argument List into this DynamicList
		void transfer(List<T>&);

		//- Transfer contents of the argument DynamicList into this DynamicList
		void transfer(DynamicList<T, SizeInc, SizeMult, SizeDiv>&);

		//- Transfer contents to the Xfer container as a plain List
		Xfer< List<T> > xfer();

		// Member Operators

		//- Append an element at the end of the list
		void append(const T&);

		//- Append a List at the end of this list
		void append(const UList<T>&);

		//- Append a UIndirectList at the end of this list
		void append(const UIndirectList<T>&);

		//- Remove and return the top element
		T remove();

		//- Return non-const access to an element, resizing list if necessary
		T& operator()(const label);

		//- Assignment of all addressed entries to the given value
		void operator=(const T&);

		//- Assignment from DynamicList
		void operator=(const DynamicList<T, SizeInc, SizeMult, SizeDiv>&);

		//- Assignment from UList
		void operator=(const UList<T>&);

		template<class T, unsigned SizeInc, unsigned SizeMult, unsigned SizeDiv>
		friend Ostream& operator<<(Ostream&, const DynamicList<T, SizeInc, SizeMult, SizeDiv>&);

		template<class T, unsigned SizeInc, unsigned SizeMult, unsigned SizeDiv>
		friend Istream& operator>>(Istream&, DynamicList<T, SizeInc, SizeMult, SizeDiv>&);
	};
}

#include <DynamicListI.hxx>

#endif // !_DynamicList_Header
