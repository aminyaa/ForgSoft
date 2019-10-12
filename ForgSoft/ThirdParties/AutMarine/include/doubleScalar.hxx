#pragma once
#ifndef _doubleScalar_Header
#define _doubleScalar_Header

#include <doubleFloat.hxx>
#include <pTraits.hxx>
#include <word.hxx>

namespace AutLib
{

	typedef double doubleScalar;

	// Largest and smallest scalar values allowed in certain parts of the code.
	// (15 is the number of significant figures in an
	//  IEEE double precision number.  See limits.h or float.h)
	static const doubleScalar doubleScalarGREAT = (doubleScalar)1.0e+15;
	static const doubleScalar doubleScalarVGREAT = (doubleScalar)1.0e+300;
	static const doubleScalar doubleScalarROOTVGREAT = (doubleScalar)1.0e+150;
	static const doubleScalar doubleScalarSMALL = (doubleScalar)1.0e-15;
	static const doubleScalar doubleScalarVSMALL = (doubleScalar)1.0e-300;
	static const doubleScalar doubleScalarROOTVSMALL = (doubleScalar)1.0e-150;

	inline doubleScalar mag(const doubleScalar s)
	{
		return ::fabs(s);
	}

	// template specialisation for pTraits<doubleScalar>
	template<>
	class pTraits<doubleScalar>
	{
		doubleScalar p_;

	public:

		//- Component type
		typedef doubleScalar cmptType;

		// Member constants

		enum
		{
			dim = 3,         // Dimensionality of space
			rank = 0,        // Rank of doubleScalar is 0
			nComponents = 1  // Number of components in doubleScalar is 1
		};


		// Static data members

		static const char* const typeName;
		static const char* componentNames[];
		static const doubleScalar zero;
		static const doubleScalar one;
		static const doubleScalar max;
		static const doubleScalar min;


		// Constructors

		//- Construct from doubleScalar
		pTraits(const doubleScalar s)
		{
			p_ = s;
		}

		//- Construct from Istream
		pTraits(Istream&);


		// Member operators

		operator doubleScalar() const
		{
			return p_;
		}

		operator doubleScalar&()
		{
			return p_;
		}
	};

	//- Return a string representation of a doubleScalar
	word name(const doubleScalar);


	inline doubleScalar& setComponent(doubleScalar& s, const direction)
	{
		return s;
	}

	inline doubleScalar component(const doubleScalar s, const direction)
	{
		return s;
	}

	inline doubleScalar sign(const doubleScalar s)
	{
		return (s >= 0) ? (doubleScalar)1 : -(doubleScalar)1;
	}

	inline doubleScalar pos(const doubleScalar s)
	{
		return (s >= 0) ? (doubleScalar)1 : (doubleScalar)0;
	}

	inline doubleScalar neg(const doubleScalar s)
	{
		return (s < 0) ? (doubleScalar)1 : (doubleScalar)0;
	}

	inline bool equal(const doubleScalar& s1, const doubleScalar& s2)
	{
		return mag(s1 - s2) <= doubleScalarVSMALL;
	}

	inline bool notEqual(const doubleScalar s1, const doubleScalar s2)
	{
		return mag(s1 - s2) > doubleScalarVSMALL;
	}

	inline doubleScalar limit(const doubleScalar s1, const doubleScalar s2)
	{
		return (mag(s1) < mag(s2)) ? s1 : (doubleScalar)0;
	}

	inline doubleScalar minMod(const doubleScalar s1, const doubleScalar s2)
	{
		return (mag(s1) < mag(s2)) ? s1 : s2;
	}

	inline doubleScalar magSqr(const doubleScalar s)
	{
		return s * s;
	}

	inline doubleScalar sqr(const doubleScalar s)
	{
		return s * s;
	}

	inline doubleScalar sqrtSumSqr(const doubleScalar a, const doubleScalar b)
	{
		doubleScalar maga = mag(a);
		doubleScalar magb = mag(b);

		if (maga > magb)
		{
			return maga * ::sqrt((doubleScalar)1.0 + sqr(magb / maga));
		}
		else
		{
			return magb < doubleScalarVSMALL ? (doubleScalar)0 : magb * ::sqrt((doubleScalar)1.0 + sqr(maga / magb));
		}
	}

	inline doubleScalar pow3(const doubleScalar s)
	{
		return s * sqr(s);
	}

	inline doubleScalar pow4(const doubleScalar s)
	{
		return sqr(sqr(s));
	}

