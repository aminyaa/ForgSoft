#pragma once
template<class Type>
AutLib::IOField<Type>::IOField(const IOobject& io)
	: regIOobject(io)
{
	if (io.readOpt() == IOobject::MUST_READ || (io.readOpt() == IOobject::READ_IF_PRESENT && headerOk()))
	{
		readStream(typeName) >> *this;
		close();
	}
}


template<class Type>
AutLib::IOField<Type>::IOField(const IOobject& io, const label size)
	: regIOobject(io)
{
	if (io.readOpt() == IOobject::MUST_READ || (io.readOpt() == IOobject::READ_IF_PRESENT && headerOk()))
	{
		readStream(typeName) >> *this;
		close();
	}
	else
	{
		Field<Type>::setSize(size);
	}
}


template<class Type>
AutLib::IOField<Type>::IOField(const IOobject& io, const Field<Type>& f)
	: regIOobject(io)
{
	if (io.readOpt() == IOobject::MUST_READ || (io.readOpt() == IOobject::READ_IF_PRESENT && headerOk()))
	{
		readStream(typeName) >> *this;
		close();
	}
	else
	{
		Field<Type>::operator=(f);
	}
}


template<class Type>
AutLib::IOField<Type>::IOField(const IOobject& io, const Xfer<Field<Type> >& f)
	: regIOobject(io)
{
	Field<Type>::transfer(f());

	if (io.readOpt() == IOobject::MUST_READ || (io.readOpt() == IOobject::READ_IF_PRESENT && headerOk()))
	{
		readStream(typeName) >> *this;
		close();
	}
}

template<class Type>
AutLib::IOField<Type>::~IOField()
{}

template<class Type>
bool AutLib::IOField<Type>::writeData(Ostream& os) const
{
	return (os << static_cast<const Field<Type>&>(*this)).good();
}

template<class Type>
void AutLib::IOField<Type>::operator=(const IOField<Type>& rhs)
{
	Field<Type>::operator=(rhs);
}


template<class Type>
void AutLib::IOField<Type>::operator=(const Field<Type>& rhs)
{
	Field<Type>::operator=(rhs);
}