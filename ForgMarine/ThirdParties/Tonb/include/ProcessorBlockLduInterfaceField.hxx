#pragma once
#ifndef _ProcessorBlockLduInterfaceField_Header
#define _ProcessorBlockLduInterfaceField_Header

#include <primitiveFieldsFwd.hxx>
#include <typeInfo.hxx>
#include <Field.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
				   Class ProcessorBlockLduInterfaceField Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class ProcessorBlockLduInterfaceField
	{
	public:

		//- Runtime type information
		TypeName("ProcessorBlockLduInterfaceField");


		// Constructors

			//- Construct given coupled patch
		ProcessorBlockLduInterfaceField()
		{}


		//- Destructor
		virtual ~ProcessorBlockLduInterfaceField();


		// Member Functions

			// Access

				//- Return processor number
		virtual int myProcNo() const = 0;

		//- Return neigbour processor number
		virtual int neighbProcNo() const = 0;

		//- Is the transform required
		virtual bool doTransform() const = 0;

		//- Return face transformation tensor
		virtual const tensorField& forwardT() const = 0;

		//- Return rank of component for transform
		virtual int rank() const = 0;


		//- Transform given patch component field
		void transformCoupleField
		(
			scalarField& f,
			const direction cmpt
		) const;

		//- Transform given patch field
		void transformCoupleField
		(
			Field<Type>& f
		) const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <ProcessorBlockLduInterfaceField.cxx>
#endif

// ************************************************************************* //

#endif // !_ProcessorBlockLduInterfaceField_Header
