#pragma once
#include <error.hxx>
#include <OSstream.hxx>
#include <List.hxx>
#include <Istream.hxx>
template<class T, class Key, class Hash>
AutLib::HashTable<T, Key, Hash>::HashTable(const label size)
	: HashTableCore()
	, nElmts_(0)
	, tableSize_(HashTableCore::canonicalSize(size))
	, table_(NULL)
{
	if (tableSize_)
	{
		table_ = new hashedEntry*[tableSize_];

		for (label hashIdx = 0; hashIdx < tableSize_; hashIdx++)
		{
			table_[hashIdx] = 0;
		}
	}
}


template<class T, class Key, class Hash>
AutLib::HashTable<T, Key, Hash>::HashTable(const HashTable<T, Key, Hash>& ht)
	: HashTableCore()
	, nElmts_(0)
	, tableSize_(ht.tableSize_)
	, table_(NULL)
{
	if (tableSize_)
	{
		table_ = new hashedEntry*[tableSize_];

		for (label hashIdx = 0; hashIdx < tableSize_; hashIdx++)
		{
			table_[hashIdx] = 0;
		}

		for (const_iterator iter = ht.cbegin(); iter != ht.cend(); ++iter)
		{
			insert(iter.key(), *iter);
		}
	}
}

template<class T, class Key, class Hash>
AutLib::HashTable<T, Key, Hash>::HashTable(const Xfer<HashTable<T, Key, Hash> >& ht)
	: HashTableCore()
	, nElmts_(0)
	, tableSize_(0)
	, table_(NULL)
{
	transfer(ht());
}

template<class T, class Key, class Hash>
AutLib::HashTable<T, Key, Hash>::~HashTable()
{
	if (table_)
	{
		clear();
		delete[] table_;
	}
}

template<class T, class Key, class Hash>
bool AutLib::HashTable<T, Key, Hash>::found(const Key& key) const
{
	if (nElmts_)
	{
		const label hashIdx = hashKeyIndex(key);

		for (hashedEntry* ep = table_[hashIdx]; ep; ep = ep->next_)
		{
			if (key == ep->key_)
			{
				return true;
			}
		}
	}

#   ifdef FULLDEBUG
	if (debug)
	{
		Info << "HashTable<T, Key, Hash>::found(const Key& key) : "
			<< "Entry " << key << " not found in hash table\n";
	}
#   endif

	return false;
}


template<class T, class Key, class Hash>
typename AutLib::HashTable<T, Key, Hash>::iterator
AutLib::HashTable<T, Key, Hash>::find
(
	const Key& key
)
{
	if (nElmts_)
	{
		const label hashIdx = hashKeyIndex(key);

		for (hashedEntry* ep = table_[hashIdx]; ep; ep = ep->next_)
		{
			if (key == ep->key_)
			{
				return iterator(this, ep, hashIdx);
			}
		}
	}

#   ifdef FULLDEBUG
	if (debug)
	{
		Info << "HashTable<T, Key, Hash>::find(const Key& key) : "
			<< "Entry " << key << " not found in hash table\n";
	}
#   endif

	return iterator();
}


template<class T, class Key, class Hash>
typename AutLib::HashTable<T, Key, Hash>::const_iterator
AutLib::HashTable<T, Key, Hash>::find
(
	const Key& key
) const
{
	if (nElmts_)
	{
		const label hashIdx = hashKeyIndex(key);

		for (hashedEntry* ep = table_[hashIdx]; ep; ep = ep->next_)
		{
			if (key == ep->key_)
			{
				return const_iterator(this, ep, hashIdx);
			}
		}
	}

#   ifdef FULLDEBUG
	if (debug)
	{
		Info << "HashTable<T, Key, Hash>::find(const Key& key) const : "
			<< "Entry " << key << " not found in hash table\n";
	}
#   endif

	return const_iterator();
}


//template<class T, class Key, class Hash>
//AutLib::List<Key> AutLib::HashTable<T, Key, Hash>::toc() const
//{
//	List<Key> keys(nElmts_);
//	label keyI = 0;
//
//	for (const_iterator iter = cbegin(); iter != cend(); ++iter)
//	{
//		keys[keyI++] = iter.key();
//	}
//
//	return keys;
//}


