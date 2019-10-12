#pragma once
#ifndef _Switch_Header
#define _Switch_Header

#include <word.hxx>

namespace AutLib
{
	// Forward declaration of friend functions and operators
	class dictionary;

	class Switch
	{

		// Private data

		//- The logic and enumerated text representation stored as a single byte
		unsigned char switch_;

	public:

		// Public data types

		//- The various text representations for a switch value.
		//  These also correspond to the entries in names.
		enum switchType
		{
			FALSE = 0, TRUE = 1,
			OFF = 2, ON = 3,
			NO = 4, YES = 5,
			NO_1 = 6, YES_1 = 7,
			FALSE_1 = 8, TRUE_1 = 9,
			NONE = 10, PLACEHOLDER = 11,
			INVALID
		};


		// Static data members

		//- The set of names corresponding to the switchType enumeration
		//  Includes an extra entry for "invalid".
		static const char* names[INVALID + 1];

	private:

		// Static Member Functions

		//- Return a switchType representation of a word
		static switchType asEnum(const std::string&, const bool allowInvalid);

	public:

		// Constructors

		//- Construct null as false
		Switch()
			: switch_(Switch::FALSE)
		{}

		//- Construct from enumerated value
		Switch(const switchType sw)
			: switch_(sw)
		{}

		//- Construct from bool
		Switch(const bool b)
			: switch_(b ? Switch::TRUE : Switch::FALSE)
		{}

		//- Construct from integer values (treats integer as bool value)
		Switch(const int i)
			: switch_(i ? Switch::TRUE : Switch::FALSE)
		{}

		//- Construct from std::string, string, word
		//  Optionally allow bad words, and catch the error elsewhere
		Switch(const std::string& str, const bool allowInvalid = false)
			: switch_(asEnum(str, allowInvalid))
		{}

		//- Construct from character array
		//  Optionally allow bad words, and catch the error elsewhere
		Switch(const char* str, const bool allowInvalid = false)
			: switch_(asEnum(std::string(str), allowInvalid))
		{}

		//- Construct from Istream
		Switch(Istream& is);

		//- Construct from dictionary, supplying default value so that if the
		//  value is not found, it is added into the dictionary.
		static Switch lookupOrAddToDict
		(
			const word&,
			dictionary&,
			const Switch& defaultValue = false
		);


		// Member Functions

		//- Return true if the Switch has a valid value
		bool valid() const;

		//- Return a text representation of the Switch
		const char* asText() const;

		//- Update the value of the Switch if it is found in the dictionary
		bool readIfPresent(const word&, const dictionary&);


		// Member Operators

		//- Conversion to bool
		operator bool() const
		{
			return (switch_ & 0x1);
		}

		//- Assignment from enumerated value
		const Switch& operator=(const switchType sw)
		{
			switch_ = sw;
			return *this;
		}

		//- Assignment from bool
		const Switch& operator=(const bool b)
		{
			switch_ = (b ? Switch::TRUE : Switch::FALSE);
			return *this;
		}


		// IOstream Operators

		friend Istream& operator>>(Istream&, Switch&);
		friend Ostream& operator<<(Ostream&, const Switch&);
	};
}

#endif // !_Switch_Header
