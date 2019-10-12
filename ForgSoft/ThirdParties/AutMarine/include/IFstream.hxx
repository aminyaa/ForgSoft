#pragma once
#ifndef _IFstream_Header
#define _IFstream_Header

#include <ISstream.hxx>

#include <fstream>
using std::ifstream;

namespace AutLib
{

	//- A std::istream with ability to handle compressed files
	class IFstreamAllocator
	{
		friend class IFstream;

		// Private data

		istream* ifPtr_;
		IOstream::compressionType compression_;


		// Constructors

		//- Construct from pathname
		IFstreamAllocator(const fileName& pathname);


		// Destructor

		~IFstreamAllocator();


	public:

		// Member functions

		//- Access to underlying std::istream (for e.g. lexer)
		istream& stdStream();
	};

	class IFstream
		: public IFstreamAllocator
		, public ISstream
	{

		// Private data

		fileName pathname_;

	public:

		// Declare name of the class and its debug switch
		static const char* typeName_() { return "IFstream"; }
		static const word typeName;
		static debug::debugSwitch debug;;

		// Constructors

		//- Construct from pathname
		IFstream
		(
			const fileName& pathname,
			streamFormat format = ASCII,
			versionNumber version = currentVersion
		);


		// Destructor

		~IFstream();


		// Member functions

		// Access

		//- Return the name of the stream
		const fileName& name() const
		{
			return pathname_;
		}

		//- Return non-const access to the name of the stream
		fileName& name()
		{
			return pathname_;
		}

		// Print

		//- Print description of IOstream to Ostream
		virtual void print(Ostream&) const;


		// Member operators

		//- Return a non-const reference to const IFstream
		//  Needed for read-constructors where the stream argument is temporary:
		//  e.g. thing thisThing(IFstream("thingFileName")());
		IFstream& operator()() const;
	};
}

#endif // !_IFstream_Header
