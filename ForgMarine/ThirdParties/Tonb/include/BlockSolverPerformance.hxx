#pragma once
#ifndef _BlockSolverPerformance_Header
#define _BlockSolverPerformance_Header

#include <error.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * Forward declaration of template friend fuctions * * * * * * * //

	template<class Type>
	class BlockSolverPerformance;

	template<class Type>
	Istream& operator>>(Istream&, BlockSolverPerformance<Type>&);

	template<class Type>
	Ostream& operator<<(Ostream&, const BlockSolverPerformance<Type>&);


	/*---------------------------------------------------------------------------*\
					   Class BlockSolverPerformance Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class BlockSolverPerformance
	{
		// Private data

			//- Solver name
		word solverName_;

		//- Field name
		word fieldName_;

		//- Initial residual
		Type initialResidual_;

		//- Final residual
		Type finalResidual_;

		//- Number of iterations
		label nIterations_;

		//- Has the solver converged?
		bool converged_;

		//- Is the matrix singular?
		bool singular_;


	public:

		// Constructors

			//- Construct without solver and field name
		BlockSolverPerformance()
			:
			initialResidual_(pTraits<Type>::zero),
			finalResidual_(pTraits<Type>::zero),
			nIterations_(0),
			converged_(false),
			singular_(false)
		{}

		//- Construct with solver and field name
		BlockSolverPerformance
		(
			const word& solverName,
			const word& fieldName,
			const Type& iRes = pTraits<Type>::zero,
			const Type& fRes = pTraits<Type>::zero,
			const label nIter = 0,
			const bool converged = false,
			const bool singular = false
		)
			:
			solverName_(solverName),
			fieldName_(fieldName),
			initialResidual_(iRes),
			finalResidual_(fRes),
			nIterations_(nIter),
			converged_(converged),
			singular_(singular)
		{}


		// Member functions

			//- Return solver name
		const word& solverName() const
		{
			return solverName_;
		}

		//- Return solver name
		word& solverName()
		{
			return solverName_;
		}

		//- Return field name
		const word& fieldName() const
		{
			return fieldName_;
		}

		//- Return initial residual
		const Type& initialResidual() const
		{
			return initialResidual_;
		}

		//- Return initial residual
		Type& initialResidual()
		{
			return initialResidual_;
		}

		//- Return final residual
		const Type& finalResidual() const
		{
			return finalResidual_;
		}

		//- Return final residual
		Type& finalResidual()
		{
			return finalResidual_;
		}

		//- Return number of iterations
		label nIterations() const
		{
			return nIterations_;
		}

		//- Return number of iterations
		label& nIterations()
		{
			return nIterations_;
		}

		//- Has the solver converged?
		bool converged() const
		{
			return converged_;
		}

		//- Has the solver converged?
		bool& converged()
		{
			return converged_;
		}

		//- Is the matrix singular?
		bool singular() const
		{
			return singular_;
		}

		//- Is the matrix singular?
		bool& singular()
		{
			return singular_;
		}

		//- Convergence test
		bool checkConvergence
		(
			const scalar tolerance,
			const scalar relTolerance
		);

		//- Singularity test
		bool checkSingularity(const scalar& residual);

		//- Print summary of solver performance
		void print() const;


		// Member Operators

		bool operator!=(const BlockSolverPerformance<Type>&) const;


		// Friend functions

		friend Istream& operator>> <Type>
			(
				Istream&,
				BlockSolverPerformance<Type>&
				);

		friend Ostream& operator<< <Type>
			(
				Ostream&,
				const BlockSolverPerformance<Type>&
				);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <BlockSolverPerformance.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_BlockSolverPerformance_Header