template<class T, class Key, class Hash>
AutLib::List<Key> AutLib::HashTable<T, Key, Hash>::sortedToc() const
{
	List<Key> sortedLst = this->toc();
	sort(sortedLst);

	return sortedLst;
}


template<class T, class Key, class Hash>
bool AutLib::HashTable<T, Key, Hash>::set
(
	const Key& key,
	const T& newEntry,
	const bool protect
)
{
	if (!tableSize_)
	{
		resize(2);
	}

	const label hashIdx = hashKeyIndex(key);

	hashedEntry* existing = 0;
	hashedEntry* prev = 0;

	for (hashedEntry* ep = table_[hashIdx]; ep; ep = ep->next_)
	{
		if (key == ep->key_)
		{
			existing = ep;
			break;
		}
		prev = ep;
	}

	// not found, insert it at the head
	if (!existing)
	{
		table_[hashIdx] = new hashedEntry(key, table_[hashIdx], newEntry);
		nElmts_++;

		if (double(nElmts_) / tableSize_ > 0.8 && tableSize_ < maxTableSize)
		{
#           ifdef FULLDEBUG
			if (debug)
			{
				Info << "HashTable<T, Key, Hash>::set"
					"(const Key& key, T newEntry) : "
					"Doubling table size\n";
			}
#           endif

			resize(2 * tableSize_);
		}
	}
	else if (protect)
	{
		// found - but protected from overwriting
		// this corresponds to the STL 'insert' convention
#       ifdef FULLDEBUG
		if (debug)
		{
			Info << "HashTable<T, Key, Hash>::set"
				"(const Key& key, T newEntry, true) : "
				"Cannot insert " << key << " already in hash table\n";
		}
#       endif
		return false;
	}
	else
	{
		// found - overwrite existing entry
		// this corresponds to the Perl convention
		hashedEntry* ep = new hashedEntry(key, existing->next_, newEntry);

		// replace existing element - within list or insert at the head
		if (prev)
		{
			prev->next_ = ep;
		}
		else
		{
			table_[hashIdx] = ep;
		}

		delete existing;
	}

	return true;
}


template<class T, class Key, class Hash>
bool AutLib::HashTable<T, Key, Hash>::iteratorBase::erase()
{
	// note: entryPtr_ is NULL for end(), so this catches that too
	if (entryPtr_)
	{
		// Search element before entryPtr_
		hashedEntry* prev = 0;

		for
			(
				hashedEntry* ep = hashTable_->table_[hashIndex_];
				ep;
				ep = ep->next_
				)
		{
			if (ep == entryPtr_)
			{
				break;
			}
			prev = ep;
		}

		if (prev)
		{
			// has an element before entryPtr - reposition to there
			prev->next_ = entryPtr_->next_;
			delete entryPtr_;
			entryPtr_ = prev;
		}
		else
		{
			// entryPtr was first element on SLList
			hashTable_->table_[hashIndex_] = entryPtr_->next_;
			delete entryPtr_;

			// assign any non-NULL pointer value so it doesn't look
			// like end()/cend()
			entryPtr_ = reinterpret_cast<hashedEntry*>(this);

			// Mark with special hashIndex value to signal it has been rewound.
			// The next increment will bring it back to the present location.
			//
			// From the current position 'curPos', we wish to continue at
			// prevPos='curPos-1', which we mark as markPos='-curPos-1'.
			// The negative lets us notice it is special, the extra '-1'
			// is needed to avoid ambiguity for position '0'.
			// To retrieve prevPos, we would later use '-(markPos+1) - 1'
			hashIndex_ = -hashIndex_ - 1;
		}

		hashTable_->nElmts_--;

		return true;
	}
	else
	{
		return false;
	}
}



// NOTE:
// We use (const iterator&) here, but manipulate its contents anyhow.
// The parameter should be (iterator&), but then the compiler doesn't find
// it correctly and tries to call as (iterator) instead.
//
template<class T, class Key, class Hash>
bool AutLib::HashTable<T, Key, Hash>::erase(const iterator& iter)
{
	// adjust iterator after erase
	return const_cast<iterator&>(iter).erase();
}


template<class T, class Key, class Hash>
bool AutLib::HashTable<T, Key, Hash>::erase(const Key& key)
{
	return erase(find(key));
}


