#pragma once
#ifndef _BlockAMGLevel_Header
#define _BlockAMGLevel_Header

#include <BlockLduMatrix.hxx>
#include <BlockMatrixCoarsening.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * Forward declaration of template friend fuctions * * * * * * * //

	template<class Type>
	class fineBlockAMGLevel;

	template<class Type>
	class coarseBlockAMGLevel;

	template<class Type>
	class BlockAMGCycle;

	template<class Type>
	class BlockMatrixCoarsening;

	template<class Type>
	class BlockAMGSolver;

	template<class Type>
	class BlockAMGPrecon;

	/*---------------------------------------------------------------------------*\
							   Class BlockAMGLevel Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class BlockAMGLevel
	{
	public:

		// Runtime type information
		TypeName("BlockAMGLevel");


		//- Destructor
		virtual ~BlockAMGLevel()
		{}


		// Member Functions

			//- Return reference to x
		virtual Field<Type>& x() = 0;

		//- Return reference to b
		virtual Field<Type>& b() = 0;

		//- Calculate residual
		virtual void residual
		(
			const Field<Type>& x,
			const Field<Type>& b,
			Field<Type>& res
		) const = 0;

		//- Restrict residual
		virtual void restrictResidual
		(
			const Field<Type>& x,
			const Field<Type>& b,
			Field<Type>& xBuffer,
			Field<Type>& coarseRes,
			bool preSweepsDone
		) const = 0;

		//- Prolongate correction
		virtual void prolongateCorrection
		(
			Field<Type>& x,
			const Field<Type>& coarseX
		) const = 0;

		//- Smooth level
		virtual void smooth
		(
			Field<Type>& x,
			const Field<Type>& b,
			const label nSweeps
		) const = 0;

		//- Solve level
		virtual void solve
		(
			Field<Type>& x,
			const Field<Type>& b,
			const scalar tolerance,
			const scalar relTol
		) const = 0;

		//- Scale x
		virtual void scaleX
		(
			Field<Type>& x,
			const Field<Type>& b,
			Field<Type>& xBuffer
		) const = 0;

		//- Create next level from current level
		virtual autoPtr<BlockAMGLevel> makeNextLevel() const = 0;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_BlockAMGLevel_Header
