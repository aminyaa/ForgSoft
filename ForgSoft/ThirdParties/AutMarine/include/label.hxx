#pragma once
#ifndef _label_Header
#define _label_Header

#include <climits>
#include <cstdlib>

#if AUT_LABEL64
#    define AUT_LABEL_MAX 9000000000000000000
#else
#    define AUT_LABEL_MAX 2000000000
#endif

#if INT_MAX > AUT_LABEL_MAX

// Define label as an int

# undef  AUT_LABEL_MAX
# define AUT_LABEL_MAX INT_MAX

# include <int.hxx>
# include <long.hxx>
# include <longLong.hxx>

namespace AutLib
{
	typedef int label;

	static const label labelMin = INT_MIN;
	static const label labelMax = INT_MAX;

	inline label readLabel(Istream& is)
	{
		return readInt(is);
	}

} // End namespace AutLib


#elif LONG_MAX > AUT_LABEL_MAX
// Define label as a long

# undef  AUT_LABEL_MAX
# define AUT_LABEL_MAX LONG_MAX

# include <int.hxx>
# include <long.hxx>

namespace AutLib
{
	typedef long label;

	static const label labelMin = LONG_MIN;
	static const label labelMax = LONG_MAX;

	inline label readLabel(Istream& is)
	{
		return readLong(is);
	}

} // End namespace AutLib


#elif LLONG_MAX > AUT_LABEL_MAX

// Define label as a long long

# undef  AUT_LABEL_MAX
# define AUT_LABEL_MAX LLONG_MAX

# include <int.hxx>
# include <long.hxx>
# include <longLong.hxx>

namespace AutLib
{
	typedef long long label;

	static const label labelMin = LLONG_MIN;
	static const label labelMax = LLONG_MAX;

	inline label readLabel(Istream& is)
	{
		return readLongLong(is);
	}

} // End namespace AutLib

#else

#error "Undefined size for label in label.hxx>

#endif

#include <pTraits.hxx>
#include <direction.hxx>

namespace AutLib
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

	//- Raise one label to the power of another
	label pow(label a, label b);

	//- Evaluate n! : n <= 12
	label factorial(label n);

	inline char max(const char s1, const char s2) { return (s1 > s2) ? s1 : s2; }

	inline char min(const char s1, const char s2) { return (s1 < s2) ? s1 : s2; }

	inline short max(const short s1, const short s2) { return (s1 > s2) ? s1 : s2; }

	inline short min(const short s1, const short s2) { return (s1 < s2) ? s1 : s2; }

	inline int max(const int s1, const int s2) { return (s1 > s2) ? s1 : s2; }

	inline int min(const int s1, const int s2) { return (s1 < s2) ? s1 : s2; }

	inline long max(const long s1, const long s2) { return (s1 > s2) ? s1 : s2; }

	inline long min(const long s1, const long s2) { return (s1 < s2) ? s1 : s2; }

	inline long long max(const long long s1, const long long s2) { return (s1 > s2) ? s1 : s2; }

	inline long long min(const long long s1, const long long s2) { return (s1 < s2) ? s1 : s2; }


	inline unsigned char max(const unsigned char s1, const unsigned char s2) { return (s1 > s2) ? s1 : s2; }

	inline unsigned char min(const unsigned char s1, const unsigned char s2) { return (s1 < s2) ? s1 : s2; }

	inline unsigned short max(const unsigned short s1, const unsigned short s2) { return (s1 > s2) ? s1 : s2; }

	inline unsigned short min(const unsigned short s1, const unsigned short s2) { return (s1 < s2) ? s1 : s2; }

	inline unsigned int max(const unsigned int s1, const unsigned int s2) { return (s1 > s2) ? s1 : s2; }

	inline unsigned int min(const unsigned int s1, const unsigned int s2) { return (s1 < s2) ? s1 : s2; }

	inline unsigned long max(const unsigned long s1, const unsigned long s2) { return (s1 > s2) ? s1 : s2; }

	inline unsigned long min(const unsigned long s1, const unsigned long s2) { return (s1 < s2) ? s1 : s2; }

	inline unsigned long long max(const unsigned long long s1, const unsigned long long s2) { return (s1 > s2) ? s1 : s2; }

	inline unsigned long long min(const unsigned long long s1, const unsigned long long s2) { return (s1 < s2) ? s1 : s2; }


	inline long max(const int s1, const long s2) { return (s1 > s2) ? s1 : s2; }

	inline long min(const int s1, const long s2) { return (s1 < s2) ? s1 : s2; }

	inline long long max(const int s1, const long long s2) { return (s1 > s2) ? s1 : s2; }

	inline long long min(const int s1, const long long s2) { return (s1 < s2) ? s1 : s2; }

	inline long long max(const long long s1, const int s2) { return (s1 > s2) ? s1 : s2; }

	inline long long min(const long long s1, const int s2) { return (s1 < s2) ? s1 : s2; }

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