template<class T, class Key, class Hash>
AutLib::label AutLib::HashTable<T, Key, Hash>::erase(const UList<Key>& keys)
{
	const label nTotal = nElmts_;
	label count = 0;

	// Remove listed keys from this table - terminates early if possible
	for (label keyI = 0; count < nTotal && keyI < keys.size(); ++keyI)
	{
		if (erase(keys[keyI]))
		{
			count++;
		}
	}

	return count;
}


template<class T, class Key, class Hash>
template<class AnyType, class AnyHash>
AutLib::label AutLib::HashTable<T, Key, Hash>::erase
(
	const HashTable<AnyType, Key, AnyHash>& rhs
)
{
	label count = 0;

	// Remove rhs keys from this table - terminates early if possible
	// Could optimize depending on which hash is smaller ...
	for (iterator iter = begin(); iter != end(); ++iter)
	{
		if (rhs.found(iter.key()) && erase(iter))
		{
			count++;
		}
	}

	return count;
}


template<class T, class Key, class Hash>
void AutLib::HashTable<T, Key, Hash>::resize(const label sz)
{
	label newSize = HashTableCore::canonicalSize(sz);

	if (newSize == tableSize_)
	{
#       ifdef FULLDEBUG
		if (debug)
		{
			Info << "HashTable<T, Key, Hash>::resize(const label) : "
				<< "new table size == old table size\n";
		}
#       endif

		return;
	}

	HashTable<T, Key, Hash>* tmpTable = new HashTable<T, Key, Hash>(newSize);

	for (const_iterator iter = cbegin(); iter != cend(); ++iter)
	{
		tmpTable->insert(iter.key(), *iter);
	}

	label oldSize = tableSize_;
	tableSize_ = tmpTable->tableSize_;
	tmpTable->tableSize_ = oldSize;

	hashedEntry** oldTable = table_;
	table_ = tmpTable->table_;
	tmpTable->table_ = oldTable;

	delete tmpTable;
}


template<class T, class Key, class Hash>
void AutLib::HashTable<T, Key, Hash>::clear()
{
	if (nElmts_)
	{
		for (label hashIdx = 0; hashIdx < tableSize_; hashIdx++)
		{
			if (table_[hashIdx])
			{
				hashedEntry* ep = table_[hashIdx];
				while (hashedEntry* next = ep->next_)
				{
					delete ep;
					ep = next;
				}
				delete ep;
				table_[hashIdx] = 0;
			}
		}
		nElmts_ = 0;
	}
}


template<class T, class Key, class Hash>
void AutLib::HashTable<T, Key, Hash>::clearStorage()
{
	clear();
	resize(0);
}


template<class T, class Key, class Hash>
void AutLib::HashTable<T, Key, Hash>::shrink()
{
	const label newSize = HashTableCore::canonicalSize(nElmts_);

	if (newSize < tableSize_)
	{
		// avoid having the table disappear on us
		resize(newSize ? newSize : 2);
	}
}


template<class T, class Key, class Hash>
void AutLib::HashTable<T, Key, Hash>::transfer(HashTable<T, Key, Hash>& ht)
{
	// as per the Destructor
	if (table_)
	{
		clear();
		delete[] table_;
	}

	tableSize_ = ht.tableSize_;
	ht.tableSize_ = 0;

	table_ = ht.table_;
	ht.table_ = NULL;

	nElmts_ = ht.nElmts_;
	ht.nElmts_ = 0;
}

template<class T, class Key, class Hash>
void AutLib::HashTable<T, Key, Hash>::operator=
(
	const HashTable<T, Key, Hash>& rhs
	)
{
	// Check for assignment to self
	if (this == &rhs)
	{
		FatalErrorIn
		(
			"HashTable<T, Key, Hash>::operator="
			"(const HashTable<T, Key, Hash>&)"
		) << "attempted assignment to self"
			<< abort(FatalError);
	}

	// could be zero-sized from a previous transfer()
	if (!tableSize_)
	{
		resize(rhs.tableSize_);
	}
	else
	{
		clear();
	}

	for (const_iterator iter = rhs.cbegin(); iter != rhs.cend(); ++iter)
	{
		insert(iter.key(), *iter);
	}
}


