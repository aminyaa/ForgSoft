#pragma once
// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

inline bool tnbLib::regIOobject::ownedByRegistry() const
{
	return ownedByRegistry_;
}


inline void tnbLib::regIOobject::store()
{
	ownedByRegistry_ = true;
}


template<class Type>
inline Type& tnbLib::regIOobject::store(Type* tPtr)
{
	if (!tPtr)
	{
		FatalErrorIn("Type& regIOobject::store(Type*)")
			<< "object deallocated"
			<< abort(FatalError);
	}

	tPtr->regIOobject::ownedByRegistry_ = true;

	return *tPtr;
}


template<class Type>
inline Type& tnbLib::regIOobject::store(autoPtr<Type>& atPtr)
{
	Type* tPtr = atPtr.ptr();

	if (!tPtr)
	{
		FatalErrorIn
		(
			"Type& regIOobject::store(autoPtr<Type>&)"
		) << "object deallocated"
			<< abort(FatalError);
	}

	tPtr->regIOobject::ownedByRegistry_ = true;

	return *tPtr;
}


inline void tnbLib::regIOobject::release()
{
	ownedByRegistry_ = false;
}


inline tnbLib::label tnbLib::regIOobject::eventNo() const
{
	return eventNo_;
}

inline tnbLib::label& tnbLib::regIOobject::eventNo()
{
	return eventNo_;
}


// ************************************************************************* //