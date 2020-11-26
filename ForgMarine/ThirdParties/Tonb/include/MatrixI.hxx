#pragma once
// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class Form, class Type>
inline tnbLib::Matrix<Form, Type>::Matrix()
	:
	v_(NULL),
	n_(0),
	m_(0)
{}


template<class Form, class Type>
inline tnbLib::autoPtr<tnbLib::Matrix<Form, Type> >
tnbLib::Matrix<Form, Type>::clone() const
{
	return autoPtr<Matrix<Form, Type> >(new Matrix<Form, Type>(*this));
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class Form, class Type>
inline const tnbLib::Matrix<Form, Type>& tnbLib::Matrix<Form, Type>::null()
{
	return zero;
}


//- Return the number of rows
template<class Form, class Type>
inline tnbLib::label tnbLib::Matrix<Form, Type>::n() const
{
	return n_;
}


template<class Form, class Type>
inline tnbLib::label tnbLib::Matrix<Form, Type>::m() const
{
	return m_;
}


template<class Form, class Type>
inline tnbLib::label tnbLib::Matrix<Form, Type>::size() const
{
	return n_ * m_;
}


template<class Form, class Type>
inline void tnbLib::Matrix<Form, Type>::checki(const label i) const
{
	if (!n_)
	{
		FatalErrorIn("Matrix<Form, Type>::checki(const label)")
			<< "attempt to access element from zero sized row"
			<< abort(FatalError);
	}
	else if (i < 0 || i >= n_)
	{
		FatalErrorIn("Matrix<Form, Type>::checki(const label)")
			<< "index " << i << " out of range 0 ... " << n_ - 1
			<< abort(FatalError);
	}
}


template<class Form, class Type>
inline void tnbLib::Matrix<Form, Type>::checkj(const label j) const
{
	if (!m_)
	{
		FatalErrorIn("Matrix<Form, Type>::checkj(const label)")
			<< "attempt to access element from zero sized column"
			<< abort(FatalError);
	}
	else if (j < 0 || j >= m_)
	{
		FatalErrorIn("Matrix<Form, Type>::checkj(const label)")
			<< "index " << j << " out of range 0 ... " << m_ - 1
			<< abort(FatalError);
	}
}


// * * * * * * * * * * * * * * * Member Operators  * * * * * * * * * * * * * //

template<class Form, class Type>
inline Type* tnbLib::Matrix<Form, Type>::operator[](const label i)
{
#   ifdef FULLDEBUG
	checki(i);
#   endif
	return v_[i];
}


template<class Form, class Type>
inline const Type* tnbLib::Matrix<Form, Type>::operator[](const label i) const
{
#   ifdef FULLDEBUG
	checki(i);
#   endif
	return v_[i];
}


// ************************************************************************* //