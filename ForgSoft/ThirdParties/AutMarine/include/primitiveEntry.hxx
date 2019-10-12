#pragma once
#ifndef _primitiveEntry_Header
#define _primitiveEntry_Header

#include <entry.hxx>
#include <ITstream.hxx>

namespace AutLib
{

	class primitiveEntry
		: public entry
		, public ITstream
	{
		// Private member functions

		//- Append the given token to this entry
		void append
		(
			const token& currToken,
			const dictionary&,
			Istream&
		);

		//- Append the given tokens starting at the current tokenIndex
		void append(const tokenList&);

		//- Expand the given variable (keyword starts with $)
		bool expandVariable(const word&, const dictionary&);

		//- Expand the given function (keyword starts with #)
		bool expandFunction
		(
			const word&,
			const dictionary&,
			Istream&
		);

		//- Read the complete entry from the given stream
		void readEntry(const dictionary&, Istream&);

		//- Insert the given tokens at token posI
		void insert(const tokenList&, const label posI);


	public:

		// Constructors

		//- Construct from keyword and a Istream
		primitiveEntry(const keyType&, Istream&);

		//- Construct from keyword, parent dictionary and Istream
		primitiveEntry(const keyType&, const dictionary& parentDict, Istream&);

		//- Construct from keyword and a ITstream
		primitiveEntry(const keyType&, const ITstream&);

		//- Construct from keyword and a token
		primitiveEntry(const keyType&, const token&);

		//- Construct from keyword and a tokenList
		primitiveEntry(const keyType&, const tokenList&);

		//- Construct from keyword and a T
		template<class T>
		primitiveEntry(const keyType&, const T&);

		autoPtr<entry> clone(const dictionary&) const
		{
			return autoPtr<entry>(new primitiveEntry(*this));
		}


		// Member functions

		//- Return the dictionary name
		const fileName& name() const
		{
			return ITstream::name();
		}

		//- Return the dictionary name
		fileName& name()
		{
			return ITstream::name();
		}

		//- Return line number of first token in dictionary
		label startLineNumber() const;

		//- Return line number of last token in dictionary
		label endLineNumber() const;

		//- Return true because this entry is a stream
		bool isStream() const
		{
			return true;
		}

		//- Return token stream if this entry is a primitive entry
		ITstream& stream() const;

		//- This entry is not a dictionary,
		//  calling this function generates a FatalError
		const dictionary& dict() const;

		//- This entry is not a dictionary,
		//  calling this function generates a FatalError
		dictionary& dict();

		//- Read tokens from the given stream
		bool read(const dictionary&, Istream&);

		// Write
		void write(Ostream&) const;

		//- Return info proxy.
		//  Used to print token information to a stream
		InfoProxy<primitiveEntry> info() const
		{
			return *this;
		}
	};

	Ostream& operator<<(Ostream&, const InfoProxy<primitiveEntry>&);
}

#include <primitiveEntryI.hxx>

#endif // !_primitiveEntry_Header