template<class T, class Key, class Hash>
bool AutLib::HashTable<T, Key, Hash>::operator==
(
	const HashTable<T, Key, Hash>& rhs
	) const
{
	// sizes (number of keys) must match
	if (size() != rhs.size())
	{
		return false;
	}

	for (const_iterator iter = rhs.cbegin(); iter != rhs.cend(); ++iter)
	{
		const_iterator fnd = find(iter.key());

		if (fnd == cend() || fnd() != iter())
		{
			return false;
		}
	}

	return true;
}


template<class T, class Key, class Hash>
bool AutLib::HashTable<T, Key, Hash>::operator!=
(
	const HashTable<T, Key, Hash>& rhs
	) const
{
	return !(operator==(rhs));
}

template<class T, class Key, class Hash>
inline AutLib::HashTable<T, Key, Hash>::hashedEntry::hashedEntry
(
	const Key& key,
	hashedEntry* next,
	const T& obj
)
	:
	key_(key),
	next_(next),
	obj_(obj)
{
}

template<class T, class Key, class Hash>
inline AutLib::label
AutLib::HashTable<T, Key, Hash>::hashKeyIndex(const Key& key) const
{
	// size is power of two - this is the modulus
	return Hash()(key) & (tableSize_ - 1);
}

template<class T, class Key, class Hash>
inline AutLib::label AutLib::HashTable<T, Key, Hash>::capacity() const
{
	return tableSize_;
}


template<class T, class Key, class Hash>
inline AutLib::label AutLib::HashTable<T, Key, Hash>::size() const
{
	return nElmts_;
}


template<class T, class Key, class Hash>
inline bool AutLib::HashTable<T, Key, Hash>::empty() const
{
	return !nElmts_;
}


template<class T, class Key, class Hash>
inline bool AutLib::HashTable<T, Key, Hash>::insert
(
	const Key& key,
	const T& newEntry
)
{
	return this->set(key, newEntry, true);
}


template<class T, class Key, class Hash>
inline bool AutLib::HashTable<T, Key, Hash>::set
(
	const Key& key,
	const T& newEntry
)
{
	return this->set(key, newEntry, false);
}


template<class T, class Key, class Hash>
inline AutLib::Xfer<AutLib::HashTable<T, Key, Hash> >
AutLib::HashTable<T, Key, Hash>::xfer()
{
	return xferMove(*this);
}

template<class T, class Key, class Hash>
inline T& AutLib::HashTable<T, Key, Hash>::operator[](const Key& key)
{
	iterator iter = this->find(key);

	if (iter == this->end())
	{
		FatalErrorIn("HashTable<T, Key, Hash>::operator[](const Key&)")
			<< key << " not found in table.  Valid entries: "
			<< toc()
			<< exit(FatalError);
	}

	return *iter;
}


template<class T, class Key, class Hash>
inline const T& AutLib::HashTable<T, Key, Hash>::operator[](const Key& key) const
{
	const_iterator iter = this->find(key);

	if (iter == this->cend())
	{
		FatalErrorIn("HashTable<T, Key, Hash>::operator[](const Key&) const")
			<< key << " not found in table.  Valid entries: "
			<< toc()
			<< exit(FatalError);
	}

	return *iter;
}


template<class T, class Key, class Hash>
inline T& AutLib::HashTable<T, Key, Hash>::operator()(const Key& key)
{
	iterator iter = this->find(key);

	if (iter == this->end())
	{
		this->insert(key, T());
		return *find(key);
	}
	else
	{
		return *iter;
	}
}

template<class T, class Key, class Hash>
inline AutLib::HashTable<T, Key, Hash>::iteratorBase::iteratorBase()
	:
	hashTable_(0),
	entryPtr_(0),
	hashIndex_(0)
{
}


template<class T, class Key, class Hash>
inline AutLib::HashTable<T, Key, Hash>::iteratorBase::iteratorBase
(
	const HashTable<T, Key, Hash>* hashTbl
)
	:
	hashTable_(const_cast<HashTable<T, Key, Hash>*>(hashTbl)),
	entryPtr_(0),
	hashIndex_(0)
{
	if (hashTable_->nElmts_)
	{
		// find first non-NULL table entry
		while
			(
				!(entryPtr_ = hashTable_->table_[hashIndex_])
				&& ++hashIndex_ < hashTable_->tableSize_
				)
		{
		}

		if (hashIndex_ >= hashTable_->tableSize_)
		{
			// make into an end iterator
			entryPtr_ = 0;
			hashIndex_ = 0;
		}
	}
}