	inline doubleScalar pow5(const doubleScalar s)
	{
		return s * pow4(s);
	}

	inline doubleScalar pow6(const doubleScalar s)
	{
		return pow3(sqr(s));
	}

	inline doubleScalar inv(const doubleScalar s)
	{
		return (doubleScalar)1.0 / s;
	}

	inline doubleScalar dot(const doubleScalar s1, const doubleScalar s2)
	{
		return s1 * s2;
	}

	inline doubleScalar cmptMultiply(const doubleScalar s1, const doubleScalar s2)
	{
		return s1 * s2;
	}

	inline doubleScalar cmptDivide(const doubleScalar s1, const doubleScalar s2)
	{
		return s1 / s2;
	}

	inline doubleScalar cmptSumMultiply(const doubleScalar s1, const doubleScalar s2)
	{
		return s1 * s2;
	}

	inline doubleScalar cmptMax(const doubleScalar s)
	{
		return s;
	}

	inline doubleScalar cmptMin(const doubleScalar s)
	{
		return s;
	}

	inline doubleScalar cmptAv(const doubleScalar s)
	{
		return s;
	}

	inline doubleScalar cmptMag(const doubleScalar s)
	{
		return mag(s);
	}


	inline doubleScalar cmptSign(const doubleScalar s)
	{
		return sign(s);
	}

	inline doubleScalar j0(const doubleScalar s)
	{
		return ::_j0(s);
	}

	inline doubleScalar j1(const doubleScalar s)
	{
		return ::_j1(s);
	}

	inline doubleScalar y0(const doubleScalar s)
	{
		return ::_y0(s);
	}

	inline doubleScalar y1(const doubleScalar s)
	{
		return ::_y1(s);
	}

	// Standard C++ transcendental functions
	inline doubleScalar sqrt(const doubleScalar s) { return ::sqrt(s); }

	inline doubleScalar cbrt(const doubleScalar s) { return ::cbrt(s); }

	inline doubleScalar exp(const doubleScalar s) { return ::exp(s); }

	inline doubleScalar log(const doubleScalar s) { return ::log(s); }

	inline doubleScalar log10(const doubleScalar s) { return ::log10(s); }

	inline doubleScalar sin(const doubleScalar s) { return ::sin(s); }

	inline doubleScalar cos(const doubleScalar s) { return ::cos(s); }

	inline doubleScalar tan(const doubleScalar s) { return ::tan(s); }

	inline doubleScalar asin(const doubleScalar s) { return ::asin(s); }

	inline doubleScalar acos(const doubleScalar s) { return ::acos(s); }

	inline doubleScalar atan(const doubleScalar s) { return ::atan(s); }

	inline doubleScalar sinh(const doubleScalar s) { return ::sinh(s); }

	inline doubleScalar cosh(const doubleScalar s) { return ::cosh(s); }

	inline doubleScalar tanh(const doubleScalar s) { return ::tanh(s); }

	inline doubleScalar asinh(const doubleScalar s) { return ::asinh(s); }

	inline doubleScalar acosh(const doubleScalar s) { return ::acosh(s); }

	inline doubleScalar atanh(const doubleScalar s) { return ::atanh(s); }

	// Standard ANSI-C (but not in <cmath>) transcendental functions

	inline doubleScalar erf(const doubleScalar s) { return ::erf(s); }

	inline doubleScalar erfc(const doubleScalar s) { return ::erfc(s); }

	inline doubleScalar lgamma(const doubleScalar s) { return ::lgamma(s); }

	inline doubleScalar stabilise(const doubleScalar& s, const doubleScalar& theSmall)
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


	inline doubleScalar cmptStabilise
	(
		const doubleScalar& s,
		const doubleScalar& theSmall,
		const doubleScalar& value
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

	doubleScalar readDoubleScalar(Istream&);
	Istream& operator>>(Istream&, doubleScalar&);
	Ostream& operator<<(Ostream&, const doubleScalar);

	inline doubleScalar hypot(const doubleScalar x, const doubleScalar y)
	{
		return ::hypot(x, y);
	}

	inline doubleScalar atan2(const doubleScalar y, const doubleScalar x)
	{
		return ::atan2(y, x);
	}

	inline doubleScalar jn(const int n, const doubleScalar s)
	{
		return ::_jn(n, s);
	}

	inline doubleScalar yn(const int n, const doubleScalar s)
	{
		return ::_yn(n, s);
	}
}

#endif // !_doubleScalar_Header
