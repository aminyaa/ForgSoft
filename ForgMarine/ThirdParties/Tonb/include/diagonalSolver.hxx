#pragma once
#ifndef _diagonalSolver_Header
#define _diagonalSolver_Header

#include <lduMatrix.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							   Class diagonalSolver Declaration
	\*---------------------------------------------------------------------------*/

	class diagonalSolver
		:
		public lduMatrix::solver
	{
		// Private Member Functions

			//- Disallow default bitwise copy construct
		diagonalSolver(const diagonalSolver&);

		//- Disallow default bitwise assignment
		void operator=(const diagonalSolver&);


	public:

		//- Runtime type information
		TypeName("diagonal");


		// Constructors

			//- Construct from matrix and solver controls
		diagonalSolver
		(
			const word& fieldName,
			const lduMatrix& matrix,
			const FieldField<Field, scalar>& coupleBouCoeffs,
			const FieldField<Field, scalar>& coupleIntCoeffs,
			const lduInterfaceFieldPtrsList& interfaces,
			const dictionary& dict
		);


		// Member Functions

			//- Read and reset the solver parameters from the given stream
		void read(const dictionary&)
		{}

		//- Solve the matrix with this solver
		lduSolverPerformance solve
		(
			scalarField& x,
			const scalarField& b,
			const direction cmpt = 0
		) const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_diagonalSolver_Header
