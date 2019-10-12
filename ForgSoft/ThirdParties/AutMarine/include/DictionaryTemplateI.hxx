#pragma once
template<class T>
AutLib::Dictionary<T>::Dictionary()
{}

template<class T>
AutLib::Dictionary<T>::Dictionary(const Dictionary& dict)
	: DictionaryBase<IDLList<T>, T>(dict)
{}

template<class T>
bool AutLib::Dictionary<T>::erase(const word& keyword)
{
	T* tPtr;
	if (tPtr = this->remove(keyword))
	{
		delete tPtr;
		return true;
	}
	else
	{
		return false;
	}
}