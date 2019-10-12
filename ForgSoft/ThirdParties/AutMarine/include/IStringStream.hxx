#pragma once
#ifndef _IStringStream_Header
#define _IStringStream_Header

#include <ISstream.hxx>
#include <sstream>

namespace AutLib
{

	class IStringStream
		: public ISstream
	{

	public:

		// Constructors

		//- Construct from string
		IStringStream
		(
			const string& buffer,
			streamFormat format = ASCII,
			versionNumber version = currentVersion
		)
			: ISstream
			(
				*(new std::istringstream(buffer)),
				"IStringStream.sourceFile",
				format,
				version
			)
		{}


		//- Construct from char*
		IStringStream
		(
			const char* buffer,
			streamFormat format = ASCII,
			versionNumber version = currentVersion
		)
			:
			ISstream
			(
				*(new std::istringstream(buffer)),
				"IStringStream.sourceFile",
				format,
				version
			)
		{}


		// Destructor

		~IStringStream()
		{
			delete &dynamic_cast<std::istringstream&>(stream());
		}


		// Member functions

		// Access

		//- Return the string
		string str() const
		{
			return dynamic_cast<const std::istringstream&>(stream()).str();
		}


		// Print

		//- Print description to Ostream
		void print(Ostream&) const;


		// Member operators

		//- Return a non-const reference to const Istream
		//  Needed for read-constructors where the stream argument is temporary:
		//  e.g. thing thisThing(IFstream("thingFileName")());
		Istream& operator()() const
		{
			return const_cast<IStringStream&>(*this);
		}
	};
}

#endif // !_IStringStream_Header
