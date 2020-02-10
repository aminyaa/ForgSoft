#pragma once
// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class Type>
tnbLib::RectangularMatrix<Type>::RectangularMatrix()
	: Matrix<RectangularMatrix<Type>, Type>()
{}

template<class Type>
tnbLib::RectangularMatrix<Type>::RectangularMatrix
(
	const label m,
	const label n
)
	: Matrix<RectangularMatrix<Type>, Type>(m, n)
{}

template<class Type>
tnbLib::RectangularMatrix<Type>::RectangularMatrix
(
	const label m,
	const label n,
	const Type& t
)
	: Matrix<RectangularMatrix<Type>, Type>(m, n, t)
{}

template<class Type>
tnbLib::RectangularMatrix<Type>::RectangularMatrix(Istream& is)
	: Matrix<RectangularMatrix<Type>, Type>(is)
{}

template<class Type>
tnbLib::autoPtr<tnbLib::RectangularMatrix<Type> >
tnbLib::RectangularMatrix<Type>::clone() const
{
	return autoPtr<RectangularMatrix<Type> >(new RectangularMatrix<Type>(*this));
}


// ************************************************************************* //