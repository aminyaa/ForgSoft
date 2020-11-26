#pragma once
#ifndef _lduInterface_Header
#define _lduInterface_Header

#include <labelField.hxx>
#include <typeInfo.hxx>
#include <Pstream.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	/*---------------------------------------------------------------------------*\
						 Class lduInterface Declaration
	\*---------------------------------------------------------------------------*/

	class lduInterface
	{
		// Private Member Functions

			//- Disallow default bitwise copy construct
		lduInterface(const lduInterface&);

		//- Disallow default bitwise assignment
		void operator=(const lduInterface&);


	public:

		//- Runtime type information
		TypeName("lduInterface");


		// Constructors

			//- Construct null
		lduInterface()
		{}


		// Destructor

		virtual ~lduInterface();


		// Member Functions

			// Access

				//- Return true if interface is coupled
		virtual bool coupled() const = 0;

		//- Return faceCell addressing
		virtual const unallocLabelList& faceCells() const = 0;


		// Interface transfer functions

			//- Return the values of the given internal data adjacent to
			//  the interface as a field
		virtual tmp<labelField> interfaceInternalField
		(
			const unallocLabelList& internalData
		) const = 0;

		//- Initialise interface data transfer
		virtual void initTransfer
		(
			const Pstream::commsTypes commsType,
			const unallocLabelList& interfaceData
		) const
		{}

		//- Transfer and return neighbour field
		virtual tmp<labelField> transfer
		(
			const Pstream::commsTypes commsType,
			const unallocLabelList& interfaceData
		) const = 0;

		//- Initialise transfer of internal field adjacent to the interface
		virtual void initInternalFieldTransfer
		(
			const Pstream::commsTypes commsType,
			const unallocLabelList& iF
		) const
		{}

		//- Transfer and return internal field adjacent to the interface
		virtual tmp<labelField> internalFieldTransfer
		(
			const Pstream::commsTypes commsType,
			const unallocLabelList& iF
		) const = 0;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_lduInterface_Header
