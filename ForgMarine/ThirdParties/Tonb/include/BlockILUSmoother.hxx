#pragma once
#ifndef _BlockILUSmoother_Header
#define _BlockILUSmoother_Header

#include <BlockLduSmoother.hxx>
#include <blockCholeskyPrecons.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						   Class BlockILUSmoother Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class BlockILUSmoother
		:
		public BlockLduSmoother<Type>
	{
		// Private Data

			//- Cholesky preconditioner
		BlockCholeskyPrecon<Type> precon_;

		//- Correction array
		mutable Field<Type> xCorr_;

		//- Residual array
		mutable Field<Type> residual_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		BlockILUSmoother(const BlockILUSmoother&);

		//- Disallow default bitwise assignment
		void operator=(const BlockILUSmoother&);


	public:

		//- Runtime type information
		TypeName("ILU");


		// Constructors

			//- Construct from components
		BlockILUSmoother
		(
			const BlockLduMatrix<Type>& matrix,
			const dictionary& dict
		)
			:
			BlockLduSmoother<Type>(matrix),
			precon_(matrix),
			xCorr_(matrix.lduAddr().size()),
			residual_(matrix.lduAddr().size())
		{}


		// Destructor

		virtual ~BlockILUSmoother()
		{}


		// Member Functions

			//- Execute smoothing
		virtual void smooth
		(
			Field<Type>& x,
			const Field<Type>& b,
			const label nSweeps
		) const
		{
			for (label sweep = 0; sweep < nSweeps; sweep++)
			{
				// Calculate residual
				this->matrix_.Amul(residual_, x);

				// residual = b - Ax
				forAll(b, i)
				{
					residual_[i] = b[i] - residual_[i];
				}

				precon_.precondition(xCorr_, residual_);

				// Add correction to x
				x += xCorr_;
			}
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_BlockILUSmoother_Header
