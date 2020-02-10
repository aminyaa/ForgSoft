#pragma once
#ifndef _processorAMGInterfaceField_Header
#define _processorAMGInterfaceField_Header

#include <AMGInterfaceField.hxx>
#include <processorAMGInterface.hxx>
#include <processorLduInterfaceField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
					  Class processorAMGInterfaceField Declaration
	\*---------------------------------------------------------------------------*/

	class processorAMGInterfaceField
		:
		public AMGInterfaceField,
		public processorLduInterfaceField
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
		processorAMGInterfaceField(const processorAMGInterfaceField&);

		//- Disallow default bitwise assignment
		void operator=(const processorAMGInterfaceField&);


	public:

		//- Runtime type information
		TypeName("processor");


		// Constructors

			//- Construct from AMG interface and fine level interface field
		processorAMGInterfaceField
		(
			const AMGInterface& AMGCp,
			const lduInterfaceField& fineInterfaceField
		);


		//- Destructor
		virtual ~processorAMGInterfaceField();


		// Member Functions

			// Access

				//- Return size
		label size() const
		{
			return procInterface_.size();
		}


		// Coupled interface matrix update

			//- Transform neighbour field
		virtual void transformCoupleField
		(
			scalarField& pnf,
			const direction cmpt
		) const
		{
			processorLduInterfaceField::transformCoupleField(pnf, cmpt);
		}

		//- Initialise neighbour matrix update
		virtual void initInterfaceMatrixUpdate
		(
			const scalarField& psiInternal,
			scalarField& result,
			const lduMatrix& m,
			const scalarField& coeffs,
			const direction cmpt,
			const Pstream::commsTypes commsType,
			const bool switchToLhs
		) const;

		//- Update result field based on interface functionality
		virtual void updateInterfaceMatrix
		(
			const scalarField& psiInternal,
			scalarField& result,
			const lduMatrix&,
			const scalarField& coeffs,
			const direction cmpt,
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

#endif // !_processorAMGInterfaceField_Header
