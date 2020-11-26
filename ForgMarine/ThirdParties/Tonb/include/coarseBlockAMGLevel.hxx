#pragma once
#ifndef _coarseBlockAMGLevel_Header
#define _coarseBlockAMGLevel_Header

#include <BlockAMGLevel.hxx>
#include <BlockLduSmoother.hxx>
#include <BlockLduMatrix.hxx>
#include <lduPrimitiveMesh.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							Class coarseBlockAMGLevel Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class coarseBlockAMGLevel
		: public BlockAMGLevel<Type>
	{
		// Private data

			//- Matrix addressing object.  This also contains coupling interfaces
		autoPtr<lduPrimitiveMesh> addrPtr_;

		//- Matrix
		autoPtr<BlockLduMatrix<Type> > matrixPtr_;

		//- Solution field
		Field<Type> x_;

		//- RHS field
		Field<Type> b_;

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
		coarseBlockAMGLevel(const coarseBlockAMGLevel<Type>&);

		//- Disallow default bitwise assignment
		void operator=(const coarseBlockAMGLevel<Type>&);


	public:

		//- Runtime type information
		TypeName("coarseBlockAMGLevel");


		// Constructors

			//- Construct from components
		coarseBlockAMGLevel
		(
			autoPtr<lduPrimitiveMesh> addrPtr,
			autoPtr<BlockLduMatrix<Type> > matrixPtr,
			const dictionary& dict,
			const word& coarseningType,
			const label groupSize,
			const label minCoarseEqns
		);


		//- Destructor
		virtual ~coarseBlockAMGLevel();


		// Member Functions

			//- Return reference to x
		virtual Field<Type>& x();

		//- Return reference to b
		virtual Field<Type>& b();

		//- Return reference to dictionary
		const dictionary& dict() const
		{
			return dict_;
		}

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
#   include <coarseBlockAMGLevel.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_coarseBlockAMGLevel_Header
