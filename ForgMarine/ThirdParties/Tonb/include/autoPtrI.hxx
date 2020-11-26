#pragma once
#include <error.hxx>
#include <OSstream.hxx>

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class T>
inline tnbLib::autoPtr<T>::autoPtr(T* tPtr)
	:
	ptr_(tPtr)
{}


template<class T>
inline tnbLib::autoPtr<T>::autoPtr(const autoPtr<T>& ap)
	:
	ptr_(ap.ptr_)
{
	ap.ptr_ = 0;
}


template<class T>
inline tnbLib::autoPtr<T>::~autoPtr()
{
	clear();
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class T>
inline bool tnbLib::autoPtr<T>::empty() const
{
	return !ptr_;
}


template<class T>
inline bool tnbLib::autoPtr<T>::valid() const
{
	return ptr_;
}


template<class T>
inline T* tnbLib::autoPtr<T>::ptr()
{
	T* ptr = ptr_;
	ptr_ = NULL;
	return ptr;
}


template<class T>
inline void tnbLib::autoPtr<T>::set(T* p)
{
	if (ptr_)
	{
		FatalErrorIn("void autoPtr<T>::set(T*)")
			<< "object already allocated"
			<< abort(FatalError);
	}

	ptr_ = p;
}


template<class T>
inline void tnbLib::autoPtr<T>::reset(T* p)
{
	if (ptr_)
	{
		delete ptr_;
	}

	ptr_ = p;
}


template<class T>
inline void tnbLib::autoPtr<T>::clear()
{
	reset(NULL);
}


// * * * * * * * * * * * * * * * Member Operators  * * * * * * * * * * * * * //

template<class T>
inline T& tnbLib::autoPtr<T>::operator()()
{
	if (!ptr_)
	{
		FatalErrorIn("T& autoPtr<T>::operator()()")
			<< "object is not allocated"
			<< abort(FatalError);
	}

	return *ptr_;
}


template<class T>
inline const T& tnbLib::autoPtr<T>::operator()() const
{
	if (!ptr_)
	{
		FatalErrorIn("const T& autoPtr<T>::operator()() const")
			<< "object is not allocated"
			<< abort(FatalError);
	}

	return *ptr_;
}


/*
template<class T>
inline T& tnbLib::autoPtr<T>::operator*()
{
	return operator()();
}


template<class T>
inline const T& tnbLib::autoPtr<T>::operator*() const
{
	return operator()();
}
*/


template<class T>
inline tnbLib::autoPtr<T>::operator const T&() const
{
	return operator()();
}


template<class T>
inline T* tnbLib::autoPtr<T>::operator->()
{
	if (!ptr_)
	{
		FatalErrorIn("autoPtr<T>::operator->()")
			<< "object is not allocated"
			<< abort(FatalError);
	}

	return ptr_;
}


template<class T>
inline const T* tnbLib::autoPtr<T>::operator->() const
{
	return const_cast<autoPtr<T>&>(*this).operator->();
}


template<class T>
inline void tnbLib::autoPtr<T>::operator=(const autoPtr<T>& ap)
{
	if (this != &ap)
	{
		reset(const_cast<autoPtr<T>&>(ap).ptr());
	}
}


// ************************************************************************* //