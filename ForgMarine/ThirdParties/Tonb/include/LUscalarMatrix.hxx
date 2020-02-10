#pragma once
#ifndef _LUscalarMatrix_Header
#define _LUscalarMatrix_Header

#include <scalarMatrices.hxx>
#include <labelList.hxx>
#include <FieldField.hxx>
#include <lduInterfaceFieldPtrsList.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	class lduMatrix;
	class procLduMatrix;

	/*---------------------------------------------------------------------------*\
							   Class LUscalarMatrix Declaration
	\*---------------------------------------------------------------------------*/

	class LUscalarMatrix
		:
		public scalarSquareMatrix
	{
		// Private data

			//- Processor matrix offsets
		labelList procOffsets_;

		//- The pivot indices used in the LU decomposition
		labelList pivotIndices_;

		//- Convert the given lduMatrix into this LUscalarMatrix
		void convert
		(
			const lduMatrix& ldum,
			const FieldField<Field, scalar>& interfaceCoeffs,
			const lduInterfaceFieldPtrsList& interfaces
		);

		//- Convert the given list of procLduMatrix into this LUscalarMatrix
		//  on the master processor
		void convert(const PtrList<procLduMatrix>& lduMatrices);


		//- Print the ratio of the mag-sum of the off-diagonal coefficients
		//  to the mag-diagonal
		void printDiagonalDominance() const;


	public:

		// Constructors

			//- Construct from scalarSquareMatrix and perform LU decomposition
		LUscalarMatrix(const scalarSquareMatrix&);

		//- Construct from lduMatrix and perform LU decomposition
		LUscalarMatrix
		(
			const lduMatrix&,
			const FieldField<Field, scalar>& interfaceCoeffs,
			const lduInterfaceFieldPtrsList& interfaces
		);


		// Member Functions

			//- Solve the matrix using the LU decomposition with pivoting
			//  returning the solution in the source
		template<class T>
		void solve(Field<T>& source) const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <LUscalarMatrixTemplates.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_LUscalarMatrix_Header
