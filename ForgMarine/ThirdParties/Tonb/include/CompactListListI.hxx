#pragma once
// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class T>
tnbLib::CompactListList<T>::CompactListList()
{}


template<class T>
tnbLib::CompactListList<T>::CompactListList
(
	const label nRows,
	const label nData
)
	:
	offsets_(nRows, 0),
	m_(nData)
{}


template<class T>
tnbLib::CompactListList<T>::CompactListList
(
	const label nRows,
	const label nData,
	const T& t
)
	:
	offsets_(nRows, 0),
	m_(nData, t)
{}


template<class T>
tnbLib::autoPtr<tnbLib::CompactListList<T>>
tnbLib::CompactListList<T>::clone() const
{
	return autoPtr<CompactListList<T>>(new CompactListList<T>(*this));
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class T>
const tnbLib::CompactListList<T>& tnbLib::CompactListList<T>::null()
{
	return *reinterpret_cast<CompactListList<T>*>(0);
}


template<class T>
tnbLib::label tnbLib::CompactListList<T>::size() const
{
	return offsets_.size();
}


template<class T>
bool tnbLib::CompactListList<T>::empty() const
{
	return offsets_.empty();
}


template<class T>
const tnbLib::List<tnbLib::label>& tnbLib::CompactListList<T>::offsets() const
{
	return offsets_;
}


template<class T>
tnbLib::List<tnbLib::label>& tnbLib::CompactListList<T>::offsets()
{
	return offsets_;
}


template<class T>
const tnbLib::List<T>& tnbLib::CompactListList<T>::m() const
{
	return m_;
}


template<class T>
tnbLib::List<T>& tnbLib::CompactListList<T>::m()
{
	return m_;
}


template<class T>
tnbLib::label tnbLib::CompactListList<T>::index
(
	const label i,
	const label j
) const
{
	if (i == 0)
	{
		return j;
	}
	else
	{
		return offsets_[i - 1] + j;
	}
}


template<class T>
tnbLib::label tnbLib::CompactListList<T>::whichRow(const label i) const
{
	if (i < 0 || i >= m_.size())
	{
		FatalErrorIn
		(
			"CompactListList<T>::whichRow(const label) const"
		) << "Index " << i << " outside 0.." << m_.size()
			<< abort(FatalError);
	}

	forAll(offsets_, rowI)
	{
		if (i < offsets_[rowI])
		{
			return rowI;
		}
	}

	return -1;
}


template<class T>
tnbLib::label tnbLib::CompactListList<T>::whichColumn
(
	const label row,
	const label i
) const
{
	return i - index(row, 0);
}


template<class T>
tnbLib::Xfer<tnbLib::CompactListList<T>> tnbLib::CompactListList<T>::xfer()
{
	return xferMove(*this);
}


template<class T>
void tnbLib::CompactListList<T>::resize(const label nRows)
{
	this->setSize(nRows);
}


template<class T>
void tnbLib::CompactListList<T>::resize
(
	const label nRows,
	const label nData
)
{
	this->setSize(nRows, nData);
}


template<class T>
void tnbLib::CompactListList<T>::resize
(
	const label nRows,
	const label nData,
	const T& t
)
{
	this->setSize(nRows, nData, t);
}


template<class T>
void tnbLib::CompactListList<T>::resize(const UList<label>& rowSizes)
{
	this->setSize(rowSizes);
}


// * * * * * * * * * * * * * * * Member Operators  * * * * * * * * * * * * * //

template<class T>
tnbLib::UList<T> tnbLib::CompactListList<T>::operator[]
(
	const label i
	)
{
	if (i == 0)
	{
		return UList<T>(m_.begin(), offsets_[i]);
	}
	else
	{
		return UList<T>(&m_[offsets_[i - 1]], offsets_[i] - offsets_[i - 1]);
	}
}


template<class T>
const tnbLib::UList<T> tnbLib::CompactListList<T>::operator[]
(
	const label i
	) const
{
	if (i == 0)
	{
		return UList<T>(m_.begin(), offsets_[i]);
	}
	else
	{
		return UList<T>(&m_[offsets_[i - 1]], offsets_[i] - offsets_[i - 1]);
	}
}


template<class T>
T& tnbLib::CompactListList<T>::operator()
(
	const label i,
	const label j
	)
{
	return m_[index(i, j)];
}


template<class T>
const T& tnbLib::CompactListList<T>::operator()
(
	const label i,
	const label j
	) const
{
	return m_[index(i, j)];
}


template<class T>
void tnbLib::CompactListList<T>::operator=(const T& t)
{
	m_ = t;
}


// ************************************************************************* //

//- Moved from cxx


// * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * * //

template<class T>
tnbLib::CompactListList<T>::CompactListList(const List<List<T>>& ll)
	:
	offsets_(ll.size())
{
	label sumSize = 0;
	forAll(ll, i)
	{
		sumSize += ll[i].size();
		offsets_[i] = sumSize;
	}

	m_.setSize(sumSize);

	label k = 0;
	forAll(ll, i)
	{
		const List<T>& lli = ll[i];

		forAll(lli, j)
		{
			m_[k++] = lli[j];
		}
	}
}


template<class T>
tnbLib::CompactListList<T>::CompactListList
(
	const UList<label>& rowSizes
)
	:
	offsets_(rowSizes.size())
{
	label sumSize = 0;
	forAll(rowSizes, i)
	{
		sumSize += rowSizes[i];
		offsets_[i] = sumSize;
	}

	m_.setSize(sumSize);
}


template<class T>
tnbLib::CompactListList<T>::CompactListList
(
	const UList<label>& rowSizes,
	const T& t
)
	:
	offsets_(rowSizes.size())
{
	label sumSize = 0;
	forAll(rowSizes, i)
	{
		sumSize += rowSizes[i];
		offsets_[i] = sumSize;
	}

	m_.setSize(sumSize, t);
}


template<class T>
tnbLib::CompactListList<T>::CompactListList
(
	const Xfer<CompactListList<T>>& lst
)
{
	transfer(lst());
}


template<class T>
tnbLib::CompactListList<T>::CompactListList
(
	CompactListList<T>& lst,
	bool reUse
)
	:
	offsets_(lst.offsets_, reUse),
	m_(lst.m_, reUse)
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class T>
void tnbLib::CompactListList<T>::setSize(const label nRows)
{
	if (nRows == 0)
	{
		clear();
	}
	if (nRows < offsets_.size())
	{
		offsets_.setSize(nRows);
		m_.setSize(offsets_[nRows - 1]);
	}
	else if (nRows > offsets_.size())
	{
		FatalErrorIn("CompactListList<T>::setSize(const label nRows)")
			<< "Cannot be used to extend the list from " << offsets_.size()
			<< " to " << nRows << nl
			<< "    Please use one of the other setSize member functions"
			<< abort(FatalError);
	}
}


template<class T>
void tnbLib::CompactListList<T>::setSize
(
	const label nRows,
	const label nData
)
{
	offsets_.setSize(nRows);
	m_.setSize(nData);
}


template<class T>
void tnbLib::CompactListList<T>::setSize
(
	const label nRows,
	const label nData,
	const T& t
)
{
	offsets_.setSize(nRows);
	m_.setSize(nData, t);
}


template<class T>
void tnbLib::CompactListList<T>::setSize(const UList<label>& rowSizes)
{
	offsets_.setSize(rowSizes.size());

	label sumSize = 0;
	forAll(rowSizes, i)
	{
		sumSize += rowSizes[i];
		offsets_[i] = sumSize;
	}

	m_.setSize(sumSize);
}


template<class T>
tnbLib::labelList tnbLib::CompactListList<T>::sizes() const
{
	labelList rowSizes(offsets_.size());

	label prevOffset = 0;
	forAll(offsets_, i)
	{
		rowSizes[i] = offsets_[i] - prevOffset;
		prevOffset = offsets_[i];
	}
	return rowSizes;
}


template<class T>
void tnbLib::CompactListList<T>::clear()
{
	offsets_.clear();
	m_.clear();
}


template<class T>
void tnbLib::CompactListList<T>::transfer(CompactListList<T>& a)
{
	offsets_.transfer(a.offsets_);
	m_.transfer(a.m_);
}


// * * * * * * * * * * * * * * * Member Operators  * * * * * * * * * * * * * //

template<class T>
tnbLib::List<tnbLib::List<T>> tnbLib::CompactListList<T>::operator()() const
{
	List<List<T>> ll(offsets_.size());

	label offsetPrev = 0;
	forAll(offsets_, i)
	{
		List<T>& lst = ll[i];

		lst.setSize(offsets_[i] - offsetPrev);

		forAll(lst, j)
		{
			lst[j] = m_[offsetPrev + j];
		}

		offsetPrev = offsets_[i];
	}

	return ll;
}


// * * * * * * * * * * * * * * * *  IOStream operators * * * * * * * * * * * //

//- Moved from io.cxx

#include <Istream.hxx>

// * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * * //

template<class T>
tnbLib::CompactListList<T>::CompactListList(Istream& is)
{
	operator>>(is, *this);
}


// * * * * * * * * * * * * * * * IOstream Operators  * * * * * * * * * * * * //

template<class T>
tnbLib::Istream& tnbLib::operator>>(Istream& is, CompactListList<T>& lst)
{
	is >> lst.offsets_ >> lst.m_;
	return is;
}


template<class T>
tnbLib::Ostream& tnbLib::operator<<(Ostream& os, const CompactListList<T>& lst)
{
	os << lst.offsets_ << lst.m_;
	return os;
}


// ************************************************************************* //