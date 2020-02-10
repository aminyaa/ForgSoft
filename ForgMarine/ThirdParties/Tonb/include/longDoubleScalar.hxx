#pragma once
#ifndef _longDoubleScalar_Header
#define _longDoubleScalar_Header

#include <doubleFloat.hxx>
#include <direction.hxx>
#include <word.hxx>

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

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


#define ScalarVGREAT longDoubleScalarVGREAT
#define ScalarVSMALL longDoubleScalarVSMALL
#define readScalar readLongDoubleScalar

	inline longDoubleScalar mag(const longDoubleScalar s)
	{
		return ::fabsl(s);
	}

#define transFunc(func)            \
inline longDoubleScalar func(const longDoubleScalar s) \
{                                  \
    return ::func(s);              \
}

}

#include <pTraits.hxx>

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

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


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

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
		return (s >= 0) ? 1 : -1;
	}

	inline longDoubleScalar pos(const longDoubleScalar s)
	{
		return (s >= 0) ? 1 : 0;
	}

	inline longDoubleScalar neg(const longDoubleScalar s)
	{
		return (s < 0) ? 1 : 0;
	}

	inline bool equal(const longDoubleScalar& s1, const longDoubleScalar& s2)
	{
		return mag(s1 - s2) <= ScalarVSMALL;
	}

	inline bool notEqual(const longDoubleScalar s1, const longDoubleScalar s2)
	{
		return mag(s1 - s2) > ScalarVSMALL;
	}

	inline longDoubleScalar limit(const longDoubleScalar s1, const longDoubleScalar s2)
	{
		return (mag(s1) < mag(s2)) ? s1 : 0;
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
			return maga * ::sqrt(1.0 + sqr(magb / maga));
		}
		else
		{
			return magb < ScalarVSMALL ? 0 : magb * ::sqrt(1.0 + sqr(maga / magb));
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
		return 1.0 / s;
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


	// Standard C++ transcendental functions
	transFunc(sqrt)
		transFunc(cbrt)
		transFunc(exp)
		transFunc(log)
		transFunc(log10)
		transFunc(sin)
		transFunc(cos)
		transFunc(tan)
		transFunc(asin)
		transFunc(acos)
		transFunc(atan)
		transFunc(sinh)
		transFunc(cosh)
		transFunc(tanh)
		transFunc(asinh)
		transFunc(acosh)
		transFunc(atanh)

		// Standard ANSI-C (but not in <cmath>) transcendental functions

		transFunc(erf)
		transFunc(erfc)
		transFunc(lgamma)

		transFunc(_j0)
		transFunc(_j1)

		transFunc(_y0)
		transFunc(_y1)


		// Stabilization around zero for division
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


	// * * * * * * * * * * * * * * * IOstream Operators  * * * * * * * * * * * * //

	longDoubleScalar readScalar(Istream&);
	Istream& operator>>(Istream&, longDoubleScalar&);
	Ostream& operator<<(Ostream&, const longDoubleScalar);


	// ************************************************************************* //
}

namespace tnbLib
{

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

#undef ScalarVGREAT
#undef ScalarVSMALL
#undef readScalar
#undef transFunc


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

}

#endif // !_longDoubleScalar_Header
