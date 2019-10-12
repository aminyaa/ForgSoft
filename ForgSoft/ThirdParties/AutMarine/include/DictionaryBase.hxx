#pragma once
#ifndef _DictionaryBase_Header
#define _DictionaryBase_Header

#include <HashTable.hxx>
#include <wordList.hxx>

namespace AutLib
{

	template<class IDLListType, class T>
	class DictionaryBase
		: public IDLListType
	{

		// Private data

		//- HashTable of the entries held on the IDLListType for quick lookup
		HashTable<T*> hashedTs_;


		// Private Member functions

		// Add the IDLListType entries into the HashTable
		void addEntries();

	public:

		// Constructors

		//- Null constructor
		DictionaryBase();

		//- Copy construct
		DictionaryBase(const DictionaryBase&);

		//- Construct from Istream using given Istream constructor class
		template<class INew>
		DictionaryBase(Istream&, const INew&);

		//- Construct from Istream using default Istream constructor class
		DictionaryBase(Istream&);


		// Member functions

		// Search and lookup

		//- Search DictionaryBase for given keyword
		bool found(const word&) const;

		//- Find and return an entry if present, otherwise return NULL
		const T* lookupPtr(const word&) const;

		//- Find and return an entry if present, otherwise return NULL
		T* lookupPtr(const word&);

		//- Find and return entry
		const T* lookup(const word&) const;

		//- Find and return entry
		T* lookup(const word&);

		//- Return the table of contents
		wordList toc() const;


		// Editing

		//- Add at head of dictionary
		void insert(const word&, T*);

		//- Add at tail of dictionary
		void append(const word&, T*);

		//- Remove and return entry specified by keyword.
		//  Return NULL if the keyword was not found.
		T* remove(const word&);

		//- Clear the dictionary
		void clear();

		//- Transfer the contents of the argument into this DictionaryBase
		//  and annull the argument.
		void transfer(DictionaryBase<IDLListType, T>&);

		// Member operators

		void operator=(const DictionaryBase&);

		//- Find and return entry
		const T* operator[](const word& key) const
		{
			return lookup(key);
		}

		//- Find and return entry
		T* operator[](const word& key)
		{
			return lookup(key);
		}

		template<typename IDLListType, typename T>
		friend Ostream& operator<<(Ostream&, const DictionaryBase<IDLListType, T>&);
	};
}

#include <DictionaryBaseI.hxx>

#endif // !_DictionaryBase_Header
