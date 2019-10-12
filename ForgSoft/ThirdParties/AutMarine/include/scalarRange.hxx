#pragma once
#ifndef _scalarRange_Header
#define _scalarRange_Header

#include <debugSwitch.hxx>

namespace AutLib
{

	class scalarRange
	{
		//- Enumeration defining the types of token
		enum rangeType
		{
			EMPTY = 0,
			EXACT,
			LOWER,
			UPPER,
			RANGE
		};


		// Private data

		enum rangeType type_;
		scalar value_;
		scalar value2_;


	public:

		static debug::debugSwitch debug;


		// Constructors

		//- Construct Null
		scalarRange();

		//- Construct a Range
		scalarRange(const scalar& lower, const scalar& upper);

		//- Construct from Istream.
		//  Since commas can be used as list delimiters,
		//  leading and trailing commas are ignored.
		scalarRange(Istream&);


		// Member Functions

		//- Is the range non-empty?
		bool isDefined() const;

		//- Is the range 'EXACT'?
		bool isExact() const;

		//- The value constituting an 'EXACT' match
		//  or the values for 'UPPER' or 'LOWER' limits
		scalar value() const;

		//- The lower limit
		scalar lower() const;

		//- The upper limit
		scalar upper() const;

		//- Return true if the value is within the range
		bool selected(const scalar&) const;


		// Member Operators

		bool operator==(const scalarRange&) const;
		bool operator!=(const scalarRange&) const;


		// IOstream Operators

		friend Istream& operator>>(Istream&, scalarRange&);
		friend Ostream& operator<<(Ostream&, const scalarRange&);
	};
}

#endif // !_scalarRange_Header