template<class T, class Key, class Hash>
inline AutLib::HashTable<T, Key, Hash>::iteratorBase::iteratorBase
(
	const HashTable<T, Key, Hash>* hashTbl,
	const hashedEntry* elmt,
	const label hashIndex
)
	:
	hashTable_(const_cast<HashTable<T, Key, Hash>*>(hashTbl)),
	entryPtr_(const_cast<hashedEntry*>(elmt)),
	hashIndex_(hashIndex)
{
}


template<class T, class Key, class Hash>
inline void
AutLib::HashTable<T, Key, Hash>::iteratorBase::increment()
{
	// A negative index is a special value from erase
	if (hashIndex_ < 0)
	{
		// the markPos='-curPos-1', but we wish to continue at 'curPos-1'
		// thus use '-(markPos+1) -1'
		hashIndex_ = -(hashIndex_ + 1) - 1;
	}
	else if (entryPtr_)
	{
		if (entryPtr_->next_)
		{
			// Move to next element on the SLList
			entryPtr_ = entryPtr_->next_;
			return;
		}
	}
	// else
	// {
	//     // if we reach here (entryPtr_ is NULL) it is already at the end()
	//     // we should probably stop
	// }


	// Step to the next table entry
	while
		(
			++hashIndex_ < hashTable_->tableSize_
			&& !(entryPtr_ = hashTable_->table_[hashIndex_])
			)
	{
	}

	if (hashIndex_ >= hashTable_->tableSize_)
	{
		// make into an end iterator
		entryPtr_ = 0;
		hashIndex_ = 0;
	}
}


template<class T, class Key, class Hash>
inline
const Key& AutLib::HashTable<T, Key, Hash>::iteratorBase::key() const
{
	return entryPtr_->key_;
}


template<class T, class Key, class Hash>
inline T&
AutLib::HashTable<T, Key, Hash>::iteratorBase::object()
{
	return entryPtr_->obj_;
}


template<class T, class Key, class Hash>
inline const T&
AutLib::HashTable<T, Key, Hash>::iteratorBase::cobject() const
{
	return entryPtr_->obj_;
}


template<class T, class Key, class Hash>
inline bool AutLib::HashTable<T, Key, Hash>::iteratorBase::operator==
(
	const iteratorBase& iter
	) const
{
	return entryPtr_ == iter.entryPtr_;
}


template<class T, class Key, class Hash>
inline bool AutLib::HashTable<T, Key, Hash>::iteratorBase::operator!=
(
	const iteratorBase& iter
	) const
{
	return entryPtr_ != iter.entryPtr_;
}


template<class T, class Key, class Hash>
inline bool AutLib::HashTable<T, Key, Hash>::iteratorBase::operator==
(
	const iteratorEnd&
	) const
{
	return !entryPtr_;
}


template<class T, class Key, class Hash>
inline bool AutLib::HashTable<T, Key, Hash>::iteratorBase::operator!=
(
	const iteratorEnd&
	) const
{
	return entryPtr_;
}

template<class T, class Key, class Hash>
inline AutLib::HashTable<T, Key, Hash>::iterator::iterator()
	:
	iteratorBase()
{
}


template<class T, class Key, class Hash>
inline AutLib::HashTable<T, Key, Hash>::iterator::iterator
(
	const iteratorEnd&
)
	:
	iteratorBase()
{
}


template<class T, class Key, class Hash>
inline AutLib::HashTable<T, Key, Hash>::iterator::iterator
(
	HashTable<T, Key, Hash>* hashTbl
)
	:
	iteratorBase(hashTbl)
{
}


template<class T, class Key, class Hash>
inline AutLib::HashTable<T, Key, Hash>::iterator::iterator
(
	HashTable<T, Key, Hash>* hashTbl,
	hashedEntry* elmt,
	const label hashIndex
)
	:
	iteratorBase(hashTbl, elmt, hashIndex)
{
}


template<class T, class Key, class Hash>
inline T&
AutLib::HashTable<T, Key, Hash>::iterator::operator*()
{
	return this->object();
}


template<class T, class Key, class Hash>
inline T&
AutLib::HashTable<T, Key, Hash>::iterator::operator()()
{
	return this->object();
}


