#pragma once
#ifndef _fileName_Header
#define _fileName_Header

#include <debugSwitch.hxx>
#include <word.hxx>

namespace AutLib
{
	template<class T> class List;
	typedef List<word> wordList;

	class fileName
		: public string
	{

		// Private member functions

		//- Strip invalid characters
		void stripInvalid();

	public:

		//- Enumerations to handle file types and modes.
		enum Type
		{
			UNDEFINED,
			FILE,
			DIRECTORY,
			LINK
		};


		// Static data members

		static const char* const typeName;
		static debug::debugSwitch debug;
		static const fileName null;


		// Constructors

		//- Construct null
		fileName();

		//- Construct as copy
		fileName(const fileName&);

		//- Construct as copy of word
		fileName(const word&);

		//- Construct as copy of string
		fileName(const string&);

		//- Construct as copy of std::string
		fileName(const std::string&);

		//- Construct as copy of character array
		fileName(const char*);

		//- Construct by concatenating elements of wordList separated by '/'
		explicit fileName(const wordList&);

		//- Construct from Istream
		fileName(Istream&);


		// Member functions

		//- Is this character valid for a fileName?
		static bool valid(char);

		//- Cleanup file name
		//  eg, remove repeated slashes, etc.
		bool clean();

		//- Cleanup file name
		//  eg, remove repeated slashes, etc.
		fileName clean() const;

		// Interogation

		//- Return the file type: FILE, DIRECTORY or UNDEFINED
		Type type() const;

		// Decomposition

		//- Return file name (part beyond last /)
		word name() const;

		//- Return directory path name (part before last /)
		fileName path() const;

		//- Return file name without extension (part before last .)
		fileName lessExt() const;

		//- Return file name extension (part after last .)
		word ext() const;

		//- Return path components as wordList
		wordList components(const char delimiter = '/') const;

		//- Return a single component of the path
		word component(const size_type, const char delimiter = '/') const;

		// Member operators

		// Assignment

		const fileName& operator=(const fileName&);
		const fileName& operator=(const word&);
		const fileName& operator=(const string&);
		const fileName& operator=(const std::string&);
		const fileName& operator=(const char*);


		// IOstream operators

		friend Istream& operator>>(Istream&, fileName&);
		friend Ostream& operator<<(Ostream&, const fileName&);
	};

	//- Assemble words and fileNames as pathnames by adding a '/' separator
	fileName operator/(const string&, const string&);
}

#include <fileNameI.hxx>

#endif // !_fileName_Header
