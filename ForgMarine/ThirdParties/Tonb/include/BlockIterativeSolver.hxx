#pragma once
#ifndef _BlockIterativeSolver_Header
#define _BlockIterativeSolver_Header

#include <BlockLduSolver.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						Class BlockIterativeSolver Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class BlockIterativeSolver
		:
		public BlockLduSolver<Type>
	{
		// Private data

			//- Solver tolerance
		scalar tolerance_;

		//- Relative tolerance
		scalar relTolerance_;

		//- Minimum number of iterations
		//  (forced irrespective of convergence)
		label minIter_;

		//- Maximum number of iterations
		label maxIter_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		BlockIterativeSolver(const BlockIterativeSolver&);

		//- Disallow default bitwise assignment
		void operator=(const BlockIterativeSolver&);


	protected:

		// Protected Member Functions

			//- Return normalisation factor
		scalar normFactor
		(
			Field<Type>& x,
			const Field<Type>& b
		) const;

		//- Is the stop criterion reached
		bool stop(BlockSolverPerformance<Type>& solverPerf) const;


	public:

		// Constructors

			//- Construct from matrix components and solver data stream
		BlockIterativeSolver
		(
			const word& fieldName,
			const BlockLduMatrix<Type>& matrix,
			const dictionary& dict
		);


		// Destructor

		virtual ~BlockIterativeSolver()
		{}


		// Member Functions

			// Access

				//- Return tolerance
		scalar tolerance() const
		{
			return tolerance_;
		}

		//- Return relative tolerance
		scalar relTolerance() const
		{
			return relTolerance_;
		}

		//- Return minimum number of iterations
		label minIter() const
		{
			return minIter_;
		}

		//- Return maximum number of iterations
		label maxIter() const
		{
			return maxIter_;
		}


		// Solve

			//- Solve the matrix with this solver
		virtual BlockSolverPerformance<Type> solve
		(
			Field<Type>& x,
			const Field<Type>& b
		) = 0;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

#ifdef NoRepository
#   include <BlockIterativeSolver.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_BlockIterativeSolver_Header
