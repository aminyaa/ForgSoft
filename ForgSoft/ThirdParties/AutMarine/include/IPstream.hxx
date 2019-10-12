#pragma once
#ifndef _IPstream_Header
#define _IPstream_Header

#include <Istream.hxx>
#include <Pstream.hxx>

namespace AutLib
{

	class IPstream
		: public Pstream
		, public Istream
	{

		// Private data

		//- ID of sending processor
		int fromProcNo_;

		//- Message size
		label messageSize_;


		// Private member functions

		//- Check the bufferPosition_ against messageSize_ for EOF
		void checkEof();

		//- Read a T from the transfer buffer
		template<class T>
		void readFromBuffer(T&);

		//- Read data from the transfer buffer
		void readFromBuffer(void* data, size_t count, size_t align);

	public:

		// Constructors

		//- Construct given process index to read from, optional buffer size,
		//  read format and IO version
		IPstream
		(
			const commsTypes commsType,
			const int fromProcNo,
			const label bufSize = 0,
			streamFormat format = BINARY,
			versionNumber version = currentVersion
		);


		// Destructor
		~IPstream();


		// Member functions

		// Inquiry

		//- Return flags of output stream
		ios_base::fmtflags flags() const
		{
			return ios_base::fmtflags(0);
		}


		// Read functions

		//- Read into given buffer from given processor and return the
		//  message size
		static label read
		(
			const commsTypes commsType,
			const int fromProcNo,
			char* buf,
			const std::streamsize bufSize
		);

		//- Non-blocking receives: wait until all have finished.
		static void waitRequests();

		//- Non-blocking receives: has request i finished?
		static bool finishedRequest(const label i);

		//- Return next token from stream
		Istream& read(token&);

		//- Read a character
		Istream& read(char&);

		//- Read a word
		Istream& read(word&);

		// Read a string (including enclosing double-quotes)
		Istream& read(string&);

		//- Read a label
		Istream& read(label&);

		//- Read a floatScalar
		Istream& read(floatScalar&);

		//- Read a doubleScalar
		Istream& read(doubleScalar&);

		//- Read a longDoubleScalar
		Istream& read(longDoubleScalar&);

		//- Read binary block
		Istream& read(char*, std::streamsize);

		//- Rewind and return the stream so that it may be read again
		Istream& rewind();


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

#endif // !_IPstream_Header
