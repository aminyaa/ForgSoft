#pragma once
template<class T>
const AutLib::Xfer<T> AutLib::Xfer<T>::zero;

template<class T>
inline const AutLib::Xfer<T>& AutLib::Xfer<T>::null()
{
	return zero;
}

template<class T>
inline AutLib::Xfer<T>::Xfer(T* p)
	: ptr_(p ? p : new T)
{}


template<class T>
inline AutLib::Xfer<T>::Xfer(T& t, bool allowTransfer)
	: ptr_(new T)
{
	if (allowTransfer)
	{
		ptr_->transfer(t);
	}
	else
	{
		ptr_->operator=(t);
	}
}


template<class T>
inline AutLib::Xfer<T>::Xfer(const T& t)
	: ptr_(new T)
{
	ptr_->operator=(t);
}


template<class T>
inline AutLib::Xfer<T>::Xfer(const Xfer<T>& t)
	: ptr_(new T)
{
	ptr_->transfer(*(t.ptr_));
}

template<class T>
inline AutLib::Xfer<T>::~Xfer()
{
	delete ptr_;
	ptr_ = 0;
}

template<class T>
inline void AutLib::Xfer<T>::operator=(T& t)
{
	ptr_->transfer(t);
}


template<class T>
inline void AutLib::Xfer<T>::operator=(const Xfer<T>& t)
{
	// silently ignore attempted copy to self
	if (this != &t)
	{
		ptr_->transfer(*(t.ptr_));
	}
}


template<class T>
inline T& AutLib::Xfer<T>::operator()() const
{
	return *ptr_;
}


template<class T>
inline T* AutLib::Xfer<T>::operator->() const
{
	return ptr_;
}

template<class T>
inline AutLib::Xfer<T> AutLib::xferCopy(const T& t)
{
	return AutLib::Xfer<T>(t);
}


template<class T>
inline AutLib::Xfer<T> AutLib::xferMove(T& t)
{
	return AutLib::Xfer<T>(t, true);
}


template<class T>
inline AutLib::Xfer<T> AutLib::xferTmp(AutLib::tmp<T>& tt)
{
	return AutLib::Xfer<T>(tt(), tt.isTmp());
}


template<class To, class From>
inline AutLib::Xfer<To> AutLib::xferCopyTo(const From& t)
{
	AutLib::Xfer<To> xf;
	xf() = t;
	return xf;
}


template<class To, class From>
inline AutLib::Xfer<To> AutLib::xferMoveTo(From& t)
{
	AutLib::Xfer<To> xf;
	xf().transfer(t);
	return xf;
}