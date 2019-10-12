#pragma once
template<unsigned nBits>
inline unsigned int AutLib::PackedList<nBits>::max_bits()
{
	return sizeof(StorageType)*CHAR_BIT - 1;
}


template<unsigned nBits>
inline unsigned int AutLib::PackedList<nBits>::max_value()
{
	return (1u << nBits) - 1;
}


template<unsigned nBits>
inline unsigned int AutLib::PackedList<nBits>::packing()
{
	return sizeof(StorageType)*CHAR_BIT / nBits;
}


template<unsigned nBits>
inline unsigned int AutLib::PackedList<nBits>::maskLower(unsigned offset)
{
	// return (1u << (nBits * offset)) - 1;
	// The next one works more reliably with overflows
	// eg, when compiled without optimization
	return (~0u >> (sizeof(StorageType)*CHAR_BIT - nBits * offset));
}


template<unsigned nBits>
inline AutLib::label AutLib::PackedList<nBits>::packedLength(const label nElem)
{
	return (nElem + packing() - 1) / packing();
}

template<unsigned nBits>
inline AutLib::PackedList<nBits>::PackedList()
	: StorageList()
	, size_(0)
{}


template<unsigned nBits>
inline AutLib::PackedList<nBits>::PackedList(const label size)
	: StorageList(packedLength(size), 0u)
	, size_(size)
{}

template<unsigned nBits>
AutLib::PackedList<nBits>::PackedList(const label size, const unsigned int val)
	: StorageList(packedLength(size), 0u)
	, size_(size)
{
	operator=(val);
}


template<unsigned nBits>
AutLib::PackedList<nBits>::PackedList(const UList<label>& lst)
	: StorageList(packedLength(lst.size()), 0u)
	, size_(lst.size())
{
	for (AutLib::label i = 0; i < (lst).size(); i++)
	{
		set(i, lst[i]);
	}
}

template<unsigned nBits>
inline AutLib::PackedList<nBits>::PackedList(const PackedList<nBits>& lst)
	: StorageList(lst)
	, size_(lst.size_)
{}


template<unsigned nBits>
inline AutLib::PackedList<nBits>::PackedList(const Xfer<PackedList<nBits> >& lst)
{
	transfer(lst());
}


template<unsigned nBits>
inline AutLib::autoPtr<AutLib::PackedList<nBits> >
AutLib::PackedList<nBits>::clone() const
{
	return autoPtr<PackedList<nBits> >(new PackedList<nBits>(*this));
}

template<unsigned nBits>
inline AutLib::PackedList<nBits>::iteratorBase::iteratorBase()
	:
	list_(0),
	index_(0)
{
}


template<unsigned nBits>
inline AutLib::PackedList<nBits>::iteratorBase::iteratorBase
(
	const PackedList<nBits>* lst,
	const label i
)
	:
	list_(const_cast<PackedList<nBits>*>(lst)),
	index_(i)
{
}


template<unsigned nBits>
inline unsigned int
AutLib::PackedList<nBits>::iteratorBase::get() const
{
	const unsigned int seg = index_ / packing();
	const unsigned int off = index_ % packing();

	const unsigned int& stored = list_->StorageList::operator[](seg);
	return (stored >> (nBits * off)) & max_value();
}


template<unsigned nBits>
inline bool
AutLib::PackedList<nBits>::iteratorBase::set(const unsigned int val)
{
	const unsigned int seg = index_ / packing();
	const unsigned int off = index_ % packing();

	unsigned int& stored = list_->StorageList::operator[](seg);
	const unsigned int prev = stored;

	const unsigned int startBit = nBits * off;
	const unsigned int maskNew = max_value() << startBit;

	if (val & ~max_value())
	{
		// overflow is max_value, fill everything
		stored |= maskNew;
	}
	else
	{
		stored &= ~maskNew;
		stored |= maskNew & (val << startBit);
	}

	return prev != stored;
}


template<unsigned nBits>
inline bool AutLib::PackedList<nBits>::iteratorBase::operator==
(
	const iteratorBase& iter
	) const
{
	return this->get() == iter.get();
}


