#pragma once
#ifndef _fineBlockAMGLevel_Header
#define _fineBlockAMGLevel_Header

#include <BlockAMGLevel.hxx>
#include <BlockLduSmoother.hxx>
#include <BlockLduMatrix.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	template<class Type>
	class coarseBlockAMGLevel;

	template<class Type>
	class BlockMatrixCoarsening;

	/*---------------------------------------------------------------------------*\
							Class fineBlockAMGLevel Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class fineBlockAMGLevel
		:
		public BlockAMGLevel<Type>
	{
		// Private data

			 //- Reference to matrix
		const BlockLduMatrix<Type>& matrix_;

		//- Dictionary
		const dictionary& dict_;

		//- AMG coarsening
		autoPtr<BlockMatrixCoarsening<Type> > coarseningPtr_;

		//- Smoother
		autoPtr<BlockLduSmoother<Type> > smootherPtr_;

		//- Ax buffer
		mutable Field<Type> Ax_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		fineBlockAMGLevel(const fineBlockAMGLevel<Type>&);

		//- Disallow default bitwise assignment
		void operator=(const fineBlockAMGLevel<Type>&);


	public:

		//- Runtime type information
		TypeName("fineBlockAMGLevel");


		// Constructors

			//- Construct from components
		fineBlockAMGLevel
		(
			const BlockLduMatrix<Type>& matrix,
			const dictionary& dict,
			const word& coarseningType,
			const label groupSize,
			const label minCoarseEqns
		);


		//- Destructor
		virtual ~fineBlockAMGLevel()
		{}


		// Member Functions

			//- Return reference to dictionary
		const dictionary& dict() const
		{
			return dict_;
		}

		//- Return reference to x
		virtual Field<Type>& x();

		//- Return reference to b
		virtual Field<Type>& b();

		//- Calculate residual
		virtual void residual
		(
			const Field<Type>& x,
			const Field<Type>& b,
			Field<Type>& res
		) const;

		//- Restrict residual
		virtual void restrictResidual
		(
			const Field<Type>& x,
			const Field<Type>& b,
			Field<Type>& xBuffer,
			Field<Type>& coarseRes,
			bool preSweepsDone
		) const;

		//- Prolongate correction
		virtual void prolongateCorrection
		(
			Field<Type>& x,
			const Field<Type>& coarseX
		) const;

		//- Smooth level
		virtual void smooth
		(
			Field<Type>& x,
			const Field<Type>& b,
			const label nSweeps
		) const;

		//- Solve level
		virtual void solve
		(
			Field<Type>& x,
			const Field<Type>& b,
			const scalar tolerance,
			const scalar relTol
		) const;

		//- Scale x
		virtual void scaleX
		(
			Field<Type>& x,
			const Field<Type>& b,
			Field<Type>& xBuffer
		) const;

		//- Create next level from current level
		virtual autoPtr<BlockAMGLevel<Type> > makeNextLevel() const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <fineBlockAMGLevel.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_fineBlockAMGLevel_Header
