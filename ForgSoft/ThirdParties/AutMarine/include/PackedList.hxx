#pragma once
#ifndef _PackedList_Header
#define _PackedList_Header

#include <labelList.hxx>
#include <StaticAssert.hxx>

namespace AutLib
{

	class PackedListName
	{
	public:
		PackedListName()
		{}

		static const char* typeName_() { return "PackedList"; }
		static const word typeName;
		static debug::debugSwitch debug;;
	};

	template<unsigned nBits = 1>
	class PackedList
		: private List<unsigned int>
	{
		typedef unsigned int      StorageType;
		typedef List<StorageType> StorageList;

		//- nBits must be positive (non-zero) and fit within the storage
		//  For simplicity, assume 8-bit bytes
		StaticAssert(nBits && nBits < (sizeof(StorageType) << 3));

		// Private data

		//- Number of nBits entries
		label size_;

		// Private Member Functions

		//- Calculate the list length when packed
		static label packedLength(const label);

	public:

		// Public data

		//- The max. number of bits that can be templated.
		//  Might someday be useful for a template assert.
		static unsigned int max_bits();

		//- The max. value for an entry, which simultaneously the bit-mask
		//  eg, ((1 << 2) - 1) yields 0b0011
		static unsigned int max_value();

		//- The number of entries per packed storage element
		static unsigned int packing();

		//- Masking for all bits below the offset
		static unsigned int maskLower(unsigned offset);

		// Forward declaration of iterators

		class iteratorBase;
		class iterator;
		class const_iterator;

		// Constructors

		//- Null constructor
		PackedList();

		//- Construct with given size, initializes list to 0.
		explicit PackedList(const label size);

		//- Construct with given size and value for all elements.
		PackedList(const label size, const unsigned val);

		//- Copy constructor.
		PackedList(const PackedList<nBits>&);

		//- Construct by transferring the parameter contents
		PackedList(const Xfer< PackedList<nBits> >&);

		//- Construct from a list of labels
		explicit PackedList(const UList<label>&);

		//- Clone
		autoPtr< PackedList<nBits> > clone() const;

		// Member Functions

		// Access

		//- The number of elements that can be stored before reallocating
		label capacity() const;

		//- Number of entries.
		label size() const;

		//- Return true if the list is empty (ie, size() is zero).
		bool empty() const;

		//- Get value at index I.
		//  Never auto-vivify entries.
		unsigned int get(const label) const;

		//- Set value at index I. Return true if value changed.
		//  Does auto-vivify for non-existent entries.
		//  Default value set is the max_value.
		bool set(const label, const unsigned int val = ~0u);

		//- Unset the entry at index I. Return true if value changed.
		//  Never auto-vivify entries.
		bool unset(const label);

		//- Return the underlying packed storage
		List<unsigned int>& storage();

		//- Return the underlying packed storage
		const List<unsigned int>& storage() const;

		//- Count number of bits set, O(log(n))
		//  Uses the Hamming weight (population count) method
		//  http://en.wikipedia.org/wiki/Hamming_weight
		unsigned int count() const;

		//- Return the values as a labelList
		labelList values() const;

		//- Print values and information
		Ostream& print(Ostream&) const;

		// Edit

		//- Trim any trailing zero elements
		bool trim();

		//- Invert the bits in the addressable region.
		void flip();

		//- Alter the size of the underlying storage.
		//  The addressed size will be truncated if needed to fit, but will
		//  remain otherwise untouched.
		void setCapacity(const label);

		//- Reset addressable list size, does not shrink the allocated size.
		//  Optionally specify a value for new elements.
		void resize(const label, const unsigned int& val = 0);

		//- Alias for resize()
		void setSize(const label, const unsigned int& val = 0);

		//- Reserve allocation space for at least this size.
		//  Never shrinks the allocated size.
		//  The list size is adjusted as per DynamicList with
		//  SizeInc=0, SizeMult=2, SizeDiv=1
		void reserve(const label);

		//- Clear the list, i.e. set addressable size to zero.
		//  Does not adjust the underlying storage
		void clear();

		//- Clear the list and delete storage.
		void clearStorage();

		//- Shrink the allocated space to what is actually used.
		void shrink();

		//- Transfer the contents of the argument list into this list
		//  and annul the argument list.
		void transfer(PackedList<nBits>&);

		//- Transfer contents to the Xfer container
		Xfer< PackedList<nBits> > xfer();


		// Member operators

		//- Append a value at the end of the list
		void append(const unsigned int val);

		//- Remove and return the last element
		unsigned int remove();

		//- Get value at index I
		//  Never auto-vivify entries.
		unsigned int operator[](const label) const;

		//- Set value at index I.
		//  Returns iterator to perform the actual operation.
		//  Does not auto-vivify entries, but will when assigned to.
		iteratorBase operator[](const label);

		//- Assignment of all entries to the given value. Takes linear time.
		void operator=(const unsigned int val);

		//- Assignment operator. Takes linear time.
		void operator=(const PackedList<nBits>&);

		//- Assignment operator. Takes linear time.
		void operator=(const UList<label>&);

		// Ostream operator

		//      // Write PackedList to Ostream.
		//      friend Ostream& operator<< <nBits> (Ostream&, const PackedList<nBits>&);

		// Iterators and helpers

		//- The iterator base for PackedList
		//  Note: data and functions are protected, to allow reuse by iterator
		//  and prevent most external usage.
		class iteratorBase
		{
			friend class PackedList;

		protected:

			// Protected Data

			//- Pointer to original list
			//  This also lets us use the default bitwise copy/assignment
			PackedList* list_;

			//- Element index
			label index_;

			// Protected Member Functions

			//- Get value as unsigned, no range-checking
			unsigned int get() const;

			//- Set value, returning true if changed, no range-checking
			bool set(unsigned int);

			// Constructors

			//- Construct null
			iteratorBase();

			//- Construct from base list and position index
			iteratorBase(const PackedList*, const label);

		public:

			// Member Operators

			//- Compare values (not positions)
			bool operator==(const iteratorBase&) const;
			bool operator!=(const iteratorBase&) const;

			//- Assign value, not position.
			//  This allows packed[0] = packed[3] for assigning values
			unsigned int operator=(const iteratorBase&);

			//- Assign value.
			//  A non-existent entry will be auto-vivified.
			unsigned int operator=(const unsigned int val);

			//- Conversion operator
			//  Never auto-vivify entries.
			operator unsigned int() const;

			//- Print value and information
			Ostream& print(Ostream&) const;
		};


		//- The iterator class used for PackedList
		class iterator
			:
			public iteratorBase
		{

			//- Disallow copy constructor from const_iterator - violates const-ness!
			iterator(const const_iterator&) = delete;

			//- Disallow assignment from const_iterator - violates const-ness!
			void operator=(const const_iterator&) = delete;

		public:

			// Constructors

			//- Construct null
			iterator();

			//- Construct from iterator base, eg iter(packedlist[i])
			//  but also  "iterator iter = packedlist[i];"
			//  An out-of-range iterator is assigned end()
			iterator(const iteratorBase&);

			//- Construct from base list and position index
			iterator(const PackedList*, const label);

			// Member Operators

			//- Compare positions (not values)
			bool operator==(const iteratorBase&) const;
			bool operator!=(const iteratorBase&) const;

			//- Assign from iteratorBase, eg iter = packedlist[i]
			//  An out-of-range iterator is assigned end()
			iterator& operator=(const iteratorBase&);

			//- Return value
			unsigned int operator*() const;

			//- Return value
			unsigned int operator()() const;

			//- Return iteratorBase for assigning values
			iteratorBase& operator*();

			//- Return iteratorBase for assigning values
			iteratorBase& operator()();

			iterator& operator++();
			iterator operator++(int);

			iterator& operator--();
			iterator operator--(int);

		};

		//- iterator set to the beginning of the PackedList
		iterator begin();

		//- iterator set to beyond the end of the PackedList
		iterator end();


		//- The const_iterator for PackedList
		class const_iterator
			:
			public iteratorBase
		{
		public:

			// Constructors

			//- Construct null
			const_iterator();

			//- Construct from iterator base, eg iter(packedlist[i])
			//  but also  "const_iterator iter = packedlist[i];"
			//  An out-of-range iterator is assigned cend()
			const_iterator(const iteratorBase&);

			//- Construct from base list and position index
			const_iterator(const PackedList*, const label);

			//- Construct from iterator
			const_iterator(const iterator&);

			// Member operators

			//- Compare positions (not values)
			bool operator==(const iteratorBase&) const;
			bool operator!=(const iteratorBase&) const;

			//- Assign from iteratorBase or derived
			//  eg, iter = packedlist[i] or even iter = list.begin()
			const_iterator& operator=(const iteratorBase&);

			//- Return referenced value directly
			unsigned int operator*() const;

			//- Return referenced value directly
			unsigned int operator()() const;

			const_iterator& operator++();
			const_iterator operator++(int);

			const_iterator& operator--();
			const_iterator operator--(int);

		};


		//- const_iterator set to the beginning of the PackedList
		const_iterator cbegin() const;

		//- const_iterator set to beyond the end of the PackedList
		const_iterator cend() const;

		//- const_iterator set to the beginning of the PackedList
		const_iterator begin() const;

		//- const_iterator set to beyond the end of the PackedList
		const_iterator end() const;

	};
}

#include <PackedListI.hxx>

#endif // !_PackedList_Header
