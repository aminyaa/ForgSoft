#pragma once
#ifndef _BlockGaussSeidelSolver_Header
#define _BlockGaussSeidelSolver_Header

#include <blockLduSolvers.hxx>
#include <BlockIterativeSolver.hxx>
#include <BlockSolverPerformance.hxx>
#include <blockGaussSeidelPrecons.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
					   Class BlockGaussSeidelSolver Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class BlockGaussSeidelSolver
		:
		public BlockIterativeSolver<Type>
	{
		// Private data

			//- Gauss-Seidel preconditioner
		BlockGaussSeidelPrecon<Type> gs_;

		//- Number of sweeps before evaluating residual
		label nSweeps_;



		// Private Member Functions

			//- Disallow default bitwise copy construct
		BlockGaussSeidelSolver(const BlockGaussSeidelSolver<Type>&);

		//- Disallow default bitwise assignment
		void operator=(const BlockGaussSeidelSolver<Type>&);


	public:

		//- Runtime type information
		TypeName("GaussSeidel");


		// Constructors

			//- Construct from matrix components and solver data stream
		BlockGaussSeidelSolver
		(
			const word& fieldName,
			const BlockLduMatrix<Type>& matrix,
			const dictionary& dict
		);


		// Destructor

		virtual ~BlockGaussSeidelSolver()
		{}


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
#   include <BlockGaussSeidelSolver.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_BlockGaussSeidelSolver_Header
