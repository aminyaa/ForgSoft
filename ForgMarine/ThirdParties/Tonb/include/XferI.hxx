#pragma once
// * * * * * * * * * * * * * * * Static Members  * * * * * * * * * * * * * * //

template<class T>
const tnbLib::Xfer<T> tnbLib::Xfer<T>::zero;


// * * * * * * * * * * * * Static Member Functions * * * * * * * * * * * * * //

template<class T>
const tnbLib::Xfer<T>& tnbLib::Xfer<T>::null()
{
	return zero;
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class T>
tnbLib::Xfer<T>::Xfer(T* p)
	: ptr_(p ? p : new T)
{}


template<class T>
tnbLib::Xfer<T>::Xfer(T& t, bool allowTransfer)
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
tnbLib::Xfer<T>::Xfer(const T& t)
	: ptr_(new T)
{
	ptr_->operator=(t);
}


template<class T>
tnbLib::Xfer<T>::Xfer(const Xfer<T>& t)
	: ptr_(new T)
{
	ptr_->transfer(*(t.ptr_));
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

template<class T>
tnbLib::Xfer<T>::~Xfer()
{
	delete ptr_;
	ptr_ = 0;
}


// * * * * * * * * * * * * *  Member Functions * * * * * * * * * * * * * * * //


// * * * * * * * * * * * * * * * Member Operators  * * * * * * * * * * * * * //

template<class T>
void tnbLib::Xfer<T>::operator=(T& t)
{
	ptr_->transfer(t);
}


template<class T>
void tnbLib::Xfer<T>::operator=(const Xfer<T>& t)
{
	// silently ignore attempted copy to self
	if (this != &t)
	{
		ptr_->transfer(*(t.ptr_));
	}
}


template<class T>
T& tnbLib::Xfer<T>::operator()() const
{
	return *ptr_;
}


template<class T>
T* tnbLib::Xfer<T>::operator->() const
{
	return ptr_;
}


// * * * * * * * * * * * * *  Helper Functions * * * * * * * * * * * * * * * //


template<class T>
tnbLib::Xfer<T> tnbLib::xferCopy(const T& t)
{
	return tnbLib::Xfer<T>(t);
}


template<class T>
tnbLib::Xfer<T> tnbLib::xferMove(T& t)
{
	return tnbLib::Xfer<T>(t, true);
}


template<class T>
tnbLib::Xfer<T> tnbLib::xferTmp(tnbLib::tmp<T>& tt)
{
	return tnbLib::Xfer<T>(tt(), tt.isTmp());
}


template<class To, class From>
tnbLib::Xfer<To> tnbLib::xferCopyTo(const From& t)
{
	tnbLib::Xfer<To> xf;
	xf() = t;
	return xf;
}


template<class To, class From>
tnbLib::Xfer<To> tnbLib::xferMoveTo(From& t)
{
	tnbLib::Xfer<To> xf;
	xf().transfer(t);
	return xf;
}


// ************************************************************************* //