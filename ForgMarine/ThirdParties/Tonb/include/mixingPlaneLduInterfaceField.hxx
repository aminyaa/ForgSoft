#pragma once
#ifndef _mixingPlaneLduInterfaceField_Header
#define _mixingPlaneLduInterfaceField_Header

#include <primitiveFieldsFwd.hxx>
#include <typeInfo.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
					  Class mixingPlaneLduInterfaceField Declaration
	\*---------------------------------------------------------------------------*/

	class mixingPlaneLduInterfaceField
	{
	public:

		//- Runtime type information
		TypeName("mixingPlaneLduInterfaceField");


		// Constructors

			//- Construct given coupled patch
		mixingPlaneLduInterfaceField()
		{}


		//- Destructor
		virtual ~mixingPlaneLduInterfaceField();


		// Member Functions

			// Access

				//- Is the transform required
		virtual bool doTransform() const = 0;

		//- Return face transformation tensor
		virtual const tensorField& forwardT() const = 0;

		//- Return neighbour-cell transformation tensor
		virtual const tensorField& reverseT() const = 0;

		//- Return rank of component for transform
		virtual int rank() const = 0;


		//- Transform given patch internal field
		void transformCoupleField
		(
			scalarField& psiInternal,
			const direction cmpt
		) const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_mixingPlaneLduInterfaceField_Header
