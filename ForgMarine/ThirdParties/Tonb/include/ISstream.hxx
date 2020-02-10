#pragma once
#ifndef _ISstream_Header
#define _ISstream_Header

#include <Istream.hxx>
#include <fileName.hxx>

#include <iostream>

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						   Class ISstream Declaration
\*---------------------------------------------------------------------------*/

	class ISstream
		:
		public Istream
	{
		// Private data

		fileName name_;
		istream& is_;


		// Private member functions

		char nextValid();


		// Private Member Functions

			//- Disallow default bitwise assignment
		void operator=(const ISstream&);


	protected:

		// Protected member functions

			//- Return the stream reference
		istream& stream()
		{
			return is_;
		}

		//- Return the const stream reference
		const istream& stream() const
		{
			return is_;
		}


	public:

		// Constructors

			//- Construct as wrapper around istream
		ISstream
		(
			istream& is,
			const string& name,
			streamFormat format = ASCII,
			versionNumber version = currentVersion,
			compressionType compression = UNCOMPRESSED
		);


		// Destructor

		virtual ~ISstream()
		{}


		// Member functions

			// Inquiry

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


		// Read functions

			//- Raw, low-level get character function.
		ISstream& get(char&);

		//- Raw, low-level getline into a string function.
		ISstream& getLine(string&);

		//- Raw, low-level putback character function.
		ISstream& putback(const char&);

		//- Return next token from stream
		virtual Istream& read(token&);

		//- Read a character
		virtual Istream& read(char&);

		//- Read a word
		virtual Istream& read(word&);

		//- Read a string (including enclosing double-quotes).
		//  Backslashes are retained, except when escaping double-quotes
		//  and an embedded newline character.
		virtual Istream& read(string&);

		//- Read a label
		virtual Istream& read(label&);

		//- Read a floatScalar
		virtual Istream& read(floatScalar&);

		//- Read a doubleScalar
		virtual Istream& read(doubleScalar&);

		//- Read a longDoubleScalar
		virtual Istream& read(longDoubleScalar&);

		//- Read binary block
		virtual Istream& read(char*, std::streamsize);

		//- Rewind and return the stream so that it may be read again
		virtual Istream& rewind();


		// Stream state functions

			//- Set flags of output stream
		virtual ios_base::fmtflags flags(const ios_base::fmtflags flags);


		// Print

			//- Print description of IOstream to Ostream
		virtual void print(Ostream&) const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#include <ISstreamI.hxx>

#endif // !_ISstream_Header
