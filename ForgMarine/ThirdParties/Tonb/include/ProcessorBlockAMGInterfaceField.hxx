#pragma once
#ifndef _ProcessorBlockAMGInterfaceField_Header
#define _ProcessorBlockAMGInterfaceField_Header

#include <BlockAMGInterfaceField.hxx>
#include <processorAMGInterface.hxx>
#include <ProcessorBlockLduInterfaceField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
				  Class ProcessorBlockAMGInterfaceField Declaration
	\*---------------------------------------------------------------------------*/

	template <class Type>
	class ProcessorBlockAMGInterfaceField
		:
		public BlockAMGInterfaceField<Type>,
		public ProcessorBlockLduInterfaceField<Type>
	{
		// Private data

			//- Local reference cast into the processor interface
		const processorAMGInterface& procInterface_;

		//- Is the transform required
		bool doTransform_;

		//- Rank of component for transformation
		int rank_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		ProcessorBlockAMGInterfaceField
		(
			const ProcessorBlockAMGInterfaceField&
		);

		//- Disallow default bitwise assignment
		void operator=(const ProcessorBlockAMGInterfaceField&);


	public:

		//- Runtime type information
		TypeName("processor");


		// Constructors

			//- Construct from AMG interface and fine level interface field
		ProcessorBlockAMGInterfaceField
		(
			const AMGInterface& AMGCp,
			const BlockLduInterfaceField<Type>& fineInterfaceField
		);


		//- Destructor
		virtual ~ProcessorBlockAMGInterfaceField();


		// Member Functions

			// Access

				//- Return size
		label size() const
		{
			return procInterface_.size();
		}


		// Block coupled interface matrix update

			//- Transform given patch component field
		virtual void transformCoupleField
		(
			scalarField& f,
			const direction cmpt
		) const
		{
			ProcessorBlockLduInterfaceField<Type>::transformCoupleField
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
			ProcessorBlockLduInterfaceField<Type>::transformCoupleField(f);
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


		//- Processor interface functions

			//- Return processor number
		virtual int myProcNo() const
		{
			return procInterface_.myProcNo();
		}

		//- Return neigbour processor number
		virtual int neighbProcNo() const
		{
			return procInterface_.neighbProcNo();
		}

		//- Does the interface field perform the transfromation
		virtual bool doTransform() const
		{
			return doTransform_;
		}

		//- Return face transformation tensor
		virtual const tensorField& forwardT() const
		{
			return procInterface_.forwardT();
		}

		//- Return rank of component for transform
		virtual int rank() const
		{
			return rank_;
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <ProcessorBlockAMGInterfaceField.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_ProcessorBlockAMGInterfaceField_Header
