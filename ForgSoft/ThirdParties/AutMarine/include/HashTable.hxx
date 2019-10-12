#pragma once
#ifndef _HashTable_Header
#define _HashTable_Header

#include <label.hxx>
#include <debugSwitch.hxx>
#include <Xfer.hxx>

namespace AutLib
{

	// Forward declaration of friend functions and operators

	template<class T> class List;
	template<class T> class UList;
	template<class T, class Key, class Hash> class HashTable;
	template<class T, class Key, class Hash> class HashPtrTable;

	//- Template-invariant bits for HashTable
	struct HashTableCore
	{
		//- Return a canonical (power-of-two) size
		static label canonicalSize(const label);

		//- Maximum allowable table size
		static const label maxTableSize;

		//- Construct null
		HashTableCore()
		{}

		//- Define template name and debug
		static const char* typeName_() { return "HashTable"; }
		static const word typeName;
		static debug::debugSwitch debug;;

		//- A zero-sized end iterator
		struct iteratorEnd
		{
			//- Construct null
			iteratorEnd()
			{}
		};

		//- iteratorEnd set to beyond the end of any HashTable
		static iteratorEnd cend()
		{
			return iteratorEnd();
		}

		//- iteratorEnd set to beyond the end of any HashTable
		static iteratorEnd end()
		{
			return iteratorEnd();
		}
	};


