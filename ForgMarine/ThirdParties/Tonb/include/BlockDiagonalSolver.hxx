#pragma once
#ifndef _BlockDiagonalSolver_Header
#define _BlockDiagonalSolver_Header

#include <Field.hxx>
#include <typeInfo.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	template<class Type>
	class BlockLduMatrix;

	template<class Type>
	class BlockLduSolver;

	template<class Type>
	class BlockSolverPerformance;

	/*---------------------------------------------------------------------------*\
						  Class BlockDiagonalSolver Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class BlockDiagonalSolver
		:
		public BlockLduSolver<Type>
	{
		// Private Member Functions

			//- Disallow default bitwise copy construct
		BlockDiagonalSolver(const BlockDiagonalSolver<Type>&);

		//- Disallow default bitwise assignment
		void operator=(const BlockDiagonalSolver<Type>&);


	public:

		//- Runtime type information
		TypeName("Diagonal");


		// Constructors

			//- Construct from matrix
		BlockDiagonalSolver
		(
			const word& fieldName,
			const BlockLduMatrix<Type>& matrix,
			const dictionary& dict
		);


		// Member Functions

			//- Solve the matrix with this solver
		virtual BlockSolverPerformance<Type> solve
		(
			Field<Type>& x,
			const Field<Type>& b
		);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <BlockDiagonalSolver.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_BlockDiagonalSolver_Header
