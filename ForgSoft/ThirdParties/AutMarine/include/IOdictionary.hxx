#pragma once
#ifndef _IOdictionary_Header
#define _IOdictionary_Header

#include <dictionary.hxx>
#include <regIOobject.hxx>

namespace AutLib
{

	class IOdictionary
		: public regIOobject
		, public dictionary
	{

	public:

		static const char* typeName_() { return "dictionary"; }

		static const word typeName;
		static debug::debugSwitch debug;;

		virtual const word& type() const { return typeName; };


		// Constructors

		//- Construct given an IOobject
		IOdictionary(const IOobject&);

		//- Construct given an IOobject and dictionary
		IOdictionary(const IOobject&, const dictionary&);


		// Destructor

		virtual ~IOdictionary();


		// Member functions

		//- Name function is needed to disambiguate those inherited
		//  from regIOobject and dictionary
		const word& name() const;

		//- ReadData function required for regIOobject read operation
		virtual bool readData(Istream&);

		//- WriteData function required for regIOobject write operation
		virtual bool writeData(Ostream&) const;


		// Member operators

		//- Assignment of other IOdictionary's entries to this IOdictionary
		void operator=(const IOdictionary&);
	};
}

#endif // !_IOdictionary_Header
