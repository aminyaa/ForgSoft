#pragma once
inline 
bool AutLib::regIOobject::ownedByRegistry() const
{
	return ownedByRegistry_;
}


inline 
void AutLib::regIOobject::store()
{
	ownedByRegistry_ = true;
}


template<class Type>
inline Type& AutLib::regIOobject::store(Type* tPtr)
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
inline Type& AutLib::regIOobject::store(autoPtr<Type>& atPtr)
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


inline 
void AutLib::regIOobject::release()
{
	ownedByRegistry_ = false;
}


inline 
AutLib::label AutLib::regIOobject::eventNo() const
{
	return eventNo_;
}

inline 
AutLib::label& AutLib::regIOobject::eventNo()
{
	return eventNo_;
}