	template<class T, class Key = word, class Hash = string::hash>
	class HashTable
		: public HashTableCore
	{
		// Private data type for table entries

		//- Structure to hold a hashed entry with SLList for collisions
		struct hashedEntry
		{
			//- The lookup key
			Key key_;

			//- Pointer to next hashedEntry in sub-list
			hashedEntry* next_;

			//- The data object
			T obj_;

			//- Construct from key, next pointer and object
			hashedEntry(const Key&, hashedEntry* next, const T&);


		private:

			//- Disallow default bitwise copy construct
			hashedEntry(const hashedEntry&) = delete;

			//- Disallow default bitwise assignment
			void operator=(const hashedEntry&) = delete;
		};

		// Private data: size of table, the table and current number of elements

		//- The current number of elements in table
		label nElmts_;

		//- Number of primary entries allocated in table
		label tableSize_;

		//- The table of primary entries
		hashedEntry** table_;


		// Private Member Functions

		//- Return a canonical (power-of-two) size
		static label canonicalSize(const label);

		//- Return the hash index of the Key within the current table size.
		//  No checks for zero-sized tables.
		label hashKeyIndex(const Key&) const;

		//- Assign a new hashedEntry to a possibly already existing key
		bool set(const Key&, const T& newElmt, bool protect);

	public:

		// Forward declaration of iterators

		class iteratorBase;
		class iterator;
		class const_iterator;

		//- Declare friendship with the HashPtrTable class
		template<class T2, class Key2, class Hash2>
		friend class HashPtrTable;

		//- Declare friendship with the iteratorBase
		friend class iteratorBase;

		//- Declare friendship with the iterator
		friend class iterator;

		//- Declare friendship with the const_iterator
		friend class const_iterator;


		// Constructors

		//- Construct given initial table size
		explicit HashTable(const label size = 128);

		//- Construct from Istream
		HashTable(Istream&, const label size = 128);

		//- Construct as copy
		HashTable(const HashTable<T, Key, Hash>&);

		//- Construct by transferring the parameter contents
		HashTable(const Xfer<HashTable<T, Key, Hash> >&);


		//- Destructor
		~HashTable();


		// Member Functions

		// Access

		//- The size of the underlying table
		label capacity() const;

		//- Return number of elements in table
		label size() const;

		//- Return true if the hash table is empty
		bool empty() const;

		//- Return true if hashedEntry is found in table
		bool found(const Key&) const;

		//- Find and return an iterator set at the hashedEntry
		//  If not found iterator = end()
		iterator find(const Key&);

		//- Find and return an const_iterator set at the hashedEntry
		//  If not found iterator = end()
		const_iterator find(const Key&) const;

		//- Return the table of contents
		List<Key> toc() const;

		//- Return the table of contents as a sorted list
		List<Key> sortedToc() const;

		//- Print information
		Ostream& printInfo(Ostream&) const;


		// Edit

		//- Insert a new hashedEntry
		bool insert(const Key&, const T& newElmt);

		//- Assign a new hashedEntry, overwriting existing entries
		bool set(const Key&, const T& newElmt);

		//- Erase a hashedEntry specified by given iterator
		//  This invalidates the iterator until the next operator++
		bool erase(const iterator&);

		//- Erase a hashedEntry specified by the given key
		bool erase(const Key&);

		//- Remove entries given by the listed keys from this HashTable
		//  Return the number of elements removed
		label erase(const UList<Key>&);

		//- Remove entries given by the given keys from this HashTable
		//  Return the number of elements removed.
		//  The parameter HashTable needs the same type of key, but the
		//  type of values held and the hashing function are arbitrary.
		template<class AnyType, class AnyHash>
		label erase(const HashTable<AnyType, Key, AnyHash>&);

		//- Resize the hash table for efficiency
		void resize(const label newSize);

		//- Clear all entries from table
		void clear();

		//- Clear the table entries and the table itself.
		//  Equivalent to clear() followed by resize(0)
		void clearStorage();

		//- Shrink the allocated table to approx. twice number of elements
		void shrink();

		//- Transfer the contents of the argument table into this table
		//  and annul the argument table.
		void transfer(HashTable<T, Key, Hash>&);

		//- Transfer contents to the Xfer container
		Xfer<HashTable<T, Key, Hash> > xfer();


		// Member Operators

		//- Find and return a hashedEntry
		T& operator[](const Key&);

		//- Find and return a hashedEntry
		const T& operator[](const Key&) const;

		//- Find and return a hashedEntry, create it null if not present
		T& operator()(const Key&);

		//- Assignment
		void operator=(const HashTable<T, Key, Hash>&);

		//- Equality. Hash tables are equal if the keys and values are equal.
		//  Independent of table storage size and table order.
		bool operator==(const HashTable<T, Key, Hash>&) const;

		//- The opposite of the equality operation. Takes linear time.
		bool operator!=(const HashTable<T, Key, Hash>&) const;



		// STL type definitions

		//- Type of values the HashTable contains.
		typedef T value_type;

		//- Type that can be used for storing into HashTable::value_type
		//  objects.  This type is usually List::value_type&.
		typedef T& reference;

		//- Type that can be used for storing into constant
		//  HashTable::value_type objects.  This type is usually const
		//  HashTable::value_type&.
		typedef const T& const_reference;

		//- The type that can represent the size of a HashTable.
		typedef label size_type;


		// Iterators and helpers

		//- The iterator base for HashTable
		//  Note: data and functions are protected, to allow reuse by iterator
		//  and prevent most external usage.
		//  iterator and const_iterator have the same size, allowing
		//  us to reinterpret_cast between them (if desired)
		class iteratorBase
		{
			// Private Data

			//- Pointer to the HashTable for which this is an iterator
			//  This also lets us use the default bitwise copy/assignment
			HashTable<T, Key, Hash>* hashTable_;

			//- Current element
			hashedEntry* entryPtr_;

			//- Current hash index
			label hashIndex_;


		protected:

			// Constructors

			//- Construct null - equivalent to an 'end' position
			iteratorBase();

			//- Construct from hash table, moving to its 'begin' position
			explicit iteratorBase
			(
				const HashTable<T, Key, Hash>* curHashTable
			);

			//- Construct from hash table, element and hash index
			explicit iteratorBase
			(
				const HashTable<T, Key, Hash>* curHashTable,
				const hashedEntry* elmt,
				const label hashIndex
			);


			// Protected Member Functions

			//- Increment to the next position
			void increment();

			//- Erase the HashTable element at the current position
			bool erase();

			//- Return non-const access to referenced object
			T& object();

			//- Return const access to referenced object
			const T& cobject() const;


		public:

			// Member operators

			// Access

			//- Return the Key corresponding to the iterator
			const Key& key() const;

			//- Compare hashedEntry element pointers
			bool operator==(const iteratorBase&) const;
			bool operator!=(const iteratorBase&) const;

			//- Compare hashedEntry to iteratorEnd pointers
			bool operator==(const iteratorEnd& unused) const;
			bool operator!=(const iteratorEnd& unused) const;
		};


		//- An STL-conforming iterator
		class iterator
			:
			public iteratorBase
		{
			friend class HashTable;

			// Private Member Functions

			//- Construct from hash table, moving to its 'begin' position
			explicit iterator
			(
				HashTable<T, Key, Hash>* curHashTable
			);

			//- Construct from hash table, element and hash index
			explicit iterator
			(
				HashTable<T, Key, Hash>* curHashTable,
				hashedEntry* elmt,
				const label hashIndex
			);


		public:

			// Constructors

			//- Construct null (end iterator)
			iterator();

			//- Construct end iterator
			iterator(const iteratorEnd& unused);


			// Member operators

			//- Return referenced hash value
			T& operator*();
			T& operator()();

			//- Return referenced hash value
			const T& operator*() const;
			const T& operator()() const;

			iterator& operator++();
			iterator operator++(int);
		};

		//- iterator set to the beginning of the HashTable
		iterator begin();


		// STL const_iterator

		//- An STL-conforming const_iterator
		class const_iterator
			:
			public iteratorBase
		{
			friend class HashTable;

			// Private Member Functions

			//- Construct from hash table, moving to its 'begin' position
			explicit const_iterator
			(
				const HashTable<T, Key, Hash>* curHashTable
			);

			//- Construct from hash table, element and hash index
			explicit const_iterator
			(
				const HashTable<T, Key, Hash>* curHashTable,
				const hashedEntry* elmt,
				const label hashIndex
			);


		public:

			// Constructors

			//- Construct null (end iterator)
			const_iterator();

			//- Construct from iterator
			const_iterator(const iterator& iter) /*Amir*/
				: iteratorBase(iter)
			{ }

			//- Construct end iterator
			const_iterator(const iteratorEnd& unused);


			// Member operators

			//- Return referenced hash value
			const T& operator*() const;
			const T& operator()() const;

			const_iterator& operator++();
			const_iterator operator++(int);

		};


		//- const_iterator set to the beginning of the HashTable
		const_iterator cbegin() const;

		//- const_iterator set to the beginning of the HashTable
		const_iterator begin() const;


		// IOstream Operator

		template<class T, class Key, class Hash>
		friend Istream& operator>>(Istream&, HashTable<T, Key, Hash>&);

		template<class T, class Key, class Hash>
		friend Ostream& operator<<(Ostream&, const HashTable<T, Key, Hash>&);
	};
}

#include <HashTableI.hxx>

#endif // !_HashTable_Header
