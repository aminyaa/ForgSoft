#pragma once
#ifndef _Istream_Header
#define _Istream_Header

#include <IOstream.hxx>
//#include <token.hxx>

namespace AutLib
{

	class token;

	class Istream 
		: public IOstream
	{

		// Private data

		//- Has a token been put back on the stream
		bool putBack_;

		//- The last token put back on the stream
		token* putBackToken_;

	public:

		// Constructors

		//- Set stream status
		Istream
		(
			streamFormat format = ASCII,
			versionNumber version = currentVersion,
			compressionType compression = UNCOMPRESSED
		);
			/*: IOstream(format, version, compression)
			, putBack_(false)
			, putBackToken_(NULL)
		{}*/


		// Destructor

		virtual ~Istream();

		// Member functions

		// Read functions

		//- Put back token
		void putBack(const token&);

		//- Get the put back token
		bool getBack(token&);

		//- Return next token from stream
		virtual Istream& read(token&) = 0;

		//- Read a character
		virtual Istream& read(char&) = 0;

		//- Read a word
		virtual Istream& read(word&) = 0;

		// Read a string (including enclosing double-quotes)
		virtual Istream& read(string&) = 0;

		//- Read a label
		virtual Istream& read(label&) = 0;

		//- Read a floatScalar
		virtual Istream& read(floatScalar&) = 0;

		//- Read a doubleScalar
		virtual Istream& read(doubleScalar&) = 0;

		//- Read a longDoubleScalar
		virtual Istream& read(longDoubleScalar&) = 0;

		//- Read binary block
		virtual Istream& read(char*, std::streamsize) = 0;

		//- Rewind and return the stream so that it may be read again
		virtual Istream& rewind() = 0;


		// Read List punctuation tokens

		Istream& readBegin(const char* funcName);
		Istream& readEnd(const char* funcName);
		Istream& readEndBegin(const char* funcName);

		char readBeginList(const char* funcName);
		char readEndList(const char* funcName);


		// Member operators

		//- Return a non-const reference to const Istream
		//  Needed for read-constructors where the stream argument is temporary:
		//  e.g. thing thisThing(IFstream("thingFileName")());
		Istream& operator()() const;
	};

	typedef Istream& (*IstreamManip)(Istream&);

	//- operator>> handling for manipulators without arguments
	inline Istream& operator>>(Istream& is, IstreamManip f)
	{
		return f(is);
	}

	//- operator>> handling for manipulators without arguments
	inline Istream& operator>>(Istream& is, IOstreamManip f)
	{
		f(is);
		return is;
	}
}

#endif // !_Istream_Header
