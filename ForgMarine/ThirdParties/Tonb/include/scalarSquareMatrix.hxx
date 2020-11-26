#pragma once
#ifndef _scalarSquareMatrix_Header
#define _scalarSquareMatrix_Header

#include <SquareMatrix.hxx>
#include <scalarField.hxx>
#include <labelList.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							   Class scalarSquareMatrix Declaration
	\*---------------------------------------------------------------------------*/

	class scalarSquareMatrix
		: public SquareMatrix<scalar>
	{

	public:

		// Constructors

			//- Construct null
		scalarSquareMatrix();

		//- Construct given size
		scalarSquareMatrix(const label);

		//- Construct given size and coefficient value
		scalarSquareMatrix(const label, const scalar v);

		//- Construct as copy
		scalarSquareMatrix(const scalarSquareMatrix&);

		//- Construct from Istream
		scalarSquareMatrix(Istream&);


		// Member Functions

			//- Solve the matrix using Gaussian elimination with pivoting,
			//  returning the solution in the source.
			//  Matrix given as a reference is destroyed during solution
		template<class T>
		static void solve(scalarSquareMatrix& matrix, Field<T>& source);

		//- Solve the matrix using Gaussian elimination with pivoting
		//  and return the solution
		template<class Type>
		void solve(Field<Type>& psi, const Field<Type>& source) const;


		//- LU decompose the matrix with pivoting
		static void LUDecompose
		(
			scalarSquareMatrix& matrix,
			labelList& pivotIndices
		);

		//- LU back-substitution with given source, returning the solution
		//  in the source
		template<class Type>
		static void LUBacksubstitute
		(
			const scalarSquareMatrix& luMmatrix,
			const labelList& pivotIndices,
			Field<Type>& source
		);

		//- Invert the matrix using LU decomposition with pivoting
		scalarSquareMatrix LUinvert() const;

		//- Solve the matrix using LU decomposition with pivoting
		//  returning the LU form of the matrix and the solution in the source
		template<class Type>
		static void LUsolve(scalarSquareMatrix& matrix, Field<Type>& source);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <scalarSquareMatrixTemplates.cxx>
#endif

#endif // !_scalarSquareMatrix_Header
