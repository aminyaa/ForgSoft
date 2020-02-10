#pragma once
#ifndef _cyclicAMGInterface_Header
#define _cyclicAMGInterface_Header

#include <AMGInterface.hxx>
#include <cyclicLduInterface.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						  Class cyclicAMGInterface Declaration
	\*---------------------------------------------------------------------------*/

	class cyclicAMGInterface
		:
		public AMGInterface,
		virtual public cyclicLduInterface
	{
		// Private data

			//- Reference tor the cyclicLduInterface from which this is
			//  agglomerated
		const cyclicLduInterface& fineCyclicInterface_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		cyclicAMGInterface(const cyclicAMGInterface&);

		//- Disallow default bitwise assignment
		void operator=(const cyclicAMGInterface&);


	public:

		//- Runtime type information
		TypeName("cyclic");


		// Constructors

			//- Construct from fine level interface,
			//  local and neighbour restrict addressing
		cyclicAMGInterface
		(
			const lduPrimitiveMesh& lduMesh,
			const lduInterface& fineInterface,
			const labelField& localRestrictAddressing,
			const labelField& neighbourRestrictAddressing
		);


		// Destructor

		virtual ~cyclicAMGInterface();


		// Member Functions

			// Access

				//- Return true if interface is coupled
		virtual bool coupled() const
		{
			return true;
		}


		// Interface transfer functions

			//- Transfer and return neighbour field
		virtual tmp<labelField> transfer
		(
			const Pstream::commsTypes commsType,
			const unallocLabelList& interfaceData
		) const;

		//- Transfer and return internal field adjacent to the interface
		virtual tmp<labelField> internalFieldTransfer
		(
			const Pstream::commsTypes commsType,
			const unallocLabelList& iF
		) const;


		//- Cyclic interface functions

			//- Return face transformation tensor
		virtual const tensorField& forwardT() const
		{
			return fineCyclicInterface_.forwardT();
		}

		//- Return neighbour-cell transformation tensor
		virtual const tensorField& reverseT() const
		{
			return fineCyclicInterface_.reverseT();
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_cyclicAMGInterface_Header
