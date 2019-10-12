#pragma once
#ifndef _keyType_Header
#define _keyType_Header

#include <word.hxx>

namespace AutLib
{

	class keyType
		: public word
	{

		// Private member data

		//- Is the keyType a pattern (regular expression)
		bool isPattern_;

		// Private Member Functions

		//- Disallow assignments where we cannot determine string/word type
		void operator=(const std::string&) = delete;

	public:

		//- Construct null
		keyType();

		//- Construct as copy
		keyType(const keyType&);

		//- Construct as copy of word
		keyType(const word&);

		//- Construct as copy of string. Expect it to be regular expression.
		keyType(const string&);

		//- Construct as copy of character array
		keyType(const char*);

		//- Construct as copy of std::string
		keyType(const std::string&, const bool isPattern);

		//- Construct from Istream
		keyType(Istream&);


		// Member functions

		//- Should be treated as a match rather than a literal string
		bool isPattern() const;

		// Member operators

		// Assignment

		const keyType& operator=(const keyType&);
		const keyType& operator=(const word&);

		//- Assign from regular expression.
		const keyType& operator=(const string&);
		const keyType& operator=(const char*);


		// IOstream operators

		friend Istream& operator>>(Istream&, keyType&);
		friend Ostream& operator<<(Ostream&, const keyType&);
	};
}

#include <keyTypeI.hxx>

#endif // !_keyType_Header
