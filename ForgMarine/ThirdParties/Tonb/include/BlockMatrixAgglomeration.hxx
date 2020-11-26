#pragma once
#ifndef _BlockMatrixAgglomeration_Header
#define _BlockMatrixAgglomeration_Header

#include <BlockMatrixCoarsening.hxx>
#include <BlockLduMatrix.hxx>
#include <BlockCoeffNorm.hxx>
#include <tolerancesSwitch.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	/*---------------------------------------------------------------------------*\
					 Class BlockMatrixAgglomeration Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class BlockMatrixAgglomeration
		:
		public BlockMatrixCoarsening<Type>
	{
		// Private Data

			//- Reference to matrix
		const BlockLduMatrix<Type>& matrix_;

		//- Reference to a templated norm calculator
		autoPtr<BlockCoeffNorm<Type> > normPtr_;

		//- Child array: for each fine equation give agglomeration cluster
		//  index
		labelField agglomIndex_;

		//- Group size
		label groupSize_;

		//- Number of solo cells
		label nSolo_;

		//- Number of coarse equations
		label nCoarseEqns_;

		//- Can a coarse level be constructed?
		bool coarsen_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		BlockMatrixAgglomeration(const BlockMatrixAgglomeration<Type>&);

		// Disallow default bitwise assignment
		void operator=(const BlockMatrixAgglomeration<Type>&);


		//- Calculate agglomeration index (child)
		void calcAgglomeration();

		//- Restrict CoeffField.  Used for diag coefficient
		void restrictDiag
		(
			const CoeffField<Type>& Coeff,
			CoeffField<Type>& coarseCoeff
		) const;

		//- Agglomerate coeffs, symmetric matrix
		template<class DiagType, class ULType>
		void agglomerateCoeffs
		(
			const labelList& coeffRestrictAddr,
			Field<DiagType>& activeCoarseDiag,
			Field<ULType>& activeCoarseUpper,
			const Field<ULType>& activeFineUpper,
			const Field<ULType>& activeFineUpperTranspose
		) const;

		//- Agglomerate coeffs, assymmetric matrix
		template<class DiagType, class ULType>
		void agglomerateCoeffs
		(
			const labelList& coeffRestrictAddr,
			Field<DiagType>& activeCoarseDiag,
			Field<ULType>& activeCoarseUpper,
			const Field<ULType>& activeFineUpper,
			Field<ULType>& activeCoarseLower,
			const Field<ULType>& activeFineLower
		) const;

		//- Restrict CoeffField, decoupled version.  Used for diag coefficient
		void restrictDiagDecoupled
		(
			const CoeffField<Type>& Coeff,
			CoeffField<Type>& coarseCoeff
		) const;

		// Private Static Data

			//- Weighting factor
		static const debug::tolerancesSwitch weightFactor_;

		//- Diagonal scaling factor
		static const debug::tolerancesSwitch diagFactor_;


	public:

		//- Runtime type information
		TypeName("AAMG");


		// Constructors

			//- Construct from matrix and group size
		BlockMatrixAgglomeration
		(
			const BlockLduMatrix<Type>& matrix,
			const dictionary& dict,
			const label groupSize,
			const label minCoarseEqns
		);


		// Destructor

		virtual ~BlockMatrixAgglomeration();


		// Member Functions

			//- Can a coarse level be constructed?
		virtual bool coarsen() const
		{
			return coarsen_;
		}

		//- Restrict matrix
		virtual autoPtr<BlockAMGLevel<Type> > restrictMatrix() const;

		//- Restrict residual
		virtual void restrictResidual
		(
			const Field<Type>& res,
			Field<Type>& coarseRes
		) const;

		//- Prolongate correction
		virtual void prolongateCorrection
		(
			Field<Type>& x,
			const Field<Type>& coarseX
		) const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <BlockMatrixAgglomeration.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_BlockMatrixAgglomeration_Header