template<unsigned nBits>
inline bool AutLib::PackedList<nBits>::iteratorBase::operator!=
(
	const iteratorBase& iter
	) const
{
	return this->get() != iter.get();
}


template<unsigned nBits>
inline unsigned int
AutLib::PackedList<nBits>::iteratorBase::operator=(const iteratorBase& iter)
{
	const unsigned int val = iter.get();
	this->set(val);
	return val;
}


template<unsigned nBits>
inline unsigned int
AutLib::PackedList<nBits>::iteratorBase::operator=(const unsigned int val)
{
	// lazy evaluation - increase size on assigment
	if (index_ >= list_->size_)
	{
		list_->resize(index_ + 1);
	}

	this->set(val);
	return val;
}


template<unsigned nBits>
inline AutLib::PackedList<nBits>::iteratorBase::operator
unsigned int() const
{
	// lazy evaluation - return 0 for out-of-range
	if (index_ >= list_->size_)
	{
		return 0;
	}

	return this->get();
}


// const_iterator, iterator

template<unsigned nBits>
inline AutLib::PackedList<nBits>::iterator::iterator()
	: iteratorBase()
{}


template<unsigned nBits>
inline AutLib::PackedList<nBits>::const_iterator::const_iterator()
	: iteratorBase()
{}


template<unsigned nBits>
inline AutLib::PackedList<nBits>::iterator::iterator(const iteratorBase& iter)
	: iteratorBase(iter)
{
	// avoid going past end()
	// eg, iter = iterator(list, Inf)
	if (this->index_ > this->list_->size_)
	{
		this->index_ = this->list_->size_;
	}
}


template<unsigned nBits>
inline AutLib::PackedList<nBits>::const_iterator::const_iterator(const iteratorBase& iter)
	: iteratorBase(iter)
{
	// avoid going past end()
	// eg, iter = iterator(list, Inf)
	if (this->index_ > this->list_->size_)
	{
		this->index_ = this->list_->size_;
	}
}


template<unsigned nBits>
inline AutLib::PackedList<nBits>::iterator::iterator
(
	const PackedList<nBits>* lst,
	const label i
)
	: iteratorBase(lst, i)
{}


template<unsigned nBits>
inline AutLib::PackedList<nBits>::const_iterator::const_iterator
(
	const PackedList<nBits>* lst,
	const label i
)
	: iteratorBase(lst, i)
{}


template<unsigned nBits>
inline AutLib::PackedList<nBits>::const_iterator::const_iterator
(
	const iterator& iter
)
	: iteratorBase(static_cast<const iteratorBase&>(iter))
{}


template<unsigned nBits>
inline bool AutLib::PackedList<nBits>::iterator::operator==(const iteratorBase& iter) const
{
	return this->index_ == iter.index_;
}


template<unsigned nBits>
inline bool AutLib::PackedList<nBits>::iterator::operator!=(const iteratorBase& iter) const
{
	return this->index_ != iter.index_;
}



template<unsigned nBits>
inline bool AutLib::PackedList<nBits>::const_iterator::operator==(const iteratorBase& iter) const
{
	return this->index_ == iter.index_;
}


template<unsigned nBits>
inline bool AutLib::PackedList<nBits>::const_iterator::operator!=(const iteratorBase& iter) const
{
	return this->index_ != iter.index_;
}



template<unsigned nBits>
inline typename AutLib::PackedList<nBits>::iterator&
AutLib::PackedList<nBits>::iterator::operator=(const iteratorBase& iter)
{
	this->list_ = iter.list_;
	this->index_ = iter.index_;

	// avoid going past end()
	// eg, iter = iterator(list, Inf)
	if (this->index_ > this->list_->size_)
	{
		this->index_ = this->list_->size_;
	}

	return *this;
}


template<unsigned nBits>
inline typename AutLib::PackedList<nBits>::const_iterator&
AutLib::PackedList<nBits>::const_iterator::operator=(const iteratorBase& iter)
{
	this->list_ = iter.list_;
	this->index_ = iter.index_;

	// avoid going past end()
	// eg, iter = iterator(list, Inf)
	if (this->index_ > this->list_->size_)
	{
		this->index_ = this->list_->size_;
	}

	return *this;
}


