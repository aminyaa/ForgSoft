#pragma once
#ifndef _BlockGMRESSolver_Header
#define _BlockGMRESSolver_Header

#include <blockLduSolvers.hxx>
#include <BlockIterativeSolver.hxx>
#include <blockLduPrecons.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						   Class BlockGMRESSolver Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class BlockGMRESSolver
		:
		public BlockIterativeSolver<Type>
	{
		// Private data

			//- Preconditioner
		autoPtr<BlockLduPrecon<Type> > preconPtr_;

		//- Krylov space dimension
		label nDirs_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		BlockGMRESSolver(const BlockGMRESSolver<Type>&);

		//- Disallow default bitwise assignment
		void operator=(const BlockGMRESSolver<Type>&);

		//- Givens rotation
		void givensRotation
		(
			const scalar& H,
			const scalar& beta,
			scalar& c,
			scalar& s
		) const;


	public:

		//- Runtime type information
		TypeName("GMRES");


		// Constructors

			//- Construct from matrix components and solver data stream
		BlockGMRESSolver
		(
			const word& fieldName,
			const BlockLduMatrix<Type>& matrix,
			const dictionary& dict
		);


		// Destructor

		virtual ~BlockGMRESSolver()
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
#   include <BlockGMRESSolver.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_BlockGMRESSolver_Header
