#pragma once
// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class T>
tnbLib::BiIndirectList<T>::BiIndirectList
(
	const UList<T>& posList,
	const UList<T>& negList,
	const UList<label>& addr
)
	:
	posList_(const_cast<UList<T>&>(posList)),
	negList_(const_cast<UList<T>&>(negList)),
	addressing_(addr)
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class T>
tnbLib::label tnbLib::BiIndirectList<T>::size() const
{
	return addressing_.size();
}


template<class T>
bool tnbLib::BiIndirectList<T>::empty() const
{
	return addressing_.empty();
}


template<class T>
const tnbLib::UList<T>& tnbLib::BiIndirectList<T>::posList() const
{
	return posList_;
}


template<class T>
const tnbLib::UList<T>& tnbLib::BiIndirectList<T>::negList() const
{
	return negList_;
}


template<class T>
const tnbLib::List<tnbLib::label>& tnbLib::BiIndirectList<T>::addressing()
const
{
	return addressing_;
}


template<class T>
tnbLib::List<tnbLib::label>& tnbLib::BiIndirectList<T>::addressing()
{
	return addressing_;
}


template<class T>
tnbLib::label tnbLib::BiIndirectList<T>::posIndex(const label i)
{
	return i;
}


template<class T>
tnbLib::label tnbLib::BiIndirectList<T>::negIndex(const label i)
{
	return -i - 1;
}


// * * * * * * * * * * * * * * * Member Operators  * * * * * * * * * * * * * //

template<class T>
tnbLib::List<T> tnbLib::BiIndirectList<T>::operator()() const
{
	List<T> result(size());

	forAll(*this, i)
	{
		result[i] = operator[](i);
	}

	return result;
}


template<class T>
T& tnbLib::BiIndirectList<T>::operator[](const label i)
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
const T& tnbLib::BiIndirectList<T>::operator[](const label i) const
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
void tnbLib::BiIndirectList<T>::operator=(const UList<T>& ae)
{
	if (addressing_.size() != ae.size())
	{
		FatalErrorIn("BiIndirectList<T>::operator=(const UList<T>&)")
			<< "Addressing and list of addressed elements "
			"have different sizes: "
			<< addressing_.size() << " " << ae.size()
			<< abort(FatalError);
	}

	forAll(addressing_, i)
	{
		operator[](i) = ae[i];
	}
}


template<class T>
void tnbLib::BiIndirectList<T>::operator=(const T& t)
{
	forAll(addressing_, i)
	{
		operator[](i) = t;
	}
}


// ************************************************************************* //