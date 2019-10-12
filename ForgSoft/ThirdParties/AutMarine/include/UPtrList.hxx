#pragma once
#ifndef _UPtrList_Header
#define _UPtrList_Header

#include <List.hxx>

namespace AutLib
{

	template<class T>
	class UPtrList
	{
		// Private data

		List<T*> ptrs_;


	public:

		// Constructors

		//- Null Constructor.
		UPtrList();

		//- Construct with length specified.
		explicit UPtrList(const label);

		//- Construct by transferring the parameter contents
		UPtrList(const Xfer<UPtrList<T> >&);

		//- Construct as copy or re-use as specified.
		UPtrList(UPtrList<T>&, bool reUse);


		// Member functions

		// Access

		//- Return the number of elements in the UPtrList
		label size() const;

		//- Return true if the UPtrList is empty (ie, size() is zero).
		bool empty() const;


		// Edit

		//- Reset size of UPtrList.  This can only be used to set the size
		//  of an empty UPtrList, extend a UPtrList, remove entries from
		//  the end of a UPtrList.
		void setSize(const label);

		//- Reset size of UPtrList.  This can only be used to set the size
		//  of an empty UPtrList, extend a UPtrList, remove entries from
		//  the end of a UPtrList.
		void resize(const label);

		//- Clear the UPtrList, i.e. set size to zero
		void clear();

		//- Transfer the contents of the argument UPtrList into this
		//  UPtrList and annull the argument list.
		void transfer(UPtrList<T>&);

		//- Transfer contents to the Xfer container
		Xfer<UPtrList<T> > xfer();

		//- Is element set
		bool set(const label) const;

		//- Set element. Return old element (can be NULL).
		//  No checks on new element.
		T* set(const label, T*);

		//- Reorders elements. Ordering does not have to be done in
		//  ascending or descending order. Reordering has to be unique.
		//  (is shuffle)
		void reorder(const UList<label>&);


		// Member operators

		//- Return element const reference.
		const T& operator[](const label) const;

		//- Return element reference.
		T& operator[](const label);

		//- Return element const pointer.
		const T* operator()(const label) const;


		// STL type definitions

		//- Type of values the UPtrList contains.
		typedef T value_type;

		//- Type that can be used for storing into UPtrList::value_type objects
		typedef T& reference;

		//- Type that can be used for storing into constant
		//  UPtrList::value_type objects.
		typedef const T& const_reference;


		// STL iterator
		// Random access iterator for traversing UPtrList.

		class iterator;
		friend class iterator;

		//- An STL iterator
		class iterator
		{
			T** ptr_;

		public:

			//- Construct for a given UPtrList entry
			iterator(T**);

			// Member operators

			bool operator==(const iterator&) const;
			bool operator!=(const iterator&) const;

			T& operator*();
			T& operator()();

			iterator operator++();
			iterator operator++(int);

			iterator operator--();
			iterator operator--(int);

			iterator operator+=(label);

			friend iterator operator+ <T>(const iterator&, label);
			friend iterator operator+ <T>(label, const iterator&);

			iterator operator-=(label);

			friend iterator operator- <T>(const iterator&, label);

			friend label operator- <T>
				(
					const iterator&,
					const iterator&
					);

			T& operator[](label);

			bool operator<(const iterator&) const;
			bool operator>(const iterator&) const;

			bool operator<=(const iterator&) const;
			bool operator>=(const iterator&) const;
		};

		//- Return an iterator to begin traversing the UPtrList.
		iterator begin();

		//- Return an iterator to end traversing the UPtrList.
		iterator end();


		// IOstream operator

		// Write List to Ostream.
		template<class T>
		friend Ostream& operator<<(Ostream&, const UPtrList<T>&);
	};
}

#include <UPtrListI.hxx>

#endif // !_UPtrList_Header
