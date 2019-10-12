#pragma once
#ifndef _instant_Header
#define _instant_Header

#include <scalar.hxx>

namespace AutLib
{

	class instant
	{

		// Private data

		scalar value_;
		word name_;

	public:

		// Public classes

		//- Less function class used in sorting instants
		class less
		{
		public:

			bool operator()(const instant& a, const instant& b) const
			{
				return a.value() < b.value();
			}
		};


		// Static data members

		static const char* const typeName;


		// Constructors

		//- Construct null
		instant();

		//- Construct from components
		instant(const scalar, const word&);

		//- Construct from time value
		instant(const scalar);

		//- Construct from word
		instant(const word&);


		// Member Functions

		// Access

		//- Value (const access)
		scalar value() const
		{
			return value_;
		}

		//- Value (non-const access)
		scalar& value()
		{
			return value_;
		}

		//- Name (const access)
		const word& name() const
		{
			return name_;
		}

		//- Name (non-const access)
		word& name()
		{
			return name_;
		}


		// Friend Operators

		friend bool operator==(const instant&, const instant&);
		friend bool operator!=(const instant&, const instant&);


		// IOstream Operators

		friend Istream& operator>>(Istream&, instant&);
		friend Ostream& operator<<(Ostream&, const instant&);
	};
}

#endif // !_instant_Header
