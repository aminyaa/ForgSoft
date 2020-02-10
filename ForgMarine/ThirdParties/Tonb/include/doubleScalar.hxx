#pragma once
#ifndef _doubleScalar_Header
#define _doubleScalar_Header

#include <doubleFloat.hxx>
#include <direction.hxx>
#include <word.hxx>

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef double doubleScalar;

	// Largest and smallest scalar values allowed in certain parts of the code.
	// (15 is the number of significant figures in an
	//  IEEE double precision number.  See limits.h or float.h)
	static const doubleScalar doubleScalarGREAT = 1.0e+15;
	static const doubleScalar doubleScalarVGREAT = 1.0e+300;
	static const doubleScalar doubleScalarROOTVGREAT = 1.0e+150;
	static const doubleScalar doubleScalarSMALL = 1.0e-15;
	static const doubleScalar doubleScalarVSMALL = 1.0e-300;
	static const doubleScalar doubleScalarROOTVSMALL = 1.0e-150;

#define ScalarVGREAT doubleScalarVGREAT
#define ScalarVSMALL doubleScalarVSMALL
#define readScalar readDoubleScalar

	inline doubleScalar mag(const doubleScalar s)
	{
		return ::fabs(s);
	}

#define transFunc(func)            \
inline doubleScalar func(const doubleScalar s) \
{                                  \
    return ::func(s);              \
}
}

#include <pTraits.hxx>

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

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


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

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
		return (s >= 0) ? 1 : -1;
	}

	inline doubleScalar pos(const doubleScalar s)
	{
		return (s >= 0) ? 1 : 0;
	}

	inline doubleScalar neg(const doubleScalar s)
	{
		return (s < 0) ? 1 : 0;
	}

	inline bool equal(const doubleScalar& s1, const doubleScalar& s2)
	{
		return mag(s1 - s2) <= ScalarVSMALL;
	}

	inline bool notEqual(const doubleScalar s1, const doubleScalar s2)
	{
		return mag(s1 - s2) > ScalarVSMALL;
	}

	inline doubleScalar limit(const doubleScalar s1, const doubleScalar s2)
	{
		return (mag(s1) < mag(s2)) ? s1 : 0;
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
			return maga * ::sqrt(1.0 + sqr(magb / maga));
		}
		else
		{
			return magb < ScalarVSMALL ? 0 : magb * ::sqrt(1.0 + sqr(maga / magb));
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
		return 1.0 / s;
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


	// * * * * * * * * * * * * * * * IOstream Operators  * * * * * * * * * * * * //

	doubleScalar readScalar(Istream&);
	Istream& operator>>(Istream&, doubleScalar&);
	Ostream& operator<<(Ostream&, const doubleScalar);


	// ************************************************************************* //
}

namespace tnbLib
{

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

#undef ScalarVGREAT
#undef ScalarVSMALL
#undef readScalar
#undef transFunc


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#endif // !_doubleScalar_Header
