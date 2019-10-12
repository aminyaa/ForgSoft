#pragma once
template<class Type>
AutLib::IOReferencer<Type>::IOReferencer(const IOobject& io)
	: regIOobject(io)
	, typePtr_(NULL)
{
	if
		(
			io.readOpt() != IOobject::NO_READ
			|| io.writeOpt() != IOobject::NO_WRITE
			)
	{
		FatalErrorIn("IOReferencer<Type>::IOReferencer")
			<< "IOReferencer can only be NO_READ, NO_WRITE."
			<< abort(FatalError);
	}
}


template<class Type>
AutLib::IOReferencer<Type>::IOReferencer
(
	const IOobject& io,
	Type* ptr
)
	: regIOobject(io)
	, typePtr_(ptr)
{
	if
		(
		(io.readOpt() != IOobject::NO_READ)
			|| (io.writeOpt() != IOobject::NO_WRITE)
			)
	{
		FatalErrorIn("IOReferencer<Type>::IOReferencer")
			<< "IOReferencer can only be NO_READ, NO_WRITE."
			<< abort(FatalError);
	}
}

template<class Type>
AutLib::IOReferencer<Type>::~IOReferencer()
{
	if (typePtr_)
	{
		delete typePtr_;
	}
}

template<class Type>
bool AutLib::IOReferencer<Type>::writeData(Ostream& os) const
{
	// do nothing
	return os.good();
}


template<class Type>
const Type& AutLib::IOReferencer<Type>::operator()() const
{
	if (!typePtr_)
	{
		FatalErrorIn
		(
			"IOReferencer<Type>::operator()"
		)
			<< "Attempting to derefence a null typePtr - use IOReferencer::set"
			<< "first."
			<< abort(FatalError);
	}

	return *typePtr_;
}


template<class Type>
Type& AutLib::IOReferencer<Type>::operator()()
{
	if (!typePtr_)
	{
		FatalErrorIn
		(
			"IOReferencer<Type>::operator()"
		)
			<< "Attempting to derefence a null typePtr - use IOReferencer::set"
			<< "first."
			<< abort(FatalError);
	}

	return *typePtr_;
}


template<class Type>
void AutLib::IOReferencer<Type>::set
(
	Type* ptr
)
{
	if (typePtr_)
	{
		delete typePtr_;
	}

	typePtr_ = ptr;
}