template<unsigned nBits>
inline typename AutLib::PackedList<nBits>::iterator&
AutLib::PackedList<nBits>::iterator::operator++()
{
	++this->index_;
	return *this;
}


template<unsigned nBits>
inline typename AutLib::PackedList<nBits>::const_iterator&
AutLib::PackedList<nBits>::const_iterator::operator++()
{
	++this->index_;
	return *this;
}


template<unsigned nBits>
inline typename AutLib::PackedList<nBits>::iterator
AutLib::PackedList<nBits>::iterator::operator++(int)
{
	iterator old = *this;
	++this->index_;
	return old;
}


template<unsigned nBits>
inline typename AutLib::PackedList<nBits>::const_iterator
AutLib::PackedList<nBits>::const_iterator::operator++(int)
{
	const_iterator old = *this;
	++this->index_;
	return old;
}


template<unsigned nBits>
inline typename AutLib::PackedList<nBits>::iterator&
AutLib::PackedList<nBits>::iterator::operator--()
{
	--this->index_;
	return *this;
}


template<unsigned nBits>
inline typename AutLib::PackedList<nBits>::const_iterator&
AutLib::PackedList<nBits>::const_iterator::operator--()
{
	--this->index_;
	return *this;
}


template<unsigned nBits>
inline typename AutLib::PackedList<nBits>::iterator
AutLib::PackedList<nBits>::iterator::operator--(int)
{
	iterator old = *this;
	--this->index_;
	return old;
}


template<unsigned nBits>
inline typename AutLib::PackedList<nBits>::const_iterator
AutLib::PackedList<nBits>::const_iterator::operator--(int)
{
	const_iterator old = *this;
	--this->index_;
	return old;
}


template<unsigned nBits>
inline typename AutLib::PackedList<nBits>::iteratorBase&
AutLib::PackedList<nBits>::iterator::operator*()
{
	return static_cast<iteratorBase&>(*this);
}


template<unsigned nBits>
inline typename AutLib::PackedList<nBits>::iteratorBase&
AutLib::PackedList<nBits>::iterator::operator()()
{
	return static_cast<iteratorBase&>(*this);
}


template<unsigned nBits>
inline unsigned int
AutLib::PackedList<nBits>::const_iterator::operator*() const
{
	return this->get();
}


template<unsigned nBits>
inline unsigned int
AutLib::PackedList<nBits>::const_iterator::operator()() const
{
	return this->get();
}


template<unsigned nBits>
inline typename AutLib::PackedList<nBits>::iterator
AutLib::PackedList<nBits>::begin()
{
	return iterator(this, 0);
}


template<unsigned nBits>
inline typename AutLib::PackedList<nBits>::const_iterator
AutLib::PackedList<nBits>::begin() const
{
	return const_iterator(this, 0);
}


template<unsigned nBits>
inline typename AutLib::PackedList<nBits>::const_iterator
AutLib::PackedList<nBits>::cbegin() const
{
	return const_iterator(this, 0);
}


template<unsigned nBits>
inline typename AutLib::PackedList<nBits>::iterator
AutLib::PackedList<nBits>::end()
{
	return iterator(this, size_);
}


template<unsigned nBits>
inline typename AutLib::PackedList<nBits>::const_iterator
AutLib::PackedList<nBits>::end() const
{
	return const_iterator(this, size_);
}


template<unsigned nBits>
inline typename AutLib::PackedList<nBits>::const_iterator
AutLib::PackedList<nBits>::cend() const
{
	return const_iterator(this, size_);
}

template<unsigned nBits>
inline AutLib::label AutLib::PackedList<nBits>::size() const
{
	return size_;
}


template<unsigned nBits>
inline bool AutLib::PackedList<nBits>::empty() const
{
	return !size_;
}


