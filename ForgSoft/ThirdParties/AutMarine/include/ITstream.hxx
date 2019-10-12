#pragma once
#ifndef _ITstream_Header
#define _ITstream_Header

#include <Istream.hxx>
#include <tokenList.hxx>

namespace AutLib
{

	class ITstream
		: public Istream
		, public tokenList
	{
		// Private data

		//- Name of ITstream
		fileName name_;

		//- Index of token currently being read
		label tokenIndex_;


	public:

		// Constructors

		//- Construct from components
		ITstream
		(
			const string& name,
			const tokenList& tokens,
			streamFormat format = ASCII,
			versionNumber version = currentVersion
		)
			: Istream(format, version)
			, tokenList(tokens)
			, name_(name)
			, tokenIndex_(0)
		{
			setOpened();
			setGood();
		}


		//- Construct as copy
		ITstream(const ITstream& its)
			: Istream(ASCII, currentVersion)
			, tokenList(its)
			, name_(its.name_)
			, tokenIndex_(0)
		{
			setOpened();
			setGood();
		}


		// Destructor

		virtual ~ITstream()
		{}

		// Member functions

		// Inquiry

		//- Return the name of the stream
		const fileName& name() const
		{
			return name_;
		}

		//- Return non-const access to the name of the stream
		fileName& name()
		{
			return name_;
		}

		//- Return the current token index
		label tokenIndex() const
		{
			return tokenIndex_;
		}

		//- Return non-const access to the current token index
		label& tokenIndex()
		{
			return tokenIndex_;
		}

		//- Return the number of remaining tokens
		label nRemainingTokens() const
		{
			return size() - tokenIndex_;
		}

		//- Return flags of output stream
		ios_base::fmtflags flags() const
		{
			return ios_base::fmtflags(0);
		}


		// Read functions

		//- Return next token from stream
		virtual Istream& read(token&);

		//- Read a character
		virtual Istream& read(char&);

		//- Read a word
		virtual Istream& read(word&);

		// Read a string (including enclosing double-quotes)
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

#endif // !_ITstream_Header
