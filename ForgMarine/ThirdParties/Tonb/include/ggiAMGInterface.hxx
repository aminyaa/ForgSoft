#pragma once
#ifndef _ggiAMGInterface_Header
#define _ggiAMGInterface_Header

#include <AMGInterface.hxx>
#include <ggiLduInterface.hxx>
#include <mapDistribute.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						 Class ggiAMGInterface Declaration
	\*---------------------------------------------------------------------------*/

	class ggiAMGInterface
		:
		public AMGInterface,
		virtual public ggiLduInterface
	{
		// Private data

			//- Reference tor the ggiLduInterface from which this is
			//  agglomerated
		const ggiLduInterface& fineGgiInterface_;

		//- Zone size
		label zoneSize_;

		//- Zone addressing
		labelList zoneAddressing_;


		// Parallel communication

			//- Map-distribute comms tool
		mutable mapDistribute* mapPtr_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		ggiAMGInterface(const ggiAMGInterface&);

		//- Disallow default bitwise assignment
		void operator=(const ggiAMGInterface&);


		//- Init fast reduce
		void initFastReduce() const;

		//- Return mapDistribute
		const mapDistribute& map() const;


		// Private static data

			//- Processor cluster offset index
		static const label procOffset = 4000000;


	public:

		//- Runtime type information
		TypeName("ggi");


		// Constructors

			//- Construct from fine level interface,
			//  local and neighbour restrict addressing
		ggiAMGInterface
		(
			const lduPrimitiveMesh& lduMesh,
			const lduInterface& fineInterface,
			const labelField& localRestrictAddressing,
			const labelField& neighbourRestrictAddressing
		);


		// Destructor

		virtual ~ggiAMGInterface();


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

			//- Fast reduce
			//  Note: contains global communications
			//  New, HJ, 24/Jun/2011
		template<class Type>
		tmp<Field<Type> > fastReduce(const UList<Type>&) const;

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


		//- GGI interface functions

			//- Is this the master side?
		virtual bool master() const;

		//- Is this the fine level?
		virtual bool fineLevel() const;

		//- Return shadow patch index
		virtual label shadowIndex() const;

		//- Return shadow interface
		virtual const ggiLduInterface& shadowInterface() const;

		//- Return reference tor the ggiLduInterface from which this is
		//  agglomerated
		const ggiLduInterface& fineGgiInterface() const
		{
			return fineGgiInterface_;
		}

		//- Return interface size
		virtual label interfaceSize() const;

		//- Return zone size
		virtual label zoneSize() const;

		//- Return zone addressing
		virtual const labelList& zoneAddressing() const;

		//- Return addressing
		virtual const labelListList& addressing() const;

		//- Is the patch localised on a single processor
		virtual bool localParallel() const;

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

#ifdef NoRepository
#   include <ggiAMGInterfaceTemplates.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_ggiAMGInterface_Header
