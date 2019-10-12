#pragma once
template<class T>
AutLib::IOMap<T>::IOMap(const IOobject& io)
	: regIOobject(io)
{
	if (io.readOpt() == IOobject::MUST_READ || (io.readOpt() == IOobject::READ_IF_PRESENT && headerOk()))
	{
		readStream(typeName) >> *this;
		close();
	}
}

template<class T>
AutLib::IOMap<T>::IOMap(const IOobject& io, const label size)
	: regIOobject(io)
{
	if (io.readOpt() == IOobject::MUST_READ || (io.readOpt() == IOobject::READ_IF_PRESENT && headerOk()))
	{
		readStream(typeName) >> *this;
		close();
	}
	else
	{
		Map<T>::setSize(size);
	}
}


template<class T>
AutLib::IOMap<T>::IOMap(const IOobject& io, const Map<T>& map)
	: regIOobject(io)
{
	if (io.readOpt() == IOobject::MUST_READ || (io.readOpt() == IOobject::READ_IF_PRESENT && headerOk()))
	{
		readStream(typeName) >> *this;
		close();
	}
	else
	{
		Map<T>::operator=(map);
	}
}


template<class T>
AutLib::IOMap<T>::IOMap(const IOobject& io, const Xfer<Map<T> >& map)
	: regIOobject(io)
{
	Map<T>::transfer(map());

	if (io.readOpt() == IOobject::MUST_READ || (io.readOpt() == IOobject::READ_IF_PRESENT && headerOk()))
	{
		readStream(typeName) >> *this;
		close();
	}
}

template<class T>
AutLib::IOMap<T>::~IOMap()
{
}

template<class T>
bool AutLib::IOMap<T>::writeData(Ostream& os) const
{
	return (os << *this).good();
}

template<class T>
void AutLib::IOMap<T>::operator=(const IOMap<T>& rhs)
{
	Map<T>::operator=(rhs);
}


template<class T>
void AutLib::IOMap<T>::operator=(const Map<T>& rhs)
{
	Map<T>::operator=(rhs);
}