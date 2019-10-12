#pragma once
#ifndef _longDoubleScalar_Header
#define _longDoubleScalar_Header

#include <doubleFloat.hxx>
#include <pTraits.hxx>
#include <word.hxx>

namespace AutLib
{

	typedef long double longDoubleScalar;

	// Largest and smallest scalar values allowed in certain parts of the code.
	// (15 is the number of significant figures in an
	//  IEEE double precision number.  See limits.h or float.h)
	static const longDoubleScalar longDoubleScalarGREAT = 1.0e+15;
	static const longDoubleScalar longDoubleScalarVGREAT = 1.0e+300;
	static const longDoubleScalar longDoubleScalarROOTVGREAT = 1.0e+150;
	static const longDoubleScalar longDoubleScalarSMALL = 1.0e-15;
	static const longDoubleScalar longDoubleScalarVSMALL = 1.0e-300;
	static const longDoubleScalar longDoubleScalarROOTVSMALL = 1.0e-150;

	inline longDoubleScalar mag(const longDoubleScalar s)
	{
		return ::fabsl(s);
	}

	// template specialisation for pTraits<longDoubleScalar>
	template<>
	class pTraits<longDoubleScalar>
	{
		longDoubleScalar p_;

	public:

		//- Component type
		typedef longDoubleScalar cmptType;

		// Member constants

		enum
		{
			dim = 3,         // Dimensionality of space
			rank = 0,        // Rank of longDoubleScalar is 0
			nComponents = 1  // Number of components in longDoubleScalar is 1
		};


		// Static data members

		static const char* const typeName;
		static const char* componentNames[];
		static const longDoubleScalar zero;
		static const longDoubleScalar one;
		static const longDoubleScalar max;
		static const longDoubleScalar min;


		// Constructors

		//- Construct from longDoubleScalar
		pTraits(const longDoubleScalar s)
		{
			p_ = s;
		}

		//- Construct from Istream
		pTraits(Istream&);


		// Member operators

		operator longDoubleScalar() const
		{
			return p_;
		}

		operator longDoubleScalar&()
		{
			return p_;
		}
	};

	//- Return a string representation of a longDoubleScalar
	word name(const longDoubleScalar);

	inline longDoubleScalar& setComponent(longDoubleScalar& s, const direction)
	{
		return s;
	}

	inline longDoubleScalar component(const longDoubleScalar s, const direction)
	{
		return s;
	}

	inline longDoubleScalar sign(const longDoubleScalar s)
	{
		return (s >= 0) ? (longDoubleScalar)1 : -(longDoubleScalar)1;
	}

	inline longDoubleScalar pos(const longDoubleScalar s)
	{
		return (s >= 0) ? (longDoubleScalar)1 : (longDoubleScalar)0;
	}

	inline longDoubleScalar neg(const longDoubleScalar s)
	{
		return (s < 0) ? (longDoubleScalar)1 : (longDoubleScalar)0;
	}

	inline bool equal(const longDoubleScalar& s1, const longDoubleScalar& s2)
	{
		return mag(s1 - s2) <= longDoubleScalarVSMALL;
	}

	inline bool notEqual(const longDoubleScalar s1, const longDoubleScalar s2)
	{
		return mag(s1 - s2) > longDoubleScalarVSMALL;
	}

	inline longDoubleScalar limit(const longDoubleScalar s1, const longDoubleScalar s2)
	{
		return (mag(s1) < mag(s2)) ? s1 : (longDoubleScalar)0;
	}

	inline longDoubleScalar minMod(const longDoubleScalar s1, const longDoubleScalar s2)
	{
		return (mag(s1) < mag(s2)) ? s1 : s2;
	}

	inline longDoubleScalar magSqr(const longDoubleScalar s)
	{
		return s * s;
	}

	inline longDoubleScalar sqr(const longDoubleScalar s)
	{
		return s * s;
	}

	inline longDoubleScalar sqrtSumSqr(const longDoubleScalar a, const longDoubleScalar b)
	{
		longDoubleScalar maga = mag(a);
		longDoubleScalar magb = mag(b);

		if (maga > magb)
		{
			return maga * ::sqrt((longDoubleScalar)1.0 + sqr(magb / maga));
		}
		else
		{
			return magb < longDoubleScalarVSMALL ? (longDoubleScalar)0 : magb * ::sqrt((longDoubleScalar)1.0 + sqr(maga / magb));
		}
	}

	inline longDoubleScalar pow3(const longDoubleScalar s)
	{
		return s * sqr(s);
	}

	inline longDoubleScalar pow4(const longDoubleScalar s)
	{
		return sqr(sqr(s));
	}

	inline longDoubleScalar pow5(const longDoubleScalar s)
	{
		return s * pow4(s);
	}

	inline longDoubleScalar pow6(const longDoubleScalar s)
	{
		return pow3(sqr(s));
	}

	inline longDoubleScalar inv(const longDoubleScalar s)
	{
		return (longDoubleScalar)1.0 / s;
	}

