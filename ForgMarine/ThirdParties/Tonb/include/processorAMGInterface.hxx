#pragma once
#ifndef _processorAMGInterface_Header
#define _processorAMGInterface_Header

#include <AMGInterface.hxx>
#include <processorLduInterface.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
					  Class processorAMGInterface Declaration
	\*---------------------------------------------------------------------------*/

	class processorAMGInterface
		:
		public AMGInterface,
		public processorLduInterface
	{
		// Private data

			//- Reference tor the processorLduInterface from which this is
			//  agglomerated
		const processorLduInterface& fineProcInterface_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		processorAMGInterface(const processorAMGInterface&);

		//- Disallow default bitwise assignment
		void operator=(const processorAMGInterface&);


	public:

		//- Runtime type information
		TypeName("processor");

		// Constructors

			//- Construct from fine-level interface,
			//  local and neighbour restrict addressing
		processorAMGInterface
		(
			const lduPrimitiveMesh& lduMesh,
			const lduInterface& fineInterface,
			const labelField& localRestrictAddressing,
			const labelField& neighbourRestrictAddressing
		);


		// Destructor

		virtual ~processorAMGInterface();


		// Member Functions

			// Access

				//- Return true if interface is coupled
		virtual bool coupled() const
		{
			return true;
		}


		// Interface transfer functions

			//- Initialise interface data transfer
		virtual void initTransfer
		(
			const Pstream::commsTypes commsType,
			const unallocLabelList& interfaceData
		) const;

		//- Transfer and return neighbour field
		virtual tmp<labelField> transfer
		(
			const Pstream::commsTypes commsType,
			const unallocLabelList& interfaceData
		) const;

		//- Initialise neighbour field transfer
		virtual void initInternalFieldTransfer
		(
			const Pstream::commsTypes commsType,
			const unallocLabelList& iF
		) const;

		//- Transfer and return internal field adjacent to the interface
		virtual tmp<labelField> internalFieldTransfer
		(
			const Pstream::commsTypes commsType,
			const unallocLabelList& iF
		) const;


		//- Processor interface functions

			//- Return processor number
		virtual int myProcNo() const
		{
			return fineProcInterface_.myProcNo();
		}

		//- Return neigbour processor number
		virtual int neighbProcNo() const
		{
			return fineProcInterface_.neighbProcNo();
		}

		//- Return face transformation tensor
		virtual const tensorField& forwardT() const
		{
			return fineProcInterface_.forwardT();
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_processorAMGInterface_Header
