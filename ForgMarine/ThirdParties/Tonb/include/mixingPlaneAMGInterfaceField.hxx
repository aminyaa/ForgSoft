#pragma once
#ifndef _mixingPlaneAMGInterfaceField_Header
#define _mixingPlaneAMGInterfaceField_Header

#include <AMGInterfaceField.hxx>
#include <mixingPlaneAMGInterface.hxx>
#include <MixingPlaneBlockLduInterfaceField.hxx>
#include <mixingPlaneLduInterfaceField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
					  Class mixingPlaneAMGInterfaceField Declaration
	\*---------------------------------------------------------------------------*/

	class mixingPlaneAMGInterfaceField
		:
		public AMGInterfaceField,
		virtual public mixingPlaneLduInterfaceField
	{
		// Private data

			//- Local reference cast into the mixingPlane interface
		const mixingPlaneAMGInterface& mixingPlaneInterface_;

		//- Is the transform required
		bool doTransform_;

		//- Rank of component for transformation
		int rank_;

		//- Transfer buffer
		mutable scalarField transferBuffer_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		mixingPlaneAMGInterfaceField(const mixingPlaneAMGInterfaceField&);

		//- Disallow default bitwise assignment
		void operator=(const mixingPlaneAMGInterfaceField&);


	public:

		//- Runtime type information
		TypeName("mixingPlane");


		// Constructors

			//- Construct from AMG interface and fine level interface field
		mixingPlaneAMGInterfaceField
		(
			const AMGInterface& AMGCp,
			const lduInterfaceField& fineInterfaceField
		);


		// Destructor

		virtual ~mixingPlaneAMGInterfaceField();


		// Member Functions

			// Access

				//- Return size
		label size() const
		{
			return mixingPlaneInterface_.size();
		}


		// Coupled interface matrix update

			//- Transform neighbour field
		virtual void transformCoupleField
		(
			scalarField& pnf,
			const direction cmpt
		) const
		{
			mixingPlaneLduInterfaceField::transformCoupleField(pnf, cmpt);
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


		//- MixingPlane interface functions

			//- Does the interface field perform the transfromation
		virtual bool doTransform() const
		{
			return doTransform_;
		}

		//- Return face transformation tensor
		virtual const tensorField& forwardT() const
		{
			return mixingPlaneInterface_.forwardT();
		}

		//- Return neighbour-cell transformation tensor
		virtual const tensorField& reverseT() const
		{
			return mixingPlaneInterface_.reverseT();
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

#endif // !_mixingPlaneAMGInterfaceField_Header
