#pragma once
#ifndef _BlockCGSolver_Header
#define _BlockCGSolver_Header

#include <blockLduSolvers.hxx>
#include <BlockIterativeSolver.hxx>
#include <blockLduPrecons.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							   Class BlockCGSolver Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class BlockCGSolver
		:
		public BlockIterativeSolver<Type>
	{
		// Private data

			//- Preconditioner
		autoPtr<BlockLduPrecon<Type> > preconPtr_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		BlockCGSolver(const BlockCGSolver<Type>&);

		//- Disallow default bitwise assignment
		void operator=(const BlockCGSolver<Type>&);


	public:

		//- Runtime type information
		TypeName("CG");


		// Constructors

			//- Construct from matrix components and solver data stream
		BlockCGSolver
		(
			const word& fieldName,
			const BlockLduMatrix<Type>& matrix,
			const dictionary& dict
		);


		// Destructor

		virtual ~BlockCGSolver()
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
#   include <BlockCGSolver.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_BlockCGSolver_Header
