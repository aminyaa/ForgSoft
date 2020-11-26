#pragma once
#ifndef _BlockBiCGStabSolver_Header
#define _BlockBiCGStabSolver_Header

#include <blockLduSolvers.hxx>
#include <BlockIterativeSolver.hxx>
#include <blockLduPrecons.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						 Class BlockBiCGStabSolver Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class BlockBiCGStabSolver
		:
		public BlockIterativeSolver<Type>
	{
		// Private data

			//- Preconditioner
		autoPtr<BlockLduPrecon<Type> > preconPtr_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		BlockBiCGStabSolver(const BlockBiCGStabSolver<Type>&);

		//- Disallow default bitwise assignment
		void operator=(const BlockBiCGStabSolver<Type>&);


	public:

		//- Runtime type information
		TypeName("BiCGStab");


		// Constructors

			//- Construct from matrix components and solver data stream
		BlockBiCGStabSolver
		(
			const word& fieldName,
			const BlockLduMatrix<Type>& matrix,
			const dictionary& dict
		);


		// Destructor

		virtual ~BlockBiCGStabSolver()
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
#   include <BlockBiCGStabSolver.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_BlockBiCGStabSolver_Header
