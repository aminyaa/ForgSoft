#pragma once
#ifndef _OSstream_Header
#define _OSstream_Header

#include <Ostream.hxx>

namespace AutLib
{

	class OSstream
		: public Ostream
	{

		// Private data

		fileName name_;
		ostream& os_;

		// Private Member Functions

		//- Disallow default bitwise assignment
		void operator=(const OSstream&) = delete;

	protected:

		//- Return the stream reference
		ostream& stream()
		{
			return os_;
		}

		//- Return the const stream reference
		const ostream& stream() const
		{
			return os_;
		}

	public:

		// Constructors

		//- Set stream status
		OSstream
		(
			ostream& os,
			const string& name,
			streamFormat format = ASCII,
			versionNumber version = currentVersion,
			compressionType compression = UNCOMPRESSED
		);


		// Member functions

		// Enquiry

		//- Return the name of the stream
		//  Useful for Fstream to return the filename
		virtual const fileName& name() const
		{
			return name_;
		}

		//- Return non-const access to the name of the stream
		//  Useful to alter the stream name
		virtual fileName& name()
		{
			return name_;
		}

		//- Return flags of output stream
		virtual ios_base::fmtflags flags() const;


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
		//  In the rare case that the string contains a final trailing
		//  backslash, it will be dropped to the appearance of an escaped
		//  double-quote.
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

		//- Write longDoubleScalar
		virtual Ostream& write(const longDoubleScalar);

		//- Write binary block
		virtual Ostream& write(const char*, std::streamsize);

		//- Add indentation characters
		virtual void indent();


		// Stream state functions

		//- Set flags of output stream
		virtual ios_base::fmtflags flags(const ios_base::fmtflags flags);

		//- Flush stream
		virtual void flush();

		//- Add newline and flush stream
		virtual void endl();

		//- Get width of output field
		virtual int width() const;

		//- Set width of output field (and return old width)
		virtual int width(const int);

		//- Get precision of output field
		virtual int precision() const;

		//- Set precision of output field (and return old precision)
		virtual int precision(const int);


		// Print

		//- Print description of IOstream to Ostream
		virtual void print(Ostream&) const;
	};
}

#include <OSstreamI.hxx>

#endif // !_OSstream_Header
