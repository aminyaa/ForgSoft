#pragma once
#ifndef _prefixOSstream_Header
#define _prefixOSstream_Header

#include <OSstream.hxx>

namespace AutLib
{

	class prefixOSstream
		: public OSstream
	{
		// Private data

		bool printPrefix_;

		string prefix_;

		// Private member functions

		inline void checkWritePrefix();


	public:

		// Constructors

		//- Set stream status
		prefixOSstream
		(
			ostream& os,
			const string& name,
			streamFormat format = ASCII,
			versionNumber version = currentVersion,
			compressionType compression = UNCOMPRESSED
		);


		// Member functions

		// Enquiry

		//- Return the prefix of the stream
		const string& prefix() const
		{
			return prefix_;
		}

		//- Return non-const access to the prefix of the stream
		string& prefix()
		{
			return prefix_;
		}


		// Write functions

		//- Write next token to stream
		virtual Ostream& write(const token&);

		//- Write character
		virtual Ostream& write(const char);

		//- Write character string
		virtual Ostream& write(const char*);

		//- Write word
		virtual Ostream& write(const word&);

		//- Write string
		virtual Ostream& write(const string&);

		//- Write std::string surrounded by quotes.
		//  Optional write without quotes.
		virtual Ostream& writeQuoted
		(
			const std::string&,
			const bool quoted = true
		);

		//- Write label
		virtual Ostream& write(const label);

		//- Write floatScalar
		virtual Ostream& write(const floatScalar);

		//- Write doubleScalar
		virtual Ostream& write(const doubleScalar);

		//- Write doubleScalar
		virtual Ostream& write(const longDoubleScalar);

		//- Write binary block
		virtual Ostream& write(const char*, std::streamsize);

		//- Add indentation characters
		virtual void indent();


		// Print

		//- Print description of IOstream to Ostream
		virtual void print(Ostream&) const;
	};
}

#endif // !_prefixOSstream_Header
