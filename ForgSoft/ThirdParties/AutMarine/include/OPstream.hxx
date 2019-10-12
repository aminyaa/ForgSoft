#pragma once
#ifndef _OPstream_Header
#define _OPstream_Header

#include <Ostream.hxx>
#include <Pstream.hxx>

namespace AutLib
{

	class OPstream
		: public Pstream
		, public Ostream
	{

		// Private data

		// ID of receiving processor
		int toProcNo_;


		// Private member functions

		//- Write a T to the transfer buffer
		template<class T>
		void writeToBuffer(const T&);

		//- Write a char to the transfer buffer
		void writeToBuffer(const char&);

		//- Write data to the transfer buffer
		void writeToBuffer
		(
			const void* data,
			size_t count,
			size_t align
		);

	public:

		// Constructors

		//- Construct given process index to send to and optional buffer size,
		//  write format and IO version
		OPstream
		(
			const commsTypes commsType,
			const int toProcNo,
			const label bufSize = 0,
			streamFormat format = BINARY,
			versionNumber version = currentVersion
		);


		// Destructor

		~OPstream();


		// Member functions

		// Inquiry

		//- Return flags of output stream
		ios_base::fmtflags flags() const
		{
			return ios_base::fmtflags(0);
		}


		// Write functions

		//- Write given buffer to given processor
		static bool write
		(
			const commsTypes commsType,
			const int toProcNo,
			const char* buf,
			const std::streamsize bufSize
		);

		//- Non-blocking writes: wait until all have finished.
		static void waitRequests();

		//- Non-blocking writes: has request i finished?
		static bool finishedRequest(const label i);

		//- Write next token to stream
		Ostream& write(const token&);

		//- Write character
		Ostream& write(const char);

		//- Write character string
		Ostream& write(const char*);

		//- Write word
		Ostream& write(const word&);

		//- Write string
		Ostream& write(const string&);

		//- Write std::string surrounded by quotes.
		//  Optional write without quotes.
		Ostream& writeQuoted
		(
			const std::string&,
			const bool quoted = true
		);

		//- Write label
		Ostream& write(const label);

		//- Write floatScalar
		Ostream& write(const floatScalar);

		//- Write doubleScalar
		Ostream& write(const doubleScalar);

		//- Write longDoubleScalar
		Ostream& write(const longDoubleScalar);

		//- Write binary block
		Ostream& write(const char*, std::streamsize);

		//- Add indentation characters
		void indent()
		{}


		// Stream state functions

		//- Flush stream
		void flush()
		{}

		//- Add newline and flush stream
		void endl()
		{}

		//- Get width of output field
		int width() const
		{
			return 0;
		}

		//- Set width of output field (and return old width)
		int width(const int)
		{
			return 0;
		}

		//- Get precision of output field
		int precision() const
		{
			return 0;
		}

		//- Set precision of output field (and return old precision)
		int precision(const int)
		{
			return 0;
		}


		// Edit

		//- Set flags of stream
		ios_base::fmtflags flags(const ios_base::fmtflags)
		{
			return ios_base::fmtflags(0);
		}


		// Print

		//- Print description of IOstream to Ostream
		void print(Ostream&) const;
	};
}

#include <OPstreamI.hxx>

#endif // !_OPstream_Header
