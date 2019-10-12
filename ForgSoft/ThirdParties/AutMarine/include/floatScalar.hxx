#pragma once
#ifndef _floatScalar_Header
#define _floatScalar_Header

#include <doubleFloat.hxx>
#include <pTraits.hxx>
#include <word.hxx>

namespace AutLib
{

	typedef float floatScalar;

	// Largest and smallest scalar values allowed in certain parts of the code
	// (6 is the number of significant figures in an
	//  IEEE single precision number.  See limits.h or float.h)
	static const floatScalar floatScalarGREAT = (floatScalar)1.0e+6;
	static const floatScalar floatScalarVGREAT = (floatScalar)1.0e+37;
	static const floatScalar floatScalarROOTVGREAT = (floatScalar)1.0e+18;
	static const floatScalar floatScalarSMALL = (floatScalar)1.0e-6;
	static const floatScalar floatScalarVSMALL = (floatScalar)1.0e-37;
	static const floatScalar floatScalarROOTVSMALL = (floatScalar)1.0e-18;


	inline floatScalar mag(const floatScalar s)
	{
		return ::fabsf(s);
	}

	// template specialisation for pTraits<floatScalar>
	template<>
	class pTraits<floatScalar>
	{
		floatScalar p_;

	public:

		//- Component type
		typedef floatScalar cmptType;

		// Member constants

		enum
		{
			dim = 3,         // Dimensionality of space
			rank = 0,        // Rank of floatScalar is 0
			nComponents = 1  // Number of components in floatScalar is 1
		};


		// Static data members

		static const char* const typeName;
		static const char* componentNames[];
		static const floatScalar zero;
		static const floatScalar one;
		static const floatScalar max;
		static const floatScalar min;


		// Constructors

		//- Construct from floatScalar
		pTraits(const floatScalar s)
		{
			p_ = s;
		}

		//- Construct from Istream
		pTraits(Istream&);


		// Member operators

		operator floatScalar() const
		{
			return p_;
		}

		operator floatScalar&()
		{
			return p_;
		}
	};

	//- Return a string representation of a floatScalar
	word name(const floatScalar);


	inline floatScalar& setComponent(floatScalar& s, const direction)
	{
		return s;
	}

	inline floatScalar component(const floatScalar s, const direction)
	{
		return s;
	}

	inline floatScalar sign(const floatScalar s)
	{
		return (s >= 0) ? (floatScalar)1 : -(floatScalar)1;
	}

	inline floatScalar pos(const floatScalar s)
	{
		return (s >= 0) ? (floatScalar)1 : (floatScalar)0;
	}

	inline floatScalar neg(const floatScalar s)
	{
		return (s < 0) ? (floatScalar)1 : (floatScalar)0;
	}

	inline bool equal(const floatScalar& s1, const floatScalar& s2)
	{
		return mag(s1 - s2) <= floatScalarVSMALL;
	}

	inline bool notEqual(const floatScalar s1, const floatScalar s2)
	{
		return mag(s1 - s2) > floatScalarVSMALL;
	}

	inline floatScalar limit(const floatScalar s1, const floatScalar s2)
	{
		return (mag(s1) < mag(s2)) ? s1 : (floatScalar)0;
	}

	inline floatScalar minMod(const floatScalar s1, const floatScalar s2)
	{
		return (mag(s1) < mag(s2)) ? s1 : s2;
	}

	inline floatScalar magSqr(const floatScalar s)
	{
		return s * s;
	}

	inline floatScalar sqr(const floatScalar s)
	{
		return s * s;
	}

	inline floatScalar sqrtSumSqr(const floatScalar a, const floatScalar b)
	{
		floatScalar maga = mag(a);
		floatScalar magb = mag(b);

		if (maga > magb)
		{
			return maga * ::sqrt((floatScalar)1.0 + sqr(magb / maga));
		}
		else
		{
			return magb < floatScalarVSMALL ? (floatScalar)0 : magb * ::sqrt((floatScalar)1.0 + sqr(maga / magb));
		}
	}

	inline floatScalar pow3(const floatScalar s)
	{
		return s * sqr(s);
	}

	inline floatScalar pow4(const floatScalar s)
	{
		return sqr(sqr(s));
	}

	inline floatScalar pow5(const floatScalar s)
	{
		return s * pow4(s);
	}

	inline floatScalar pow6(const floatScalar s)
	{
		return pow3(sqr(s));
	}

