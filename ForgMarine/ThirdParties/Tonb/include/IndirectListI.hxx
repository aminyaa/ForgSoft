#pragma once
// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class T>
tnbLib::IndirectList<T>::IndirectList
(
	const UList<T>& completeList,
	const UList<label>& addr
)
	: completeList_(const_cast<UList<T>&>(completeList))
	, addressing_(addr)
{
#   ifdef FULLDEBUG
	if (completeList_.empty() && !addressing_.empty())
	{
		FatalErrorIn
		(
			"tnbLib::IndirectList<T>::IndirectList\n"
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


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class T>
tnbLib::label tnbLib::IndirectList<T>::size() const
{
	return addressing_.size();
}


template<class T>
bool tnbLib::IndirectList<T>::empty() const
{
	return addressing_.empty();
}


template<class T>
const tnbLib::UList<T>& tnbLib::IndirectList<T>::completeList() const
{
	return completeList_;
}


template<class T>
const tnbLib::List<tnbLib::label>& tnbLib::IndirectList<T>::addressing() const
{
	return addressing_;
}


template<class T>
void tnbLib::IndirectList<T>::resetAddressing
(
	const UList<label>& addr
)
{
	addressing_ = addr;
}


// * * * * * * * * * * * * * * * Member Operators  * * * * * * * * * * * * * //

template<class T>
tnbLib::List<T> tnbLib::IndirectList<T>::operator()() const
{
	List<T> result(size());

	forAll(*this, i)
	{
		result[i] = operator[](i);
	}

	return result;
}


template<class T>
T& tnbLib::IndirectList<T>::operator[](const label i)
{
	return completeList_[addressing_[i]];
}


template<class T>
const T& tnbLib::IndirectList<T>::operator[](const label i) const
{
	return completeList_[addressing_[i]];
}


template<class T>
void tnbLib::IndirectList<T>::operator=(const UList<T>& ae)
{
	if (addressing_.size() != ae.size())
	{
		FatalErrorIn("IndirectList<T>::operator=(const UList<T>&)")
			<< "Addressing and list of addressed elements "
			"have different sizes: "
			<< addressing_.size() << " " << ae.size()
			<< abort(FatalError);
	}

	forAll(addressing_, i)
	{
		completeList_[addressing_[i]] = ae[i];
	}
}


template<class T>
void tnbLib::IndirectList<T>::operator=(const T& t)
{
	forAll(addressing_, i)
	{
		completeList_[addressing_[i]] = t;
	}
}


// ************************************************************************* //