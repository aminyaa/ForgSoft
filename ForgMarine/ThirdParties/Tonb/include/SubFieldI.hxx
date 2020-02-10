#pragma once
// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class Type>
tnbLib::SubField<Type>::SubField
(
	const SubList<Type>& list
)
	:
	SubList<Type>(list)
{}


template<class Type>
tnbLib::SubField<Type>::SubField
(
	const UList<Type>& list
)
	:
	SubList<Type>(list, list.size())
{}


template<class Type>
tnbLib::SubField<Type>::SubField
(
	const UList<Type>& list,
	const label subSize
)
	:
	SubList<Type>(list, subSize)
{}


template<class Type>
tnbLib::SubField<Type>::SubField
(
	const UList<Type>& list,
	const label subSize,
	const label startIndex
)
	:
	SubList<Type>(list, subSize, startIndex)
{}


template<class Type>
tnbLib::SubField<Type>::SubField
(
	const SubField<Type>& sfield
)
	: refCount()
	, SubList<Type>(sfield)
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class Type>
const tnbLib::SubField<Type>& tnbLib::SubField<Type>::null()
{
	// Dangerous, but no null constructor.  Reconsider.  HJ, 10/Apr/2013
	SubField<Type>* nullPtr = reinterpret_cast<SubField<Type>*>(NULL);
	return *nullPtr;
}


template<class Type>
tnbLib::tmp<tnbLib::Field<typename tnbLib::SubField<Type>::cmptType> >
tnbLib::SubField<Type>::component
(
	const direction d
) const
{
	return (reinterpret_cast<const Field<Type>&>(*this)).component(d);
}


template<class Type>
tnbLib::tmp<tnbLib::Field<Type> > tnbLib::SubField<Type>::T() const
{
	return (reinterpret_cast<const Field<Type>&>(*this)).T();
}


// * * * * * * * * * * * * * * * Member Operators  * * * * * * * * * * * * * //

template<class Type>
void tnbLib::SubField<Type>::operator=(const SubField<Type>& rhs)
{
	UList<Type>::operator=(rhs);
}


template<class Type>
tnbLib::SubField<Type>::operator const tnbLib::Field<Type>&() const
{
	return *reinterpret_cast<const Field<Type>*>(this);
}


// ************************************************************************* //