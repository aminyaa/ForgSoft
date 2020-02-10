#pragma once
#ifndef _SquareMatrix_Header
#define _SquareMatrix_Header

#include <Matrix.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							   Class Matrix Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class SquareMatrix
		: public Matrix<SquareMatrix<Type>, Type>
	{

	public:

		// Constructors

			//- Null constructor.
		SquareMatrix();

		//- Construct given number of rows/columns.
		SquareMatrix(const label n);

		//- Construct with given number of rows and rows
		//  and value for all elements.
		SquareMatrix(const label n, const Type&);

		//- Construct from Istream.
		SquareMatrix(Istream&);

		//- Clone
		autoPtr<SquareMatrix<Type>> clone() const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <SquareMatrixI.hxx>

#endif // !_SquareMatrix_Header
