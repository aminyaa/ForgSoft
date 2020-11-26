#pragma once
#ifndef _label_Header
#define _label_Header

#include <climits>
#include <cstdlib>

#if TONB_LABEL64
#    define TONB_LABEL_MAX 9000000000000000000
#else
#    define TONB_LABEL_MAX 2000000000
#endif

#if INT_MAX > TONB_LABEL_MAX

// Define label as an int

# undef  TONB_LABEL_MAX
# define TONB_LABEL_MAX INT_MAX

#include <int.hxx>
#include <long.hxx>
#include <longLong.hxx>

namespace tnbLib
{

	typedef int label;

	static const label labelMin = INT_MIN;
	static const label labelMax = INT_MAX;

	inline label readLabel(Istream& is)
	{
		return readInt(is);
	}
}

#elif LONG_MAX > TONB_LABEL_MAX

# undef  TONB_LABEL_MAX
# define TONB_LABEL_MAX LONG_MAX

#include <int.hxx>
#include <long.hxx>

namespace tnbLib
{

	typedef long label;

	static const label labelMin = LONG_MIN;
	static const label labelMax = LONG_MAX;

	inline label readLabel(Istream& is)
	{
		return readLong(is);
	}
}

#elif LLONG_MAX > TONB_LABEL_MAX

// Define label as a long long

# undef  TONB_LABEL_MAX
# define TONB_LABEL_MAX LLONG_MAX

#include <int.hxx>
#include <long.hxx>
#include <longLong.hxx>

namespace tnbLib
{

	typedef long long label;

	static const label labelMin = LLONG_MIN;
	static const label labelMax = LLONG_MAX;

	inline label readLabel(Istream& is)
	{
		return readLongLong(is);
	}
}

#else

#error "Undefined size for label in label.H"

#endif // INT_MAX > TONB_LABEL_MAX

#include <pTraits.hxx>
#include <direction.hxx>

namespace tnbLib
{

	//- template specialization for pTraits<label>
	template<>
	class pTraits<label>
	{
		label p_;

	public:

		//- Component type
		typedef label cmptType;

		// Member constants

		enum
		{
			dim = 3,         // Dimensionality of space
			rank = 0,        // Rank of label is 0
			nComponents = 1  // Number of components in label is 1
		};


		// Static data members

		static const char* const typeName;
		static const char* componentNames[];
		static const label zero;
		static const label one;
		static const label min;
		static const label max;


		// Constructors

			//- Construct from label
		pTraits(const label l)
		{
			p_ = l;
		}

		//- Construct from Istream
		pTraits(Istream&);


		// Member Functions

		operator label() const
		{
			return p_;
		}

		operator label&()
		{
			return p_;
		}
	};

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

//- Raise one label to the power of another
	label pow(label a, label b);

	//- Evaluate n! : n <= 12
	label factorial(label n);


#define MAXMIN(retType, type1, type2)              \
                                                   \
inline retType max(const type1 s1, const type2 s2) \
{                                                  \
    return (s1 > s2)? s1: s2;                      \
}                                                  \
                                                   \
inline retType min(const type1 s1, const type2 s2) \
{                                                  \
    return (s1 < s2)? s1: s2;                      \
}


	MAXMIN(char, char, char)
		MAXMIN(short, short, short)
		MAXMIN(int, int, int)
		MAXMIN(long, long, long)
		MAXMIN(long long, long long, long long)

		MAXMIN(unsigned char, unsigned char, unsigned char)
		MAXMIN(unsigned short, unsigned short, unsigned short)
		MAXMIN(unsigned int, unsigned int, unsigned int)
		MAXMIN(unsigned long, unsigned long, unsigned long)
		MAXMIN(unsigned long long, unsigned long long, unsigned long long)

		MAXMIN(long, int, long)
		MAXMIN(long long, int, long long)
		MAXMIN(long long, long long, int)

		inline label& setComponent(label& l, const direction)
	{
		return l;
	}

	inline label component(const label l, const direction)
	{
		return l;
	}

	inline label mag(const label l)
	{
		return ::abs(l);
	}

	inline label sign(const label s)
	{
		return (s >= 0) ? 1 : -1;
	}

	inline label pos(const label s)
	{
		return (s >= 0) ? 1 : 0;
	}

	inline label neg(const label s)
	{
		return (s < 0) ? 1 : 0;
	}
}


#endif // !_label_Header
