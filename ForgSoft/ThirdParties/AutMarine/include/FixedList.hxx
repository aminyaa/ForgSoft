#pragma once
#ifndef _FixedList_Header
#define _FixedList_Header

#include <label.hxx>
#include <autoPtr.hxx>
#include <StaticAssert.hxx>
#include <Hash.hxx>

namespace AutLib
{

	template<class T> class UList;
	template<class T> class SLList;

	template<class T, unsigned Size>
	class FixedList
	{
#ifndef SWIG
		//- Size must be positive (non-zero) and also fit as a signed value
		StaticAssert(Size && Size <= INT_MAX);
#endif

		// Private data

		//- Vector of values of type T of size Size.
		T v_[Size];

	public:

		//- Hashing function class.
		//  Use Hasher directly for contiguous data. Otherwise hash incrementally.
		template< class HashT = Hash<T> >
		class Hash
		{
		public:

			Hash()
			{}

			unsigned operator()(const FixedList<T, Size>&, unsigned seed = 0) const;
		};

		// Static data members

		//- Empty list
		static const FixedList<T, Size> zero;


		// Static Member Functions

		//- Return a null FixedList
		static const FixedList<T, Size>& null();


		// Constructors

		//- Null constructor.
		FixedList();

		//- Construct from components
		FixedList(const T v[Size]);

		//- Construct from value
		explicit FixedList(const T&);

		//- Construct from UList.
		FixedList(const UList<T>&);

		//- Construct from SLList.
		FixedList(const SLList<T>&);

		//- Copy constructor.
		FixedList(const FixedList<T, Size>&);

		//- Construct from Istream.
		FixedList(Istream&);

		//- Clone
		autoPtr< FixedList<T, Size> > clone() const;


		// Member Functions

		// Access

		//- Return the forward circular index, i.e. the next index
		//  which returns to the first at the end of the list
		label fcIndex(const label i) const;

		//- Return the reverse circular index, i.e. the previous index
		//  which returns to the last at the beginning of the list
		label rcIndex(const label i) const;


		//- Return a const pointer to the first data element,
		//  similar to the STL front() method and the string::data() method
		//  This can be used (with caution) when interfacing with C code.
		const T* cdata() const;

		//- Return a pointer to the first data element,
		//  similar to the STL front() method and the string::data() method
		//  This can be used (with caution) when interfacing with C code.
		T* data();


		// Check

		//- Check start is within valid range (0 ... size-1).
		void checkStart(const label start) const;

		//- Check size is within valid range (0 ... size).
		void checkSize(const label size) const;

		//- Check index i is within valid range (0 ... size-1).
		void checkIndex(const label i) const;


		// Edit

		//- Dummy resize function
		//  needed to make FixedList consistent with List
		void resize(const label);

		//- Dummy setSize function
		//  needed to make FixedList consistent with List
		void setSize(const label);

		//- Copy (not transfer) the argument contents
		//  needed to make FixedList consistent with List
		void transfer(const FixedList<T, Size>&);

		//- Write the FixedList as a dictionary entry
		void writeEntry(Ostream&) const;

		//- Write the FixedList as a dictionary entry with keyword
		void writeEntry(const word& keyword, Ostream&) const;


		// Member operators

		//- Return element of FixedList.
		T& operator[](const label);

		//- Return element of constant FixedList.
		const T& operator[](const label) const;

		//- Assignment from array operator. Takes linear time.
		void operator=(const T v[Size]);

		//- Assignment from UList operator. Takes linear time.
		void operator=(const UList<T>&);

		//- Assignment from SLList operator. Takes linear time.
		void operator=(const SLList<T>&);

		//- Assignment of all entries to the given value
		void operator=(const T&);


		// STL type definitions

		//- Type of values the FixedList contains.
		typedef T value_type;

		//- Type that can be used for storing into
		//  FixedList::value_type objects.
		typedef T& reference;

		//- Type that can be used for storing into
		//  constant FixedList::value_type objects
		typedef const T& const_reference;

		//- The type that can represent the difference between any two
		//  FixedList iterator objects.
		typedef label difference_type;

		//- The type that can represent the size of a FixedList.
		typedef label size_type;


		// STL iterator

		//- Random access iterator for traversing FixedList.
		typedef T* iterator;

		//- Return an iterator to begin traversing the FixedList.
		iterator begin();

		//- Return an iterator to end traversing the FixedList.
		iterator end();


		// STL const_iterator

		//- Random access iterator for traversing FixedList.
		typedef const T* const_iterator;

		//- Return const_iterator to begin traversing the constant FixedList.
		const_iterator cbegin() const;

		//- Return const_iterator to end traversing the constant FixedList.
		const_iterator cend() const;

		//- Return const_iterator to begin traversing the constant FixedList.
		const_iterator begin() const;

		//- Return const_iterator to end traversing the constant FixedList.
		const_iterator end() const;


		// STL reverse_iterator

		//- Reverse iterator for reverse traversal of FixedList.
		typedef T* reverse_iterator;

		//- Return reverse_iterator to begin reverse traversing the FixedList.
		reverse_iterator rbegin();

		//- Return reverse_iterator to end reverse traversing the FixedList.
		reverse_iterator rend();


		// STL const_reverse_iterator

		//- Reverse iterator for reverse traversal of constant FixedList.
		typedef const T* const_reverse_iterator;

		//- Return const_reverse_iterator to begin reverse traversing FixedList.
		const_reverse_iterator crbegin() const;

		//- Return const_reverse_iterator to end reverse traversing FixedList.
		const_reverse_iterator crend() const;

		//- Return const_reverse_iterator to begin reverse traversing FixedList.
		const_reverse_iterator rbegin() const;

		//- Return const_reverse_iterator to end reverse traversing FixedList.
		const_reverse_iterator rend() const;


		// STL member functions

		//- Return the number of elements in the FixedList.
		label size() const;

		//- Return size of the largest possible FixedList.
		label max_size() const;

		//- Return true if the FixedList is empty (ie, size() is zero).
		bool empty() const;

		//- Swap two FixedLists of the same type in constant time.
		void swap(FixedList<T, Size>&);


		// STL member operators

		//- Equality operation on FixedLists of the same type.
		//  Returns true when the FixedLists are elementwise equal
		//  (using FixedList::value_type::operator==).  Takes linear time.
		bool operator==(const FixedList<T, Size>&) const;

		//- The opposite of the equality operation. Takes linear time.
		bool operator!=(const FixedList<T, Size>&) const;

		//- Compare two FixedLists lexicographically. Takes linear time.
		bool operator<(const FixedList<T, Size>&) const;

		//- Compare two FixedLists lexicographically. Takes linear time.
		bool operator>(const FixedList<T, Size>&) const;

		//- Return true if !(a > b). Takes linear time.
		bool operator<=(const FixedList<T, Size>&) const;

		//- Return true if !(a < b). Takes linear time.
		bool operator>=(const FixedList<T, Size>&) const;


		// IOstream operators

		//- Read List from Istream, discarding contents of existing List.

#ifndef SWIG
		template<class T, unsigned Size>
		friend Istream& operator>>(Istream&, FixedList<T, Size>&);

		// Write FixedList to Ostream.
		template<class T, unsigned Size>
		friend Ostream& operator<<(Ostream&, const FixedList<T, Size>&);
#endif
	};
}

#include <FixedListI.hxx>

#endif // !_FixedList_Header