template<unsigned nBits>
inline void AutLib::PackedList<nBits>::resize
(
	const label nElem,
	const unsigned int& val
)
{
	reserve(nElem);

	if (nElem > size_)
	{
		// fill new elements or newly exposed elements
		if (size_)
		{
			// fill value for complete segments
			unsigned int fill = val;

			if (fill & ~max_value())
			{
				// overflow is max_value, fill everything
				fill = ~0u;
			}
			else
			{
				for (unsigned int i = 1; i < packing(); ++i)
				{
					fill |= (fill << nBits);
				}
			}

			unsigned int seg = size_ / packing();
			unsigned int off = size_ % packing();

			// partial segment, preserve existing value
			if (off)
			{
				unsigned int maskOld = maskLower(off);

				StorageList::operator[](seg) &= maskOld;
				StorageList::operator[](seg) |= ~maskOld & fill;

				// continue with the next segment
				seg++;
			}

			unsigned int endSeg = nElem / packing();
			// fill in complete elements
			while (seg < endSeg)
			{
				StorageList::operator[](seg++) = fill;
			}
		}
		else
		{
			// no original size - simply flood-fill
			operator=(val);
		}
	}

	size_ = nElem;
}


template<unsigned nBits>
inline void AutLib::PackedList<nBits>::setSize
(
	const label newSize,
	const unsigned int& val
)
{
	resize(newSize, val);
}



template<unsigned nBits>
inline AutLib::label AutLib::PackedList<nBits>::capacity() const
{
	return packing() * StorageList::size();
}


template<unsigned nBits>
inline void AutLib::PackedList<nBits>::setCapacity(const label nElem)
{
	StorageList::setSize(packedLength(nElem), 0u);

	// truncate addressed size too?
	if (size_ > nElem)
	{
		size_ = nElem;
	}
}


template<unsigned nBits>
inline void AutLib::PackedList<nBits>::reserve
(
	const label nElem
)
{
	label len = packedLength(nElem);

	// need more capacity?
	if (len > StorageList::size())
	{
		// Like DynamicList with SizeInc=0, SizeMult=2, SizeDiv=1
		StorageList::setSize
		(
			max
			(
				len,
				StorageList::size() * 2
			),
			0u
		);
	}
}


template<unsigned nBits>
inline void AutLib::PackedList<nBits>::clear()
{
	size_ = 0;
}


template<unsigned nBits>
inline void AutLib::PackedList<nBits>::clearStorage()
{
	StorageList::clear();
	size_ = 0;
}


template<unsigned nBits>
inline void AutLib::PackedList<nBits>::shrink()
{
	label len = packedLength(size_);

	// we have unused space?
	if (len < StorageList::size())
	{
		StorageList::setSize(len);
	}
}

template<unsigned nBits>
inline AutLib::List<unsigned int>&
AutLib::PackedList<nBits>::storage()
{
	return static_cast<StorageList&>(*this);
}


template<unsigned nBits>
inline const AutLib::List<unsigned int>&
AutLib::PackedList<nBits>::storage() const
{
	return static_cast<const StorageList&>(*this);
}

