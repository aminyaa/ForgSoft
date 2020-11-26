#pragma once
#ifndef _BlockAMGSolver_Header
#define _BlockAMGSolver_Header

#include <BlockAMGPrecon.hxx>
#include <blockLduSolvers.hxx>
#include <blockLduPrecons.hxx>
#include <BlockIterativeSolver.hxx>
#include <BlockSolverPerformance.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							   Class BlockAMGSolver Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class BlockAMGSolver
		:
		public BlockIterativeSolver<Type>
	{
	private:

		// Private data

			//- AMG preconditioner
		BlockAMGPrecon<Type> amg_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		BlockAMGSolver(const BlockAMGSolver<Type>&);

		//- Disallow default bitwise assignment
		void operator=(const BlockAMGSolver<Type>&);


	public:

		//- Runtime type information
		TypeName("AMG");


		// Constructors

			//- Construct from matrix components and solver data stream
		BlockAMGSolver
		(
			const word& fieldName,
			const BlockLduMatrix<Type>& matrix,
			const dictionary& dict
		);


		// Destructor

		virtual ~BlockAMGSolver()
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
#   include <BlockAMGSolver.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_BlockAMGSolver_Header
