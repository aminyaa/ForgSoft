#pragma once
#ifndef _GGIBlockAMGInterfaceField_Header
#define _GGIBlockAMGInterfaceField_Header

#include <BlockAMGInterfaceField.hxx>
#include <ggiAMGInterface.hxx>
#include <GGIBlockLduInterfaceField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
					   Class GGIBlockAMGInterfaceField Declaration
	\*---------------------------------------------------------------------------*/

	template <class Type>
	class GGIBlockAMGInterfaceField
		:
		public BlockAMGInterfaceField<Type>,
		public GGIBlockLduInterfaceField<Type>
	{
		// Private data

			//- Local reference cast into the ggi interface
		const ggiAMGInterface& ggiInterface_;

		//- Is the transform required
		bool doTransform_;

		//- Rank of component for transformation.
		int rank_;

		//- Field transfer buffer
		mutable Field<Type> fieldTransferBuffer_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		GGIBlockAMGInterfaceField(const GGIBlockAMGInterfaceField&);

		//- Disallow default bitwise assignment
		void operator=(const GGIBlockAMGInterfaceField&);


		//- Agglomerate type
		template<class Type2>
		void agglomerateBlockType
		(
			Field<Type2>& coarseCoeffs,
			const tnbLib::Field<Type2>& fineCoeffs
		) const;


	public:

		//- Runtime type information
		TypeName("ggi");


		// Constructors

			//- Construct from AMG interface and fine level interface field
		GGIBlockAMGInterfaceField
		(
			const AMGInterface& AMGCp,
			const BlockLduInterfaceField<Type>& fineInterfaceField
		);


		//- Destructor
		virtual ~GGIBlockAMGInterfaceField();


		// Member Functions

			// Access

				//- Return size
		label size() const
		{
			return ggiInterface_.size();
		}


		// Agglomeration

			// Klas Jareteg: 2013-02-06. Moved by HJ, 16/Mar/2016
			//- Agglomerating for the CoeffField fine-level coefficients
		virtual tmp<CoeffField<Type> > agglomerateBlockCoeffs
		(
			const CoeffField<Type>& fineCoeffs
		) const;


		// Block coupled interface matrix update

			//- Transform given patch component field
		virtual void transformCoupleField
		(
			scalarField& f,
			const direction cmpt
		) const
		{
			GGIBlockLduInterfaceField<Type>::transformCoupleField
			(
				f,
				cmpt
			);
		}

		//- Transform neighbour field
		virtual void transformCoupleField
		(
			Field<Type>& f
		) const
		{
			GGIBlockLduInterfaceField<Type>::transformCoupleField(f);
		}

		//- Initialise neighbour matrix update
		virtual void initInterfaceMatrixUpdate
		(
			const Field<Type>&,
			Field<Type>&,
			const BlockLduMatrix<Type>&,
			const CoeffField<Type>&,
			const Pstream::commsTypes commsType,
			const bool switchToLhs
		) const;

		//- Update result field based on interface functionality
		virtual void updateInterfaceMatrix
		(
			const Field<Type>&,
			Field<Type>&,
			const BlockLduMatrix<Type>&,
			const CoeffField<Type>&,
			const Pstream::commsTypes commsType,
			const bool switchToLhs
		) const;


		//- Ggi interface functions

			//- Does the interface field perform the transfromation
		virtual bool doTransform() const
		{
			return doTransform_;
		}

		//- Return face transformation tensor
		virtual const tensorField& forwardT() const
		{
			return ggiInterface_.forwardT();
		}

		//- Return neighbour-cell transformation tensor
		virtual const tensorField& reverseT() const
		{
			return ggiInterface_.reverseT();
		}

		//- Return rank of component for transform
		virtual int rank() const
		{
			return rank_;
		}

		// Transfer buffer access

			//- Return contents of the field transfer buffer
		const Field<Type>& fieldTransferBuffer() const
		{
			return fieldTransferBuffer_;
		}

	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <GGIBlockAMGInterfaceField.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_GGIBlockAMGInterfaceField_Header
