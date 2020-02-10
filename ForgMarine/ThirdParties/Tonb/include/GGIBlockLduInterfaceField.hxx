#pragma once
#ifndef _GGIBlockLduInterfaceField_Header
#define _GGIBlockLduInterfaceField_Header

#include <primitiveFieldsFwd.hxx>
#include <typeInfo.hxx>
#include <Field.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
					   Class GGIBlockLduInterfaceField Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class GGIBlockLduInterfaceField
	{
	public:

		//- Runtime type information
		TypeName("GGIBlockLduInterfaceField");


		// Constructors

			//- Construct given coupled patch
		GGIBlockLduInterfaceField()
		{}


		//- Destructor
		virtual ~GGIBlockLduInterfaceField();


		// Member Functions

			// Access

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
#   include <GGIBlockLduInterfaceField.cxx>
#endif

// ************************************************************************* //

#endif // !_GGIBlockLduInterfaceField_Header