#if (UINT_MAX == 0xFFFFFFFF)
// 32-bit counting, Hamming weight method
#   define COUNT_PACKEDBITS(sum, x)                                           \
{                                                                             \
    x -= (x >> 1) & 0x55555555;                                               \
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);                           \
    sum += (((x + (x >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;                \
}
#elif (UINT_MAX == 0xFFFFFFFFFFFFFFFF)
// 64-bit counting, Hamming weight method
#   define COUNT_PACKEDBITS(sum, x)                                           \
{                                                                             \
    x -= (x >> 1) & 0x5555555555555555;                                       \
    x = (x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333);           \
    sum += (((x + (x >> 4)) & 0x0F0F0F0F0F0F0F0F) * 0x0101010101010101) >> 56;\
}
#else
// Arbitrary number of bits, Brian Kernighan's method
#   define COUNT_PACKEDBITS(sum, x)    for (; x; ++sum) { x &= x - 1; }
#endif


template<unsigned nBits>
unsigned int AutLib::PackedList<nBits>::count() const
{
	register unsigned int c = 0;

	if (size_)
	{
		// mask value for complete segments
		unsigned int mask = maskLower(packing());

		const unsigned int endSeg = size_ / packing();
		const unsigned int endOff = size_ % packing();

		// count bits in complete segments
		for (unsigned i = 0; i < endSeg; ++i)
		{
			register unsigned int bits = StorageList::operator[](i) & mask;
			COUNT_PACKEDBITS(c, bits);
		}

		// count bits in partial segment
		if (endOff)
		{
			mask = maskLower(endOff);

			register unsigned int bits = StorageList::operator[](endSeg) & mask;
			COUNT_PACKEDBITS(c, bits);
		}
	}

	return c;
}

template<unsigned nBits>
AutLib::labelList AutLib::PackedList<nBits>::values() const
{
	labelList elems(size_);

	for (AutLib::label i = 0; i < (*this).size(); i++)
	{
		elems[i] = get(i);
	}
	return elems;
}


template<unsigned nBits>
AutLib::Ostream& AutLib::PackedList<nBits>::iteratorBase::print(Ostream& os) const
{
	os << "iterator<" << label(nBits) << "> ["
		<< this->index_ << "]"
		<< " segment:" << label(this->index_ / packing())
		<< " offset:" << label(this->index_ % packing())
		<< " value:" << this->get()
		<< nl;

	return os;
}

template<unsigned nBits>
AutLib::Ostream& AutLib::PackedList<nBits>::print(Ostream& os) const
{
	const label packLen = packedLength(size_);

	os << "PackedList<" << nBits << ">"
		<< " max_value:" << max_value()
		<< " packing:" << packing() << nl
		<< " count: " << count() << nl
		<< " size/capacity: " << size_ << "/" << capacity() << nl
		<< " storage/capacity: " << packLen << "/" << StorageList::size()
		<< "\n(\n";

	// mask value for complete segments
	unsigned int mask = maskLower(packing());

	for (label i = 0; i < packLen; i++)
	{
		const StorageType& rawBits = StorageList::operator[](i);

		// the final segment may not be full, modify mask accordingly
		if (i + 1 == packLen)
		{
			unsigned int endOff = size_ % packing();

			if (endOff)
			{
				mask = maskLower(endOff);
			}
			else
			{
				continue;
			}
		}

		for (unsigned int testBit = (1u << max_bits()); testBit; testBit >>= 1)
		{
			if (mask & testBit)
			{
				if (rawBits & testBit)
				{
					os << '1';
				}
				else
				{
					os << '-';
				}
			}
			else
			{
				os << 'x';
			}
		}
		os << '\n';
	}
	os << ")\n";

	return os;
}

template<unsigned nBits>
bool AutLib::PackedList<nBits>::trim()
{
	if (!size_)
	{
		return false;
	}

	// mask value for complete segments
	unsigned int mask = maskLower(packing());

	label currElem = packedLength(size_) - 1;
	unsigned int endOff = size_ % packing();

	// clear trailing bits on final segment
	if (endOff)
	{
		StorageList::operator[](currElem) &= maskLower(endOff);
	}

	// test entire segment
	while (currElem > 0 && !(StorageList::operator[](currElem) &= mask))
	{
		currElem--;
	}

	// test segment
	label newsize = (currElem + 1) * packing();

	// mask for the final segment
	mask = max_value() << (nBits * (packing() - 1));

	for (endOff = packing(); endOff >= 1; --endOff, --newsize)
	{
		if (StorageList::operator[](currElem) & mask)
		{
			break;
		}

		mask >>= nBits;
	}

	if (size_ == newsize)
	{
		return false;
	}

	size_ = newsize;
	return false;
}


template<unsigned nBits>
void AutLib::PackedList<nBits>::flip()
{
	label packLen = packedLength(size_);

	for (label i = 0; i < packLen; i++)
	{
		StorageList::operator[](i) = ~StorageList::operator[](i);
	}
}

template<unsigned nBits>
inline void AutLib::PackedList<nBits>::transfer(PackedList<nBits>& lst)
{
	size_ = lst.size_;
	lst.size_ = 0;

	StorageList::transfer(lst);
}


template<unsigned nBits>
inline AutLib::Xfer< AutLib::PackedList<nBits> >
AutLib::PackedList<nBits>::xfer()
{
	return xferMove(*this);
}


template<unsigned nBits>
inline unsigned int AutLib::PackedList<nBits>::get(const label i) const
{
#   ifdef FULLDEBUG
	if (i < 0)
	{
		FatalErrorIn("PackedList<nBits>::get(const label)")
			<< "negative index " << i << " max=" << size_ - 1
			<< abort(FatalError);
	}
#   endif

	// lazy evaluation - return 0 for out-of-range
	if (i < size_)
	{
		return iteratorBase(this, i).get();
	}
	else
	{
		return 0;
	}
}


template<unsigned nBits>
inline unsigned int AutLib::PackedList<nBits>::operator[](const label i) const
{
	// lazy evaluation - return 0 for out-of-range
	if (i < size_)
	{
		return iteratorBase(this, i).get();
	}
	else
	{
		return 0;
	}
}


template<unsigned nBits>
inline bool AutLib::PackedList<nBits>::set
(
	const label i,
	const unsigned int val
)
{
#   ifdef FULLDEBUG
	if (i < 0)
	{
		FatalErrorIn("PackedList<nBits>::set(const label)")
			<< "negative index " << i << " max=" << size_ - 1
			<< abort(FatalError);
	}
#   endif

	// lazy evaluation - increase size on assigment
	if (i >= size_)
	{
		resize(i + 1);
	}

	return iteratorBase(this, i).set(val);
}


template<unsigned nBits>
inline bool AutLib::PackedList<nBits>::unset(const label i)
{
	// lazy - ignore out-of-bounds
	if (i < 0 || i >= size_)
	{
		return false;
	}

	return iteratorBase(this, i).set(0u);
}


template<unsigned nBits>
inline void AutLib::PackedList<nBits>::append(const unsigned int val)
{
	label elemI = size_;
	reserve(elemI + 1);
	size_++;

	iteratorBase(this, elemI).set(val);
}


template<unsigned nBits>
inline unsigned int AutLib::PackedList<nBits>::remove()
{
	if (!size_)
	{
		FatalErrorIn
		(
			"AutLib::PackedList<nBits>::remove()"
		) << "List is empty" << abort(FatalError);
	}

	label elemI = size_ - 1;
	const unsigned int val = iteratorBase(this, elemI).get();
	resize(elemI);

	return val;
}


template<unsigned nBits>
inline typename AutLib::PackedList<nBits>::iteratorBase
AutLib::PackedList<nBits>::operator[](const label i)
{
	return iteratorBase(this, i);
}


namespace AutLib
{
	// specialization for nBits=1
	template<>
	inline void AutLib::PackedList<1>::operator=(const unsigned int val)
	{
		if (val)
		{
			StorageList::operator=(~0u);
		}
		else
		{
			StorageList::operator=(0u);
		}
	}
}


template<unsigned nBits>
inline void AutLib::PackedList<nBits>::operator=(const unsigned int val)
{
	if (val)
	{
		unsigned int fill = val;

		if (fill & ~max_value())
		{
			// treat overflow as max_value
			fill = ~0u;
		}
		else
		{
			for (unsigned int i = 1; i < packing(); ++i)
			{
				fill |= (fill << nBits);
			}
		}

		StorageList::operator=(fill);
	}
	else
	{
		StorageList::operator=(0u);
	}
}

template<unsigned nBits>
void AutLib::PackedList<nBits>::operator=(const PackedList<nBits>& lst)
{
	StorageList::operator=(lst);
	size_ = lst.size();
}


template<unsigned nBits>
void AutLib::PackedList<nBits>::operator=(const UList<label>& lst)
{
	setCapacity(lst.size());
	size_ = lst.size();

	for (AutLib::label i = 0; i < (lst).size(); i++)
	{
		set(i, lst[i]);
	}
}