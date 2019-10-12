#pragma once
template<class T>
inline AutLib::IndirectList<T>::IndirectList
(
	const UList<T>& completeList,
	const UList<label>& addr
)
	: completeList_(const_cast<UList<T>&>(completeList))
	, addressing_(addr.castToList())
{
#   ifdef FULLDEBUG
	if (completeList_.empty() && !addressing_.empty())
	{
		FatalErrorIn
		(
			"inline AutLib::IndirectList<T>::IndirectList\n"
			"(\n"
			"    const UList<T>& completeList,\n"
			"    const UList<label>& addr\n"
			")"
		) << "Incorrect definition of indirect list.  "
			<< "Complete list is empty and addressing is not"
			<< abort(FatalError);
	}
#   endif
}

template<class T>
inline AutLib::label AutLib::IndirectList<T>::size() const
{
	return addressing_.size();
}


template<class T>
inline bool AutLib::IndirectList<T>::empty() const
{
	return addressing_.empty();
}


template<class T>
inline const AutLib::UList<T>& AutLib::IndirectList<T>::completeList() const
{
	return completeList_;
}


template<class T>
inline const AutLib::List<AutLib::label>& AutLib::IndirectList<T>::addressing() const
{
	return addressing_;
}


template<class T>
inline void AutLib::IndirectList<T>::resetAddressing
(
	const UList<label>& addr
)
{
	addressing_ = addr;
}

template<class T>
inline AutLib::List<T> AutLib::IndirectList<T>::operator()() const
{
	List<T> result(size());

	for (label i = 0; i < (*this).size(); i++)
	{
		result[i] = operator[](i);
	}

	return result;
}


template<class T>
inline T& AutLib::IndirectList<T>::operator[](const label i)
{
	return completeList_[addressing_[i]];
}


template<class T>
inline const T& AutLib::IndirectList<T>::operator[](const label i) const
{
	return completeList_[addressing_[i]];
}


template<class T>
inline void AutLib::IndirectList<T>::operator=(const UList<T>& ae)
{
	if (addressing_.size() != ae.size())
	{
		FatalErrorIn("IndirectList<T>::operator=(const UList<T>&)")
			<< "Addressing and list of addressed elements "
			"have different sizes: "
			<< addressing_.size() << " " << ae.size()
			<< abort(FatalError);
	}

	for (label i = 0; i < (addressing_).size(); i++)
	{
		completeList_[addressing_[i]] = ae[i];
	}
}


template<class T>
inline void AutLib::IndirectList<T>::operator=(const T& t)
{
	for (label i = 0; i < (addressing_).size(); i++)
	{
		completeList_[addressing_[i]] = t;
	}
}
