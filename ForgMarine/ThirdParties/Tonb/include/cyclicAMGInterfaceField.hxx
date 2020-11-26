#pragma once
#ifndef _cyclicAMGInterfaceField_Header
#define _cyclicAMGInterfaceField_Header

#include <AMGInterfaceField.hxx>
#include <cyclicAMGInterface.hxx>
#include <cyclicLduInterfaceField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
					  Class cyclicAMGInterfaceField Declaration
	\*---------------------------------------------------------------------------*/

	class cyclicAMGInterfaceField
		:
		public AMGInterfaceField,
		virtual public cyclicLduInterfaceField
	{
		// Private data

			//- Local reference cast into the cyclic interface
		const cyclicAMGInterface& cyclicInterface_;

		//- Is the transform required
		bool doTransform_;

		//- Rank of component for transformation
		int rank_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		cyclicAMGInterfaceField(const cyclicAMGInterfaceField&);

		//- Disallow default bitwise assignment
		void operator=(const cyclicAMGInterfaceField&);


	public:

		//- Runtime type information
		TypeName("cyclic");


		// Constructors

			//- Construct from AMG interface and fine level interface field
		cyclicAMGInterfaceField
		(
			const AMGInterface& AMGCp,
			const lduInterfaceField& fineInterfaceField
		);


		// Destructor

		virtual ~cyclicAMGInterfaceField();


		// Member Functions

			// Access

				//- Return size
		label size() const
		{
			return cyclicInterface_.size();
		}


		// Coupled interface matrix update

			//- Transform neighbour field
		virtual void transformCoupleField
		(
			scalarField& pnf,
			const direction cmpt
		) const
		{
			cyclicLduInterfaceField::transformCoupleField(pnf, cmpt);
		}

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


		//- Cyclic interface functions

			//- Does the interface field perform the transfromation
		virtual bool doTransform() const
		{
			return doTransform_;
		}

		//- Return face transformation tensor
		virtual const tensorField& forwardT() const
		{
			return cyclicInterface_.forwardT();
		}

		//- Return neighbour-cell transformation tensor
		virtual const tensorField& reverseT() const
		{
			return cyclicInterface_.reverseT();
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

#endif // !_cyclicAMGInterfaceField_Header
