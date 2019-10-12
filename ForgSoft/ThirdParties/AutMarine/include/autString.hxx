#pragma once
#ifndef _autString_Header
#define _autString_Header

#include <char.hxx>
#include <Hasher.hxx>

#include <string>

namespace AutLib
{

	class string
		: public std::string
	{

	public:

		// Static data members

		static const char* const typeName;
		static int debug;
		static const string null;

		//- Hashing function class, shared by all the derived classes
		class hash
		{
		public:
			hash()
			{}

			unsigned operator()(const string&, unsigned seed = 0) const;
		};

		//- Construct null
		string();

		//- Construct from std::string
		string(const std::string&);

		//- Construct as copy of character array
		string(const char*);

		//- Construct as copy of specified number of characters
		string(const char*, const size_type);

		//- Construct from a single character
		string(const char);

		//- Construct from Istream
		string(Istream&);

		//- Count and return the number of a given character in the string
		size_type count(const char) const;

		//- Is this string type valid?
		template<class String>
		static bool valid(const string&);

		//- Does this string have particular meta-characters?
		//  The meta characters can be optionally quoted.
		template<class String>
		static bool meta(const string&, const char quote = '\\');

		//- Strip invalid characters from the given string
		template<class String>
		static bool stripInvalid(string&);

		//- Return a valid String from the given string
		template<class String>
		static String validate(const string&);

		//- Return a String with quoted meta-characters from the given string
		template<class String>
		static string quotemeta(const string&, const char quote = '\\');

		//- Avoid masking the normal std::string replace
		using std::string::replace;

		//- Replace first occurence of sub-string oldStr with newStr
		//  starting at start
		string& replace
		(
			const string& oldStr,
			const string& newStr,
			size_type start = 0
		);

		//- Replace all occurences of sub-string oldStr with newStr
		//  starting at start
		string& replaceAll
		(
			const string& oldStr,
			const string& newStr,
			size_type start = 0
		);

		//- Expand initial tildes and all occurences of environment variables
		//  Expansion includes:
		//  -# environment variables
		//     - "$VAR", "${VAR}"
		//  -# current directory
		//     - leading "./" : the current directory
		//  -# tilde expansion
		//     - leading "~/" : home directory
		//     - leading "~user" : home directory for specified user
		//     - leading "~foam" : site/user FOAM configuration directory
		//
		//  @sa
		//  AutLib::findEtcFile
		string& expand();

		//- Remove repeated characters returning true if string changed
		bool removeRepeated(const char);

		//- Return string with repeated characters removed
		string removeRepeated(const char) const;

		//- Remove trailing character returning true if string changed
		bool removeTrailing(const char);

		//- Return string with trailing character removed
		string removeTrailing(const char) const;


		// Member Operators

		//- Return the sub-string from the i-th character for @a n characters
		string operator()
			(
				const size_type i,
				const size_type n
				) const;

		//- Return the sub-string from the first character for @a n characters
		string operator()
			(
				const size_type n
				) const;


		// IOstream Operators

		friend Istream& operator>>(Istream&, string&);
		friend Ostream& operator<<(Ostream&, const string&);
	};

	Ostream& operator<<(Ostream&, const std::string&);
}

#include <autStringI.hxx>

#endif // !_autString_Header
