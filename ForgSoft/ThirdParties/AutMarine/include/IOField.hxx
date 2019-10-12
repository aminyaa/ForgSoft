#pragma once
#ifndef _IOField_Header
#define _IOField_Header

#include <regIOobject.hxx>
#include <Field.hxx>

namespace AutLib
{

	template<class Type>
	class IOField
		: public regIOobject
		, public Field<Type>
	{

	public:

		static const char* typeName_() { return "Field"; }

		static const word typeName;
		static debug::debugSwitch debug;;

		virtual const word& type() const { return typeName; };


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
}

#include <IOFieldI.hxx>

#endif // !_IOField_Header
