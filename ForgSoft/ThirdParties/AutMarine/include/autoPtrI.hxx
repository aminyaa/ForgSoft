#pragma once
#include <error.hxx>
#include <OSstream.hxx>
template<class T>
inline T * AutLib::autoPtr<T>::ptr()
{
	T* ptr = ptr_;
	ptr_ = NULL;
	return ptr;
}

template<class T>
inline void AutLib::autoPtr<T>::set(T* p)
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
inline void AutLib::autoPtr<T>::reset(T* p)
{
	if (ptr_)
	{
		delete ptr_;
	}

	ptr_ = p;
}


template<class T>
inline void AutLib::autoPtr<T>::clear()
{
	reset(NULL);
}

template<class T>
inline T& AutLib::autoPtr<T>::operator()()
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
inline const T& AutLib::autoPtr<T>::operator()() const
{
	if (!ptr_)
	{
		FatalErrorIn("const T& autoPtr<T>::operator()() const")
			<< "object is not allocated"
			<< abort(FatalError);
	}

	return *ptr_;
}

template<class T>
inline AutLib::autoPtr<T>::operator const T&() const
{
	return operator()();
}


template<class T>
inline T* AutLib::autoPtr<T>::operator->()
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
inline const T* AutLib::autoPtr<T>::operator->() const
{
	return const_cast<autoPtr<T>&>(*this).operator->();
}


template<class T>
inline void AutLib::autoPtr<T>::operator=(const autoPtr<T>& ap)
{
	if (this != &ap)
	{
		reset(const_cast<autoPtr<T>&>(ap).ptr());
	}
}