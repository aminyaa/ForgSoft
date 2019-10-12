#pragma once
#ifndef _word_Header
#define _word_Header

#include <autString.hxx>

namespace AutLib
{

	class word
		: public string
	{

		// Private member functions

		//- Strip invalid characters from this word
		void stripInvalid();

	public:

		// Static data members

		static const char* const typeName;
		static int debug;
		static const word null;


		// Constructors

		//- Construct null
		word();

		//- Construct as copy
		word(const word&);

		//- Construct as copy of character array
		word(const char*, const bool doStripInvalid = true);

		//- Construct as copy with a maximum number of characters
		word
		(
			const char*,
			const size_type,
			const bool doStripInvalid
		);

		//- Construct as copy of string
		word(const string&, const bool doStripInvalid = true);

		//- Construct as copy of std::string
		word(const std::string&, const bool doStripInvalid = true);

		//- Construct from Istream
		word(Istream&);


		// Member functions

		//- Is this character valid for a word
		static bool valid(char);


		// Member operators

		// Assignment

		const word& operator=(const word&);
		const word& operator=(const string&);
		const word& operator=(const std::string&);
		const word& operator=(const char*);


		// Friend Operators

		friend word operator&(const word&, const word&);


		// IOstream operators

		friend Istream& operator>>(Istream&, word&);
		friend Ostream& operator<<(Ostream&, const word&);
	};
}

#include <wordI.hxx>

#endif // !_word_Header
