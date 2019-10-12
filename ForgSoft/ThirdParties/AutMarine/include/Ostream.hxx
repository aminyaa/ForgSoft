#pragma once
#ifndef _Ostream_Header
#define _Ostream_Header

#include <IOstream.hxx>

namespace AutLib
{

	// Forward declaration of classes
	class token;
	class keyType;

	class Ostream
		: public IOstream
	{

	protected:

		// Protected data

		//- Number of spaces per indent level
		static const unsigned short indentSize_ = 4;

		//- Indentation of the entry from the start of the keyword
		static const unsigned short entryIndentation_ = 16;

		//- Current indent level
		unsigned short indentLevel_;

	public:

		//- Set stream status
		Ostream
		(
			streamFormat format = ASCII,
			versionNumber version = currentVersion,
			compressionType compression = UNCOMPRESSED
		)
			: IOstream(format, version, compression)
			, indentLevel_(0)
		{}


		//- Destructor
		virtual ~Ostream()
		{}

		// Member functions

		// Write functions

		//- Write next token to stream
		virtual Ostream& write(const token&) = 0;

		//- Write character
		virtual Ostream& write(const char) = 0;

		//- Write character string
		virtual Ostream& write(const char*) = 0;

		//- Write word
		virtual Ostream& write(const word&) = 0;

		//- Write keyType
		virtual Ostream& write(const keyType&);

		//- Write string
		virtual Ostream& write(const string&) = 0;

		//- Write std::string surrounded by quotes.
		//  Optional write without quotes.
		virtual Ostream& writeQuoted
		(
			const std::string&,
			const bool quoted = true
		) = 0;

		//- Write label
		virtual Ostream& write(const label) = 0;

		//- Write floatScalar
		virtual Ostream& write(const floatScalar) = 0;

		//- Write doubleScalar
		virtual Ostream& write(const doubleScalar) = 0;

		//- Write doubleScalar
		virtual Ostream& write(const longDoubleScalar) = 0;

		//- Write binary block
		virtual Ostream& write(const char*, std::streamsize) = 0;

		//- Add indentation characters
		virtual void indent() = 0;

		//- Return indent level
		unsigned short indentLevel() const
		{
			return indentLevel_;
		}

		//- Access to indent level
		unsigned short& indentLevel()
		{
			return indentLevel_;
		}

		//- Incrememt the indent level
		void incrIndent()
		{
			indentLevel_++;
		}

		//- Decrememt the indent level
		void decrIndent();

		//- Write the keyword followed by an appropriate indentation
		Ostream& writeKeyword(const keyType&);


		// Stream state functions

		//- Flush stream
		virtual void flush() = 0;

		//- Add newline and flush stream
		virtual void endl() = 0;

		//- Get width of output field
		virtual int width() const = 0;

		//- Set width of output field (and return old width)
		virtual int width(const int w) = 0;

		//- Get precision of output field
		virtual int precision() const = 0;

		//- Set precision of output field (and return old precision)
		virtual int precision(const int p) = 0;


		// Member operators

		//- Return a non-const reference to const Ostream
		//  Needed for write functions where the stream argument is temporary:
		//  e.g. thing thisThing(OFstream("thingFileName")());
		Ostream& operator()() const
		{
			return const_cast<Ostream&>(*this);
		}
	};

	typedef Ostream& (*OstreamManip)(Ostream&);

	//- operator<< handling for manipulators without arguments
	inline Ostream& operator<<(Ostream& os, OstreamManip f)
	{
		return f(os);
	}

	//- operator<< handling for manipulators without arguments
	inline Ostream& operator<<(Ostream& os, IOstreamManip f)
	{
		f(os);
		return os;
	}


	//- Indent stream
	inline Ostream& indent(Ostream& os)
	{
		os.indent();
		return os;
	}

	//- Increment the indent level
	inline Ostream& incrIndent(Ostream& os)
	{
		os.incrIndent();
		return os;
	}

	//- Decrement the indent level
	inline Ostream& decrIndent(Ostream& os)
	{
		os.decrIndent();
		return os;
	}


	//- Flush stream
	inline Ostream& flush(Ostream& os)
	{
		os.flush();
		return os;
	}


	//- Add newline and flush stream
	inline Ostream& endl(Ostream& os)
	{
		os.endl();
		return os;
	}


	// Useful aliases for tab and newline characters
	static const char tab = '\t';
	static const char nl = '\n';
}

#endif // !_Ostream_Header