template<class T, class Key, class Hash>
inline const T&
AutLib::HashTable<T, Key, Hash>::iterator::operator*() const
{
	return this->cobject();
}


template<class T, class Key, class Hash>
inline const T&
AutLib::HashTable<T, Key, Hash>::iterator::operator()() const
{
	return this->cobject();
}


template<class T, class Key, class Hash>
inline
typename AutLib::HashTable<T, Key, Hash>::iterator&
AutLib::HashTable<T, Key, Hash>::iterator::operator++()
{
	this->increment();
	return *this;
}


template<class T, class Key, class Hash>
inline typename AutLib::HashTable<T, Key, Hash>::iterator
AutLib::HashTable<T, Key, Hash>::iterator::operator++(int)
{
	iterator old = *this;
	this->increment();
	return old;
}


template<class T, class Key, class Hash>
inline typename AutLib::HashTable<T, Key, Hash>::iterator
AutLib::HashTable<T, Key, Hash>::begin()
{
	return iterator(this);
}

template<class T, class Key, class Hash>
inline AutLib::HashTable<T, Key, Hash>::const_iterator::const_iterator()
	:
	iteratorBase()
{
}


//template<class T, class Key, class Hash>
//inline AutLib::HashTable<T, Key, Hash>::const_iterator::const_iterator
//(
//	const HashTable<T, Key, Hash>::iterator& iter
//)
//	:
//	iteratorBase(iter)
//{
//}


template<class T, class Key, class Hash>
inline AutLib::HashTable<T, Key, Hash>::const_iterator::const_iterator
(
	const iteratorEnd&
)
	:
	iteratorBase()
{
}


template<class T, class Key, class Hash>
inline AutLib::HashTable<T, Key, Hash>::const_iterator::const_iterator
(
	const HashTable<T, Key, Hash>* hashTbl
)
	:
	iteratorBase(hashTbl)
{
}


template<class T, class Key, class Hash>
inline AutLib::HashTable<T, Key, Hash>::const_iterator::const_iterator
(
	const HashTable<T, Key, Hash>* hashTbl,
	const hashedEntry* elmt,
	const label hashIndex
)
	:
	iteratorBase(hashTbl, elmt, hashIndex)
{
}


template<class T, class Key, class Hash>
inline const T&
AutLib::HashTable<T, Key, Hash>::const_iterator::operator*() const
{
	return this->cobject();
}


template<class T, class Key, class Hash>
inline const T&
AutLib::HashTable<T, Key, Hash>::const_iterator::operator()() const
{
	return this->cobject();
}


template<class T, class Key, class Hash>
inline
typename AutLib::HashTable<T, Key, Hash>::const_iterator&
AutLib::HashTable<T, Key, Hash>::const_iterator::operator++()
{
	this->increment();
	return *this;
}


template<class T, class Key, class Hash>
inline typename AutLib::HashTable<T, Key, Hash>::const_iterator
AutLib::HashTable<T, Key, Hash>::const_iterator::operator++(int)
{
	const_iterator old = *this;
	this->increment();
	return old;
}


template<class T, class Key, class Hash>
inline typename AutLib::HashTable<T, Key, Hash>::const_iterator
AutLib::HashTable<T, Key, Hash>::cbegin() const
{
	return const_iterator(this);
}


template<class T, class Key, class Hash>
inline typename AutLib::HashTable<T, Key, Hash>::const_iterator
AutLib::HashTable<T, Key, Hash>::begin() const
{
	return this->cbegin();
}

template<class T, class Key, class Hash>
AutLib::List<Key> AutLib::HashTable<T, Key, Hash>::toc() const
{
	List<Key> keys(nElmts_);
	label keyI = 0;

	for (const_iterator iter = cbegin(); iter != cend(); ++iter)
	{
		keys[keyI++] = iter.key();
	}

	return keys;
}

template<class T, class Key, class Hash>
AutLib::HashTable<T, Key, Hash>::HashTable(Istream& is, const label size)
	: HashTableCore()
	, nElmts_(0)
	, tableSize_(HashTableCore::canonicalSize(size))
	, table_(NULL)
{
	if (tableSize_)
	{
		table_ = new hashedEntry*[tableSize_];

		for (label hashIdx = 0; hashIdx < tableSize_; hashIdx++)
		{
			table_[hashIdx] = 0;
		}
	}

	operator>>(is, *this);
}

