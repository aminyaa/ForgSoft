#pragma once
// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class Type>
tnbLib::SquareMatrix<Type>::SquareMatrix()
	: Matrix<SquareMatrix<Type>, Type>()
{}


template<class Type>
tnbLib::SquareMatrix<Type>::SquareMatrix(const label n)
	: Matrix<SquareMatrix<Type>, Type>(n, n)
{}


template<class Type>
tnbLib::SquareMatrix<Type>::SquareMatrix
(
	const label n,
	const Type& t
)
	: Matrix<SquareMatrix<Type>, Type>(n, n, t)
{}


template<class Type>
tnbLib::SquareMatrix<Type>::SquareMatrix(Istream& is)
	: Matrix<SquareMatrix<Type>, Type>(is)
{}


template<class Type>
tnbLib::autoPtr<tnbLib::SquareMatrix<Type> >
tnbLib::SquareMatrix<Type>::clone() const
{
	return autoPtr<SquareMatrix<Type> >(new SquareMatrix<Type>(*this));
}


// ************************************************************************* //