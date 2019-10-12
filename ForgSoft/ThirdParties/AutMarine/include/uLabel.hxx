#pragma once
#ifndef _uLabel_Header
#define _uLabel_Header

#include <climits>

#if AUT_LABEL64
#    define AUT_ULABEL_MAX 18000000000000000000
#else
#    define AUT_ULABEL_MAX 4000000000
#endif

#if UINT_MAX > AUT_ULABEL_MAX

// Define uLabel as an unsigned int

# undef  AUT_ULABEL_MAX
# define AUT_ULABEL_MAX UINT_MAX

# include <uint.hxx>

namespace AutLib
{
	typedef unsigned int uLabel;

	static const uLabel uLabelMin = 0;
	static const uLabel uLabelMax = UINT_MAX;

	inline uLabel readULabel(Istream& is)
	{
		return readUint(is);
	}

} // End namespace AutLib


#elif ULONG_MAX > AUT_ULABEL_MAX

// Define uLabel as an unsigned long

# undef  AUT_ULABEL_MAX
# define AUT_ULABEL_MAX ULONG_MAX

# include <uint.hxx>
# include <ulong.hxx>

namespace AutLib
{
	typedef unsigned long uLabel;

	static const uLabel uLabelMin = 0;
	static const uLabel uLabelMax = ULONG_MAX;

	inline uLabel readULabel(Istream& is)
	{
		return readUlong(is);
	}

} // End namespace AutLib


#elif ULLONG_MAX > AUT_ULABEL_MAX

// Define uLabel as an unsigned long long

# undef  AUT_ULABEL_MAX

# error "Not implemented yet"

#endif

#include <pTraits.hxx>
#include <direction.hxx>

namespace AutLib
{

	//- template specialization for pTraits<uLabel>
	template<>
	class pTraits<uLabel>
	{
		uLabel p_;

	public:

		//- Component type
		typedef uLabel cmptType;

		// Member constants

		enum
		{
			dim = 3,         // Dimensionality of space
			rank = 0,        // Rank of uLabel is 0
			nComponents = 1  // Number of components in uLabel is 1
		};


		// Static data members

		static const char* const typeName;
		static const char* componentNames[];
		static const uLabel zero;
		static const uLabel one;
		static const uLabel max;
		static const uLabel min;


		// Constructors

		//- Construct from uLabel
		pTraits(const uLabel ul)
		{
			p_ = ul;
		}

		//- Construct from Istream
		pTraits(Istream&);


		// Member Functions

		operator uLabel() const
		{
			return p_;
		}

		operator uLabel&()
		{
			return p_;
		}
	};

	inline uLabel& setComponent(uLabel& l, const direction)
	{
		return l;
	}

	inline uLabel component(const uLabel l, const direction)
	{
		return l;
	}
}

#endif // !_uLabel_Header
