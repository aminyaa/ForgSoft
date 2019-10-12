#pragma once
#ifndef _bool_Header
#define _bool_Header

#include <pTraits.hxx>

namespace AutLib
{

	class Istream;
	class Ostream;

	Istream& operator>>(Istream&, bool&);
	Ostream& operator<<(Ostream&, const bool);

	bool readBool(Istream&);

	// template specialisation for pTraits<bool>
	template<>
	class pTraits<bool>
	{
		bool p_;

	public:

		//- Component type
		typedef bool cmptType;

		// Member constants

		enum
		{
			dim = 3,         // Dimensionality of space
			rank = 0,        // Rank of bool is 0
			nComponents = 1  // Number of components in bool is 1
		};


		// Static data members

		static const char* const typeName;
		static const char* componentNames[];
		static const bool zero;
		static const bool one;


		// Constructors

		//- Construct from bool
		pTraits(const bool b)
		{
			p_ = b;
		}

		//- Construct from Istream
		pTraits(Istream&);


		// Member Functions

		operator bool() const
		{
			return p_;
		}

		operator bool&()
		{
			return p_;
		}
	};
}

#endif // !_bool_Header
