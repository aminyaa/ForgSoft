#pragma once
#ifndef _mixingPlaneAMGInterface_Header
#define _mixingPlaneAMGInterface_Header

#include <AMGInterface.hxx>
#include <mixingPlaneLduInterface.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						 Class mixingPlaneAMGInterface Declaration
	\*---------------------------------------------------------------------------*/

	class mixingPlaneAMGInterface
		:
		public AMGInterface,
		virtual public mixingPlaneLduInterface
	{
		// Private data

			//- Reference tor the mixingPlaneLduInterface from which this is
			//  agglomerated
		const mixingPlaneLduInterface& fineMixingPlaneInterface_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		mixingPlaneAMGInterface(const mixingPlaneAMGInterface&);

		//- Disallow default bitwise assignment
		void operator=(const mixingPlaneAMGInterface&);


		// Private static data

			//- Processor cluster offset index
		static const label procOffset = 1000000;


	public:

		//- Runtime type information
		TypeName("mixingPlane");


		// Constructors

			//- Construct from fine level interface,
			//  local and neighbour restrict addressing
		mixingPlaneAMGInterface
		(
			const lduPrimitiveMesh& lduMesh,
			const lduInterface& fineInterface,
			const labelField& localRestrictAddressing,
			const labelField& neighbourRestrictAddressing
		);


		// Destructor

		virtual ~mixingPlaneAMGInterface();


		// Member Functions

			// Access

				//- Return true if interface is coupled
		virtual bool coupled() const
		{
			return true;
		}


		// Agglomeration

			//- Agglomerating the given fine-level coefficients and return
		virtual tmp<scalarField> agglomerateCoeffs
		(
			const scalarField& fineCoeffs
		) const;


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

		//- Initialise transfer of internal field adjacent to the interface
		virtual void initInternalFieldTransfer
		(
			const Pstream::commsTypes commsType,
			const unallocLabelList& iF
		) const;

		virtual void initInternalFieldTransfer
		(
			const Pstream::commsTypes commsType,
			const scalarField& iF
		) const;

		//- Transfer and return internal field adjacent to the interface
		virtual tmp<labelField> internalFieldTransfer
		(
			const Pstream::commsTypes commsType,
			const unallocLabelList& iF
		) const;

		virtual tmp<scalarField> internalFieldTransfer
		(
			const Pstream::commsTypes commsType,
			const scalarField& iF
		) const;


		//- MixingPlane interface functions

			//- Is this the master side?
		virtual bool master() const;

		//- Return shadow patch index
		virtual label shadowIndex() const;

		//- Return shadow interface
		virtual const mixingPlaneLduInterface& shadowInterface() const;

		//- Return addressing
		virtual const labelListList& addressing() const;

		//- Return weights
		virtual const scalarListList& weights() const;

		//- Return face transformation tensor
		virtual const tensorField& forwardT() const;

		//- Return neighbour-cell transformation tensor
		virtual const tensorField& reverseT() const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_mixingPlaneAMGInterface_Header