	inline floatScalar inv(const floatScalar s)
	{
		return (floatScalar)1.0 / s;
	}

	inline floatScalar dot(const floatScalar s1, const floatScalar s2)
	{
		return s1 * s2;
	}

	inline floatScalar cmptMultiply(const floatScalar s1, const floatScalar s2)
	{
		return s1 * s2;
	}

	inline floatScalar cmptDivide(const floatScalar s1, const floatScalar s2)
	{
		return s1 / s2;
	}

	inline floatScalar cmptSumMultiply(const floatScalar s1, const floatScalar s2)
	{
		return s1 * s2;
	}

	inline floatScalar cmptMax(const floatScalar s)
	{
		return s;
	}

	inline floatScalar cmptMin(const floatScalar s)
	{
		return s;
	}

	inline floatScalar cmptAv(const floatScalar s)
	{
		return s;
	}

	inline floatScalar cmptMag(const floatScalar s)
	{
		return mag(s);
	}

	inline floatScalar cmptSign(const floatScalar s)
	{
		return sign(s);
	}

	inline floatScalar j0(const floatScalar s)
	{
		return (floatScalar)::_j0(s);
	}

	inline floatScalar j1(const floatScalar s)
	{
		return (floatScalar)::_j1(s);
	}

	inline floatScalar y0(const floatScalar s)
	{
		return (floatScalar)::_y0(s);
	}

	inline floatScalar y1(const floatScalar s)
	{
		return (floatScalar)::_y1(s);
	}

	// Standard C++ transcendental functions
	inline floatScalar sqrt(const floatScalar s) { return (floatScalar)::sqrt(s); }

	inline floatScalar cbrt(const floatScalar s) { return (floatScalar)::cbrt(s); }

	inline floatScalar exp(const floatScalar s) { return (floatScalar)::exp(s); }

	inline floatScalar log(const floatScalar s) { return (floatScalar)::log(s); }

	inline floatScalar log10(const floatScalar s) { return (floatScalar)::log10(s); }

	inline floatScalar sin(const floatScalar s) { return (floatScalar)::sin(s); }

	inline floatScalar cos(const floatScalar s) { return (floatScalar)::cos(s); }

	inline floatScalar tan(const floatScalar s) { return (floatScalar)::tan(s); }

	inline floatScalar asin(const floatScalar s) { return (floatScalar)::asin(s); }

	inline floatScalar acos(const floatScalar s) { return (floatScalar)::acos(s); }

	inline floatScalar atan(const floatScalar s) { return (floatScalar)::atan(s); }

	inline floatScalar sinh(const floatScalar s) { return (floatScalar)::sinh(s); }

	inline floatScalar cosh(const floatScalar s) { return (floatScalar)::cosh(s); }

	inline floatScalar tanh(const floatScalar s) { return (floatScalar)::tanh(s); }

	inline floatScalar asinh(const floatScalar s) { return (floatScalar)::asinh(s); }

	inline floatScalar acosh(const floatScalar s) { return (floatScalar)::acosh(s); }

	inline floatScalar atanh(const floatScalar s) { return (floatScalar)::atanh(s); }

	inline floatScalar erf(const floatScalar s) { return (floatScalar)::erf(s); }

	inline floatScalar erfc(const floatScalar s) { return (floatScalar)::erfc(s); }

	inline floatScalar lgamma(const floatScalar s) { return (floatScalar)::lgamma(s); }

	inline floatScalar stabilise(const floatScalar& s, const floatScalar& theSmall)
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

	inline floatScalar cmptStabilise
	(
		const floatScalar& s,
		const floatScalar& theSmall,
		const floatScalar& value
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

	floatScalar readFloatScalar(Istream&);

	Istream& operator>>(Istream&, floatScalar&);
	Ostream& operator<<(Ostream&, const floatScalar);

	inline floatScalar hypot(const floatScalar x, const floatScalar y)
	{
		return ::hypotf(x, y);
	}

	inline floatScalar atan2(const floatScalar y, const floatScalar x)
	{
		return ::atan2f(y, x);
	}

	inline floatScalar jn(const int n, const floatScalar s)
	{
		return ::jnf(n, s);
	}

	inline floatScalar yn(const int n, const floatScalar s)
	{
		return ::ynf(n, s);
	}
}

#endif // !_floatScalar_Header
