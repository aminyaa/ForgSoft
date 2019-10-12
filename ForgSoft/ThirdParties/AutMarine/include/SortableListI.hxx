#pragma once
template<class T>
void AutLib::SortableList<T>::sortIndices(List<label>& order) const
{
	// list lengths must be identical
	if (order.size() != this->size())
	{
		// avoid copying any elements, they are overwritten anyhow
		order.clear();
		order.setSize(this->size());
	}

	for (label elemI = 0; elemI < (order).size(); elemI++)
	{
		order[elemI] = elemI;
	}

	AutLib::stableSort(order, typename UList<T>::less(*this));
}

template<class T>
AutLib::SortableList<T>::SortableList()
{}


template<class T>
AutLib::SortableList<T>::SortableList(const UList<T>& values)
	: List<T>(values.castToList())
{
	sort();
}


template<class T>
AutLib::SortableList<T>::SortableList(const Xfer<List<T> >& values)
	: List<T>(values)
{
	sort();
}


template<class T>
AutLib::SortableList<T>::SortableList(const label size)
	: List<T>(size)
{}


template<class T>
AutLib::SortableList<T>::SortableList(const label size, const T& val)
	: List<T>(size, val)
{}


template<class T>
AutLib::SortableList<T>::SortableList(const SortableList<T>& lst)
	: List<T>(lst)
	, indices_(lst.indices())
{}

template<class T>
void AutLib::SortableList<T>::clear()
{
	List<T>::clear();
	indices_.clear();
}


template<class T>
AutLib::List<T>& AutLib::SortableList<T>::shrink()
{
	indices_.clear();
	return static_cast<List<T>&>(*this);
}


template<class T>
void AutLib::SortableList<T>::sort()
{
	sortIndices(indices_);

	List<T> lst(this->size());
	for (label i = 0; i < (indices_).size(); i++)
	{
		lst[i] = this->operator[](indices_[i]);
	}

	List<T>::transfer(lst);
}


template<class T>
void AutLib::SortableList<T>::reverseSort()
{
	sortIndices(indices_);

	List<T> lst(this->size());
	label endI = indices_.size();
	for (label i = 0; i < (indices_).size(); i++)
	{
		lst[--endI] = this->operator[](indices_[i]);
	}

	List<T>::transfer(lst);
}


template<class T>
AutLib::Xfer<AutLib::List<T> > AutLib::SortableList<T>::xfer()
{
	return xferMoveTo<List<T> >(*this);
}

template<class T>
inline void AutLib::SortableList<T>::operator=(const T& t)
{
	UList<T>::operator=(t);
}


template<class T>
inline void AutLib::SortableList<T>::operator=(const UList<T>& rhs)
{
	List<T>::operator=(rhs);
	indices_.clear();
}


template<class T>
inline void AutLib::SortableList<T>::operator=(const SortableList<T>& rhs)
{
	List<T>::operator=(rhs);
	indices_ = rhs.indices();
}