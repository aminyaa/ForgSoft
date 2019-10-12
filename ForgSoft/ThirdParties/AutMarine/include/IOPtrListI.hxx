#pragma once
template<class T>
template<class INew>
AutLib::IOPtrList<T>::IOPtrList(const IOobject& io, const INew& inewt)
	: regIOobject(io)
{
	if (io.readOpt() == IOobject::MUST_READ || (io.readOpt() == IOobject::READ_IF_PRESENT && headerOk()))
	{
		PtrList<T>::read(readStream(typeName), inewt);
		close();
	}
}


template<class T>
AutLib::IOPtrList<T>::IOPtrList(const IOobject& io)
	: regIOobject(io)
{
	if (io.readOpt() == IOobject::MUST_READ || (io.readOpt() == IOobject::READ_IF_PRESENT && headerOk()))
	{
		PtrList<T>::read(readStream(typeName), INew<T>());
		close();
	}
}


template<class T>
AutLib::IOPtrList<T>::IOPtrList(const IOobject& io, const label s)
	: regIOobject(io)
	, PtrList<T>(s)
{
	if (io.readOpt() != IOobject::NO_READ)
	{
		FatalErrorIn("IOPtrList<T>::IOPtrList(const IOobject&, const label)")
			<< "NO_READ must be set if specifying size" << nl
			<< exit(FatalError);
	}
}


template<class T>
AutLib::IOPtrList<T>::IOPtrList(const IOobject& io, const PtrList<T>& list)
	: regIOobject(io)
{
	if (io.readOpt() == IOobject::MUST_READ || (io.readOpt() == IOobject::READ_IF_PRESENT && headerOk()))
	{
		PtrList<T>::read(readStream(typeName), INew<T>());
		close();
	}
	else
	{
		PtrList<T>::operator=(list);
	}
}


template<class T>
AutLib::IOPtrList<T>::IOPtrList(const IOobject& io, const Xfer<PtrList<T> >& list)
	: regIOobject(io)
{
	PtrList<T>::transfer(list());

	if (io.readOpt() == IOobject::MUST_READ || (io.readOpt() == IOobject::READ_IF_PRESENT && headerOk()))
	{
		PtrList<T>::read(readStream(typeName), INew<T>());
		close();
	}
}

template<class T>
AutLib::IOPtrList<T>::~IOPtrList()
{
}

template<class T>
bool AutLib::IOPtrList<T>::writeData(Ostream& os) const
{
	return (os << *this).good();
}

template<class T>
void AutLib::IOPtrList<T>::operator=(const IOPtrList<T>& rhs)
{
	PtrList<T>::operator=(rhs);
}