	inline longDoubleScalar dot(const longDoubleScalar s1, const longDoubleScalar s2)
	{
		return s1 * s2;
	}

	inline longDoubleScalar cmptMultiply(const longDoubleScalar s1, const longDoubleScalar s2)
	{
		return s1 * s2;
	}

	inline longDoubleScalar cmptDivide(const longDoubleScalar s1, const longDoubleScalar s2)
	{
		return s1 / s2;
	}

	inline longDoubleScalar cmptSumMultiply(const longDoubleScalar s1, const longDoubleScalar s2)
	{
		return s1 * s2;
	}

	inline longDoubleScalar cmptMax(const longDoubleScalar s)
	{
		return s;
	}

	inline longDoubleScalar cmptMin(const longDoubleScalar s)
	{
		return s;
	}

	inline longDoubleScalar cmptAv(const longDoubleScalar s)
	{
		return s;
	}

	inline longDoubleScalar cmptMag(const longDoubleScalar s)
	{
		return mag(s);
	}


	inline longDoubleScalar cmptSign(const longDoubleScalar s)
	{
		return sign(s);
	}


	inline longDoubleScalar j0(const longDoubleScalar s)
	{
		return ::_j0(s);
	}

	inline longDoubleScalar j1(const longDoubleScalar s)
	{
		return ::_j1(s);
	}

	inline longDoubleScalar y0(const longDoubleScalar s)
	{
		return ::_y0(s);
	}

	inline longDoubleScalar y1(const longDoubleScalar s)
	{
		return ::_y1(s);
	}

	// Standard C++ transcendental functions
	inline longDoubleScalar sqrt(const longDoubleScalar s) { return ::sqrt(s); }

	inline longDoubleScalar cbrt(const longDoubleScalar s) { return ::cbrt(s); }

	inline longDoubleScalar exp(const longDoubleScalar s) { return ::exp(s); }

	inline longDoubleScalar log(const longDoubleScalar s) { return ::log(s); }

	inline longDoubleScalar log10(const longDoubleScalar s) { return ::log10(s); }

	inline longDoubleScalar sin(const longDoubleScalar s) { return ::sin(s); }

	inline longDoubleScalar cos(const longDoubleScalar s) { return ::cos(s); }

	inline longDoubleScalar tan(const longDoubleScalar s) { return ::tan(s); }

	inline longDoubleScalar asin(const longDoubleScalar s) { return ::asin(s); }

	inline longDoubleScalar acos(const longDoubleScalar s) { return ::acos(s); }

	inline longDoubleScalar atan(const longDoubleScalar s) { return ::atan(s); }

	inline longDoubleScalar sinh(const longDoubleScalar s) { return ::sinh(s); }

	inline longDoubleScalar cosh(const longDoubleScalar s) { return ::cosh(s); }

	inline longDoubleScalar tanh(const longDoubleScalar s) { return ::tanh(s); }

	inline longDoubleScalar asinh(const longDoubleScalar s) { return ::asinh(s); }

	inline longDoubleScalar acosh(const longDoubleScalar s) { return ::acosh(s); }

	inline longDoubleScalar atanh(const longDoubleScalar s) { return ::atanh(s); }

	// Standard ANSI-C (but not in <cmath>) transcendental functions

	inline longDoubleScalar erf(const longDoubleScalar s) { return ::erf(s); }

	inline longDoubleScalar erfc(const longDoubleScalar s) { return ::erfc(s); }

	inline longDoubleScalar lgamma(const longDoubleScalar s) { return ::lgamma(s); }

	// Stabilisation around zero for division
	inline longDoubleScalar stabilise(const longDoubleScalar& s, const longDoubleScalar& theSmall)
	{
		if (s >= 0)
		{
			return s + theSmall;
		}
		else
		{
			return s - theSmall;
		}
	}


	inline longDoubleScalar cmptStabilise
	(
		const longDoubleScalar& s,
		const longDoubleScalar& theSmall,
		const longDoubleScalar& value
	)
	{
		if (mag(s) < theSmall)
		{
			return sign(s)*value;
		}
		else
		{
			return s;
		}
	}

	longDoubleScalar readLongDoubleScalar(Istream&);

	Istream& operator>>(Istream&, longDoubleScalar&);
	Ostream& operator<<(Ostream&, const longDoubleScalar);

	inline longDoubleScalar hypot(const longDoubleScalar x, const longDoubleScalar y)
	{
		return ::hypot(x, y);
	}

	inline longDoubleScalar atan2(const longDoubleScalar y, const longDoubleScalar x)
	{
		return ::atan2(y, x);
	}

	inline longDoubleScalar jn(const int n, const longDoubleScalar s)
	{
		return ::_jn(n, s);
	}

	inline longDoubleScalar yn(const int n, const longDoubleScalar s)
	{
		return ::_yn(n, s);
	}
}

#endif // !_longDoubleScalar_Header
