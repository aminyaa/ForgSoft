#pragma once
#ifndef _regionCoupleAMGInterfaceField_Header
#define _regionCoupleAMGInterfaceField_Header

#include <regionCoupleAMGInterface.hxx>
#include <ggiAMGInterfaceField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
					  Class regionCoupleAMGInterfaceField Declaration
	\*---------------------------------------------------------------------------*/

	class regionCoupleAMGInterfaceField
		:
		public ggiAMGInterfaceField
	{
		// Private data

			//- Local reference cast into the regionCouple interface
		const regionCoupleAMGInterface& regionCoupleInterface_;

	public:

		//- Runtime type information
		TypeName("regionCouple");


		// Constructors

			//- Construct from AMG interface and fine level interface field
		regionCoupleAMGInterfaceField
		(
			const AMGInterface& AMGCp,
			const lduInterfaceField& fineInterfaceField
		);


		// Destructor

		virtual ~regionCoupleAMGInterfaceField();


		// Member Functions

			// Coupled interface matrix update

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
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_regionCoupleAMGInterfaceField_Header
