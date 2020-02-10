#pragma once
#ifndef _overlapGGILduInterfaceField_Header
#define _overlapGGILduInterfaceField_Header

#include <primitiveFieldsFwd.hxx>
#include <typeInfo.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
					  Class overlapGGILduInterfaceField Declaration
	\*---------------------------------------------------------------------------*/

	class overlapGGILduInterfaceField
	{

	public:

		//- Runtime type information
		TypeName("overlapGGILduInterfaceField");


		// Constructors

			//- Construct given coupled patch
		overlapGGILduInterfaceField()
		{}


		//- Destructor
		virtual ~overlapGGILduInterfaceField();


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

#endif // !_overlapGGILduInterfaceField_Header
