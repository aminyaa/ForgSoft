#pragma once
#ifndef _IOField_Header
#define _IOField_Header

#include <regIOobject.hxx>
#include <Field.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							   Class IOField Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class IOField
		: public regIOobject
		, public Field<Type>
	{

	public:

		TypeName("Field");


		// Constructors

			//- Construct from IOobject
		IOField(const IOobject&);

		//- Construct from IOobject and size (does not set values)
		IOField(const IOobject&, const label size);

		//- Construct from components
		IOField(const IOobject&, const Field<Type>&);

		//- Construct by transferring the Field contents
		IOField(const IOobject&, const Xfer<Field<Type> >&);


		// Destructor

		virtual ~IOField();


		// Member functions

		bool writeData(Ostream&) const;


		// Member operators

		void operator=(const IOField<Type>&);

		void operator=(const Field<Type>&);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <IOFieldI.hxx>

#ifdef NoRepository
#   include <IOField.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !1
