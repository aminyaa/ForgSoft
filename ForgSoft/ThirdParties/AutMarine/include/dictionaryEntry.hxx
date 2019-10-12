#pragma once
#ifndef _dictionaryEntry_Header
#define _dictionaryEntry_Header

#include <dictionary.hxx>
#include <InfoProxy.hxx>

namespace AutLib
{

	class dictionaryEntry
		: public entry
		, public dictionary
	{
		// Private member functions

		void readData(Istream&);

		//- Dissallow bitwise copy
		dictionaryEntry(const dictionary&) = delete;


	public:

		// Constructors

		//- Construct from the parent dictionary and Istream
		dictionaryEntry(const dictionary& parentDict, Istream&);

		//- Construct from the keyword, parent dictionary and a Istream
		dictionaryEntry
		(
			const keyType&,
			const dictionary& parentDict,
			Istream&
		);

		//- Construct from the keyword, parent dictionary and a dictionary
		dictionaryEntry
		(
			const keyType&,
			const dictionary& parentDict,
			const dictionary& dict
		);

		//- Construct as copy for the given parentDict
		dictionaryEntry
		(
			const dictionary& parentDict,
			const dictionaryEntry&
		);

		autoPtr<entry> clone(const dictionary& parentDict) const
		{
			return autoPtr<entry>(new dictionaryEntry(parentDict, *this));
		}


		// Member functions

		//- Return the dictionary name
		const fileName& name() const
		{
			return dictionary::name();
		}

		//- Return the dictionary name
		fileName& name()
		{
			return dictionary::name();
		}

		//- Return line number of first token in dictionary
		label startLineNumber() const;

		//- Return line number of last token in dictionary
		label endLineNumber() const;

		//- This entry is not a primitive,
		//  calling this function generates a FatalError
		ITstream& stream() const;

		//- Return true because this entry is a dictionary
		bool isDict() const
		{
			return true;
		}

		//- Return dictionary
		const dictionary& dict() const;

		//- Return non-const access to dictionary
		dictionary& dict();

		// Write
		void write(Ostream&) const;

		//- Return info proxy.
		//  Used to print token information to a stream
		InfoProxy<dictionaryEntry> info() const
		{
			return *this;
		}


		// Ostream operator

		friend Ostream& operator<<(Ostream&, const dictionaryEntry&);
	};


	Ostream& operator<<(Ostream&, const InfoProxy<dictionaryEntry>&);
}

#endif // !_dictionaryEntry_Header
