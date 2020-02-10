#pragma once
#ifndef _HashSet_Header
#define _HashSet_Header

#include <Hash.hxx>
#include <HashTable.hxx>
#include <UList.hxx>
#include <nil.hxx>

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						   Class HashSet Declaration
\*---------------------------------------------------------------------------*/

	template<class Key = word, class Hash = string::hash>
	class HashSet
		: public HashTable<nil, Key, Hash>
	{

	public:

		typedef typename HashTable<nil, Key, Hash>::iterator iterator;
		typedef typename HashTable<nil, Key, Hash>::const_iterator const_iterator;


		// Constructors

			//- Construct given initial size
		explicit HashSet(const label size = 128)
			: HashTable<nil, Key, Hash>(size)
		{}

		//- Construct from Istream
		explicit HashSet(Istream& is)
			: HashTable<nil, Key, Hash>(is)
		{}

		//- Construct from UList of Key
		explicit HashSet(const UList<Key>& lst)
			: HashTable<nil, Key, Hash>(2 * lst.size())
		{
			forAll(lst, i)
			{
				insert(lst[i]);
			}
		}

		//- Construct as copy
		HashSet(const HashSet<Key, Hash>& hs)
			: HashTable<nil, Key, Hash>(hs)
		{}

		//- Construct by transferring the parameter contents
		explicit HashSet(const Xfer<HashSet<Key, Hash>>& hs)
			: HashTable<nil, Key, Hash>(hs)
		{}

		//- Construct by transferring the parameter contents
		explicit HashSet(const Xfer<HashTable<nil, Key, Hash>>& hs)
			: HashTable<nil, Key, Hash>(hs)
		{}

		//- Construct from the keys of another HashTable,
		//  the type of values held is arbitrary.
		template<class AnyType, class AnyHash>
		HashSet(const HashTable<AnyType, Key, AnyHash>&);


		// Member Functions

			// Edit

			//- Insert a new entry
		bool insert(const Key& key)
		{
			return HashTable<nil, Key, Hash>::insert(key, nil());
		}

		//- Insert keys from a UList of Key
		//  Return the number of new elements inserted
		label insert(const UList<Key>&);

		//- Same as insert (cannot overwrite nil content)
		bool set(const Key& key)
		{
			return insert(key);
		}

		//- Same as insert (cannot overwrite nil content)
		label set(const UList<Key>& lst)
		{
			return insert(lst);
		}

		//- Unset the specified key - same as erase
		bool unset(const Key& key)
		{
			return HashTable<nil, Key, Hash>::erase(key);
		}


		// Member Operators

			//- Return true if the entry exists, same as found()
		inline bool operator[](const Key&) const;

		//- Equality. Two hashtables are equal when their contents are equal.
		//  Independent of table size or order.
		bool operator==(const HashSet<Key, Hash>&) const;

		//- The opposite of the equality operation.
		bool operator!=(const HashSet<Key, Hash>&) const;


		//- Combine entries from HashSets
		void operator|=(const HashSet<Key, Hash>&);

		//- Only retain entries found in both HashSets
		void operator&=(const HashSet<Key, Hash>&);

		//- Only retain unique entries (xor)
		void operator^=(const HashSet<Key, Hash>&);

		//- Add entries listed in the given HashSet to this HashSet
		inline void operator+=(const HashSet<Key, Hash>& rhs)
		{
			this->operator|=(rhs);
		}

		//- Remove entries listed in the given HashSet from this HashSet
		void operator-=(const HashSet<Key, Hash>&);
	};


	// Global Operators

	//- Combine entries from HashSets
	template<class Key, class Hash>
	HashSet<Key, Hash> operator|
		(
			const HashSet<Key, Hash>& hash1,
			const HashSet<Key, Hash>& hash2
			);


	//- Create a HashSet that only contains entries found in both HashSets
	template<class Key, class Hash>
	HashSet<Key, Hash> operator&
		(
			const HashSet<Key, Hash>& hash1,
			const HashSet<Key, Hash>& hash2
			);


	//- Create a HashSet that only contains unique entries (xor)
	template<class Key, class Hash>
	HashSet<Key, Hash> operator^
		(
			const HashSet<Key, Hash>& hash1,
			const HashSet<Key, Hash>& hash2
			);


	//- A HashSet with word keys.
	typedef HashSet<> wordHashSet;

	//- A HashSet with label keys.
	typedef HashSet<label, Hash<label>> labelHashSet;


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#ifdef NoRepository
#   include <HashSet.cxx>
#endif

#endif // !_HashSet_Header
