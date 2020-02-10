#pragma once
// * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * * //

template<class T>
void tnbLib::SortableList<T>::sortIndices(List<label>& order) const
{
	// list lengths must be identical
	if (order.size() != this->size())
	{
		// avoid copying any elements, they are overwritten anyhow
		order.clear();
		order.setSize(this->size());
	}

	forAll(order, elemI)
	{
		order[elemI] = elemI;
	}

	tnbLib::stableSort(order, typename UList<T>::less(*this));
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class T>
tnbLib::SortableList<T>::SortableList()
{}


template<class T>
tnbLib::SortableList<T>::SortableList(const UList<T>& values)
	: List<T>(values)
{
	sort();
}


template<class T>
tnbLib::SortableList<T>::SortableList(const Xfer<List<T>>& values)
	: List<T>(values)
{
	sort();
}


template<class T>
tnbLib::SortableList<T>::SortableList(const label size)
	: List<T>(size)
{}


template<class T>
tnbLib::SortableList<T>::SortableList(const label size, const T& val)
	: List<T>(size, val)
{}


template<class T>
tnbLib::SortableList<T>::SortableList(const SortableList<T>& lst)
	: List<T>(lst)
	, indices_(lst.indices())
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //


template<class T>
void tnbLib::SortableList<T>::clear()
{
	List<T>::clear();
	indices_.clear();
}


template<class T>
tnbLib::List<T>& tnbLib::SortableList<T>::shrink()
{
	indices_.clear();
	return static_cast<List<T>&>(*this);
}


template<class T>
void tnbLib::SortableList<T>::sort()
{
	sortIndices(indices_);

	List<T> lst(this->size());
	forAll(indices_, i)
	{
		lst[i] = this->operator[](indices_[i]);
	}

	List<T>::transfer(lst);
}


template<class T>
void tnbLib::SortableList<T>::reverseSort()
{
	sortIndices(indices_);

	List<T> lst(this->size());
	label endI = indices_.size();
	forAll(indices_, i)
	{
		lst[--endI] = this->operator[](indices_[i]);
	}

	List<T>::transfer(lst);
}


template<class T>
tnbLib::Xfer<tnbLib::List<T>> tnbLib::SortableList<T>::xfer()
{
	return xferMoveTo<List<T>>(*this);
}


// * * * * * * * * * * * * * * * Member Operators  * * * * * * * * * * * * * //

template<class T>
inline void tnbLib::SortableList<T>::operator=(const T& t)
{
	UList<T>::operator=(t);
}


template<class T>
inline void tnbLib::SortableList<T>::operator=(const UList<T>& rhs)
{
	List<T>::operator=(rhs);
	indices_.clear();
}


template<class T>
inline void tnbLib::SortableList<T>::operator=(const SortableList<T>& rhs)
{
	List<T>::operator=(rhs);
	indices_ = rhs.indices();
}


// ************************************************************************* //