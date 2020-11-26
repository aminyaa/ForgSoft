#pragma once
#ifndef _ggiAMGInterfaceField_Header
#define _ggiAMGInterfaceField_Header

#include <AMGInterfaceField.hxx>
#include <ggiAMGInterface.hxx>
#include <ggiLduInterfaceField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						 Class ggiAMGInterfaceField Declaration
	\*---------------------------------------------------------------------------*/

	class ggiAMGInterfaceField
		:
		public AMGInterfaceField,
		virtual public ggiLduInterfaceField
	{
		// Private data

			//- Local reference cast into the ggi interface
		const ggiAMGInterface& ggiInterface_;

		//- Is the transform required
		bool doTransform_;

		//- Rank of component for transformation
		int rank_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		ggiAMGInterfaceField(const ggiAMGInterfaceField&);

		//- Disallow default bitwise assignment
		void operator=(const ggiAMGInterfaceField&);


	public:

		//- Runtime type information
		TypeName("ggi");


		// Constructors

			//- Construct from AMG interface and fine level interface field
		ggiAMGInterfaceField
		(
			const AMGInterface& AMGCp,
			const lduInterfaceField& fineInterfaceField
		);


		//- Destructor
		virtual ~ggiAMGInterfaceField();


		// Member Functions

			// Access

				//- Return size
		label size() const
		{
			return ggiInterface_.size();
		}


		// Coupled interface matrix update

			//- Transform neighbour field
		virtual void transformCoupleField
		(
			scalarField& pnf,
			const direction cmpt
		) const
		{
			ggiLduInterfaceField::transformCoupleField(pnf, cmpt);
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
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_ggiAMGInterfaceField_Header
