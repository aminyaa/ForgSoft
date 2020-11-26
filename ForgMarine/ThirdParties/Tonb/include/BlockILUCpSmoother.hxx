#pragma once
#ifndef _BlockILUCpSmoother_Header
#define _BlockILUCpSmoother_Header

#include <BlockLduSmoother.hxx>
#include <blockILUCpPrecons.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						   Class BlockILUCpSmoother Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class BlockILUCpSmoother
		:
		public BlockLduSmoother<Type>
	{
		// Private Data

			//- ILUCp preconditioner
		BlockILUCpPrecon<Type> precon_;

		//- Correction array
		mutable Field<Type> xCorr_;

		//- Residual array
		mutable Field<Type> residual_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		BlockILUCpSmoother(const BlockILUCpSmoother&);

		//- Disallow default bitwise assignment
		void operator=(const BlockILUCpSmoother&);


	public:

		//- Runtime type information
		TypeName("ILUCp");


		// Constructors

			//- Construct from components
		BlockILUCpSmoother
		(
			const BlockLduMatrix<Type>& matrix,
			const dictionary& dict
		)
			:
			BlockLduSmoother<Type>(matrix),
			precon_(matrix, dict),
			xCorr_(matrix.lduAddr().size()),
			residual_(matrix.lduAddr().size())
		{}


		//- Destructor
		virtual ~BlockILUCpSmoother()
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

#endif // !_BlockILUCpSmoother_Header
