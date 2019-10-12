#pragma once
template<class LListBase, class T>
AutLib::UILList<LListBase, T>::UILList(const UILList<LListBase, T>& lst)
{
	for (const_iterator iter = lst.begin(); iter != lst.end(); ++iter)
	{
		this->append(&iter());
	}
}

template<class LListBase, class T>
void AutLib::UILList<LListBase, T>::operator=(const UILList<LListBase, T>& rhs)
{
	LListBase::clear();

	for (const_iterator iter = rhs.begin(); iter != rhs.end(); ++iter)
	{
		this->append(&iter());
	}
}


template<class LListBase, class T>
bool AutLib::UILList<LListBase, T>::operator==(const UILList<LListBase, T>& rhs) const
{
	if (this->size() != rhs.size())
	{
		return false;
	}

	bool equal = true;

	const_iterator iter1 = this->begin();
	const_iterator iter2 = rhs.begin();

	for (; iter1 != this->end(); ++iter1, ++iter2)
	{
		equal = equal && iter1() == iter2();
	}

	return equal;
}


// Comparison for inequality
template<class LListBase, class T>
bool AutLib::UILList<LListBase, T>::operator!=(const UILList<LListBase, T>& rhs) const
{
	return !operator==(rhs);
}