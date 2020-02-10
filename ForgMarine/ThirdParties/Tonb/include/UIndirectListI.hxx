#pragma once
// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class T>
tnbLib::UIndirectList<T>::UIndirectList
(
	const UList<T>& completeList,
	const UList<label>& addr
)
	:
	completeList_(const_cast<UList<T>&>(completeList)),
	addressing_(addr)
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class T>
tnbLib::label tnbLib::UIndirectList<T>::size() const
{
	return addressing_.size();
}


template<class T>
bool tnbLib::UIndirectList<T>::empty() const
{
	return addressing_.empty();
}


template<class T>
const tnbLib::UList<T>& tnbLib::UIndirectList<T>::completeList() const
{
	return completeList_;
}


template<class T>
const tnbLib::List<tnbLib::label>& tnbLib::UIndirectList<T>::addressing() const
{
	return addressing_;
}


// * * * * * * * * * * * * * * * Member Operators  * * * * * * * * * * * * * //

template<class T>
tnbLib::List<T> tnbLib::UIndirectList<T>::operator()() const
{
	List<T> result(size());

	forAll(*this, i)
	{
		result[i] = operator[](i);
	}

	return result;
}


template<class T>
T& tnbLib::UIndirectList<T>::operator[](const label i)
{
	return completeList_[addressing_[i]];
}


template<class T>
const T& tnbLib::UIndirectList<T>::operator[](const label i) const
{
	return completeList_[addressing_[i]];
}


template<class T>
void tnbLib::UIndirectList<T>::operator=(const UList<T>& ae)
{
	if (addressing_.size() != ae.size())
	{
		FatalErrorIn("UIndirectList<T>::operator=(const UList<T>&)")
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
void tnbLib::UIndirectList<T>::operator=(const T& t)
{
	forAll(addressing_, i)
	{
		completeList_[addressing_[i]] = t;
	}
}


// ************************************************************************* //