template<class T, class Key, class Hash>
AutLib::Ostream& AutLib::HashTable<T, Key, Hash>::printInfo(Ostream& os) const
{
	label used = 0;
	label maxChain = 0;
	unsigned avgChain = 0;

	for (label hashIdx = 0; hashIdx < tableSize_; ++hashIdx)
	{
		label count = 0;
		for (hashedEntry* ep = table_[hashIdx]; ep; ep = ep->next_)
		{
			++count;
		}

		if (count)
		{
			++used;
			avgChain += count;

			if (maxChain < count)
			{
				maxChain = count;
			}
		}
	}

	os << "HashTable<T,Key,Hash>"
		<< " elements:" << size() << " slots:" << used << "/" << tableSize_
		<< " chaining(avg/max):" << (used ? (float(avgChain) / used) : 0)
		<< "/" << maxChain << endl;

	return os;
}

namespace AutLib
{

	template<class T, class Key, class Hash>
	Istream& operator>>(Istream& is, HashTable<T, Key, Hash>& L)
	{
		is.fatalCheck("operator>>(Istream&, HashTable<T, Key, Hash>&)");

		// Anull list
		L.clear();

		is.fatalCheck("operator>>(Istream&, HashTable<T, Key, Hash>&)");

		token firstToken(is);

		is.fatalCheck
		(
			"operator>>(Istream&, HashTable<T, Key, Hash>&) : "
			"reading first token"
		);

		if (firstToken.isLabel())
		{
			label s = firstToken.labelToken();

			// Read beginning of contents
			char delimiter = is.readBeginList("HashTable<T, Key, Hash>");

			if (s)
			{
				if (2 * s > L.tableSize_)
				{
					L.resize(2 * s);
				}

				if (delimiter == token::BEGIN_LIST)
				{
					for (label i = 0; i < s; i++)
					{
						Key key;
						is >> key;
						L.insert(key, pTraits<T>(is));

						is.fatalCheck
						(
							"operator>>(Istream&, HashTable<T, Key, Hash>&) : "
							"reading entry"
						);
					}
				}
				else
				{
					FatalIOErrorIn
					(
						"operator>>(Istream&, HashTable<T, Key, Hash>&)",
						is
					) << "incorrect first token, '(', found " << firstToken.info()
						<< exit(FatalIOError);
				}
			}

			// Read end of contents
			is.readEndList("HashTable");
		}
		else if (firstToken.isPunctuation())
		{
			if (firstToken.pToken() != token::BEGIN_LIST)
			{
				FatalIOErrorIn
				(
					"operator>>(Istream&, HashTable<T, Key, Hash>&)",
					is
				) << "incorrect first token, '(', found " << firstToken.info()
					<< exit(FatalIOError);
			}

			token lastToken(is);
			while
				(
					!(
						lastToken.isPunctuation()
						&& lastToken.pToken() == token::END_LIST
						)
					)
			{
				is.putBack(lastToken);

				Key key;
				is >> key;

				T element;
				is >> element;

				L.insert(key, element);

				is.fatalCheck
				(
					"operator>>(Istream&, HashTable<T, Key, Hash>&) : "
					"reading entry"
				);

				is >> lastToken;
			}
		}
		else
		{
			FatalIOErrorIn
			(
				"operator>>(Istream&, HashTable<T, Key, Hash>&)",
				is
			) << "incorrect first token, expected <int> or '(', found "
				<< firstToken.info()
				<< exit(FatalIOError);
		}

		is.fatalCheck("operator>>(Istream&, HashTable<T, Key, Hash>&)");

		return is;
	}

	template<class T, class Key, class Hash>
	Ostream& operator<<(Ostream& os, const HashTable<T, Key, Hash>& L)
	{
		// Write size and start delimiter
		os << nl << L.size() << nl << token::BEGIN_LIST << nl;

		// Write contents
		for (typename HashTable<T, Key, Hash>::const_iterator iter = L.cbegin(); iter != L.cend(); ++iter)
		{
			os 
				<< iter.key() 
				<< token::SPACE 
				<< iter() 
				<< AutLib::nl;
		}

		// Write end delimiter
		os << token::END_LIST;

		// Check state of IOstream
		os.check("Ostream& operator<<(Ostream&, const HashTable&)");

		return os;
	}
}