#pragma once
#ifndef _PtrList_Header
#define _PtrList_Header

#include <List.hxx>

namespace AutLib
{
	template<class T> class SLPtrList;

	template<class T>
	class PtrList
	{
		// Private data

		List<T*> ptrs_;


	protected:

		// Protected member functions

		//- Read from Istream using given Istream constructor class
		template<class INew>
		void read(Istream&, const INew& inewt);


	public:

		// Constructors

		//- Null Constructor.
		PtrList();

		//- Construct with length specified.
		explicit PtrList(const label);

		//- Copy constructor.
		PtrList(const PtrList<T>&);

		//- Copy constructor with additional argument for clone
		template<class CloneArg>
		PtrList(const PtrList<T>&, const CloneArg&);

		//- Construct by transferring the parameter contents
		PtrList(const Xfer<PtrList<T> >&);

		//- Construct as copy or re-use as specified.
		PtrList(PtrList<T>&, bool reUse);

		//- Construct as copy of SLPtrList<T>
		PtrList(const SLPtrList<T>&);

		//- Construct from Istream using given Istream constructor class
		template<class INew>
		PtrList(Istream&, const INew&);

		//- Construct from Istream using default Istream constructor class
		PtrList(Istream&);


		// Destructor

		~PtrList();


		// Member functions

		// Access

		//- Return the number of elements in the PtrList
		label size() const;

		//- Return true if the PtrList is empty (ie, size() is zero).
		bool empty() const;


		// Edit

		//- Reset size of PtrList.  This can only be used to set the size
		//  of an empty PtrList, extend a PtrList, remove entries from
		//  the end of a PtrList. If the entries are non-empty they are
		//  deleted.
		void setSize(const label);

		//- Reset size of PtrList.  This can only be used to set the size
		//  of an empty PtrList, extend a PtrList, remove entries from
		//  the end of a PtrList. If the entries are non-empty they are
		//  deleted.
		void resize(const label);

		//- Clear the PtrList, i.e. set size to zero deleting all the
		//  allocated entries.
		void clear();

		//- Transfer the contents of the argument PtrList into this PtrList
		//  and annull the argument list.
		void transfer(PtrList<T>&);

		//- Transfer contents to the Xfer container
		Xfer<PtrList<T> > xfer();

		//- Is element set
		bool set(const label) const;

		//- Set element. Return old element (can be NULL).
		//  No checks on new element.
		autoPtr<T> set(const label, T*);
		autoPtr<T> set(const label, const autoPtr<T>&);
		autoPtr<T> set(const label, const tmp<T>&);

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


		//- Assignment.
		PtrList<T>& operator=(const PtrList<T>&);


		// STL type definitions

		//- Type of values the PtrList contains.
		typedef T value_type;

		//- Type that can be used for storing into PtrList::value_type objects.
		typedef T& reference;

		//- Type that can be used for storing into constant PtrList::value_type
		//  objects.
		typedef const T& const_reference;


		// STL iterator
		// Random access iterator for traversing PtrList.

		class iterator;
		friend class iterator;

		//- An STL-conforming iterator
		class iterator
		{
			T** ptr_;

		public:

			//- Construct for a given PtrList entry
			iterator(T**);

			// Member operators

			bool operator==(const iterator&) const;
			bool operator!=(const iterator&) const;

			typedef T& Tref;
			Tref operator*();
			Tref operator()();

			iterator operator++();
			iterator operator++(int);

			iterator operator--();
			iterator operator--(int);

			iterator operator+=(label);

			template<class T>
			friend iterator operator+(const iterator&, label);
			template<class T>
			friend iterator operator+(label, const iterator&);

			iterator operator-=(label);

			template<class T>
			friend iterator operator-(const iterator&, label);

			template<class T>
			friend label operator-(const iterator&, const iterator&);

			T& operator[](label);

			bool operator<(const iterator&) const;
			bool operator>(const iterator&) const;

			bool operator<=(const iterator&) const;
			bool operator>=(const iterator&) const;
		};

		//- Return an iterator to begin traversing the PtrList.
		iterator begin();

		//- Return an iterator to end traversing the PtrList.
		iterator end();


		// IOstream operator

		//- Read List from Istream, discarding contents of existing List.
		template<class T>
		friend Istream& operator>>(Istream&, PtrList<T>&);

		// Write List to Ostream.
		template<class T>
		friend Ostream& operator<<(Ostream&, const PtrList<T>&);
	};
}

#include <PtrListI.hxx>

#endif // !_PtrList_Header
