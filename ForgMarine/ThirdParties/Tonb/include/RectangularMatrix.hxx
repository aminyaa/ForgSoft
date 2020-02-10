#pragma once
#ifndef _RectangularMatrixHeader
#define _RectangularMatrix_Header

#include <Matrix.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							   Class Matrix Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class RectangularMatrix
		: public Matrix<RectangularMatrix<Type>, Type>
	{

	public:

		// Constructors

			//- Null constructor.
		RectangularMatrix();

		//- Construct given number of rows and columns,
		RectangularMatrix(const label m, const label n);

		//- Construct with given number of rows and columns
		//  and value for all elements.
		RectangularMatrix(const label m, const label n, const Type&);

		//- Construct from Istream.
		RectangularMatrix(Istream&);

		//- Clone
		autoPtr<RectangularMatrix<Type>> clone() const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <RectangularMatrixI.hxx>

#endif // !_RectangularMatrixHeader
