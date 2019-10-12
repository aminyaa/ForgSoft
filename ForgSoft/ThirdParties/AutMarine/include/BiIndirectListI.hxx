#pragma once
template<class T>
inline AutLib::BiIndirectList<T>::BiIndirectList
(
	const UList<T>& posList,
	const UList<T>& negList,
	const UList<label>& addr
)
	: posList_(const_cast<UList<T>&>(posList))
	, negList_(const_cast<UList<T>&>(negList))
	, addressing_(addr)
{}

template<class T>
inline AutLib::label AutLib::BiIndirectList<T>::size() const
{
	return addressing_.size();
}


template<class T>
inline bool AutLib::BiIndirectList<T>::empty() const
{
	return addressing_.empty();
}


template<class T>
inline const AutLib::UList<T>& AutLib::BiIndirectList<T>::posList() const
{
	return posList_;
}


template<class T>
inline const AutLib::UList<T>& AutLib::BiIndirectList<T>::negList() const
{
	return negList_;
}


template<class T>
inline const AutLib::List<AutLib::label>& AutLib::BiIndirectList<T>::addressing()
const
{
	return addressing_;
}


template<class T>
inline AutLib::List<AutLib::label>& AutLib::BiIndirectList<T>::addressing()
{
	return addressing_;
}


template<class T>
inline AutLib::label AutLib::BiIndirectList<T>::posIndex(const label i)
{
	return i;
}


template<class T>
inline AutLib::label AutLib::BiIndirectList<T>::negIndex(const label i)
{
	return -i - 1;
}

template<class T>
inline AutLib::List<T> AutLib::BiIndirectList<T>::operator()() const
{
	List<T> result(size());

	for (label i = 0; i < (*this).size(); i++)
	{
		result[i] = operator[](i);
	}

	return std::move(result);
}


template<class T>
inline T& AutLib::BiIndirectList<T>::operator[](const label i)
{
	label index = addressing_[i];

	if (index >= 0)
	{
		return posList_[index];
	}
	else
	{
		return negList_[-index - 1];
	}
}


template<class T>
inline const T& AutLib::BiIndirectList<T>::operator[](const label i) const
{
	label index = addressing_[i];

	if (index >= 0)
	{
		return posList_[index];
	}
	else
	{
		return negList_[-index - 1];
	}
}


template<class T>
inline void AutLib::BiIndirectList<T>::operator=(const UList<T>& ae)
{
	if (addressing_.size() != ae.size())
	{
		FatalErrorIn("BiIndirectList<T>::operator=(const UList<T>&)")
			<< "Addressing and list of addressed elements "
			"have different sizes: "
			<< addressing_.size() << " " << ae.size()
			<< abort(FatalError);
	}

	for (label i = 0; i < (addressing_).size(); i++)
	{
		operator[](i) = ae[i];
	}
}


template<class T>
inline void AutLib::BiIndirectList<T>::operator=(const T& t)
{
	for (label i = 0; i < (addressing_).size(); i++)
	{
		operator[](i) = t;
	}
}