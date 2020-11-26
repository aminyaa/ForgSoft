#pragma once
//#include <pTraits.hxx>
//
//namespace tnbLib
//{
//
//	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
//
//// template specialisation for pTraits<Scalar>
//	template<>
//	class pTraits<Scalar>
//	{
//		Scalar p_;
//
//	public:
//
//		//- Component type
//		typedef Scalar cmptType;
//
//		// Member constants
//
//		enum
//		{
//			dim = 3,         // Dimensionality of space
//			rank = 0,        // Rank of Scalar is 0
//			nComponents = 1  // Number of components in Scalar is 1
//		};
//
//
//		// Static data members
//
//		static const char* const typeName;
//		static const char* componentNames[];
//		static const Scalar zero;
//		static const Scalar one;
//		static const Scalar max;
//		static const Scalar min;
//
//
//		// Constructors
//
//			//- Construct from Scalar
//		pTraits(const Scalar s)
//		{
//			p_ = s;
//		}
//
//		//- Construct from Istream
//		pTraits(Istream&);
//
//
//		// Member operators
//
//		operator Scalar() const
//		{
//			return p_;
//		}
//
//		operator Scalar&()
//		{
//			return p_;
//		}
//	};
//
//
//	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
//
//	//- Return a string representation of a Scalar
//	word name(const Scalar);
//
//
//	inline Scalar& setComponent(Scalar& s, const direction)
//	{
//		return s;
//	}
//
//	inline Scalar component(const Scalar s, const direction)
//	{
//		return s;
//	}
//
//	inline Scalar sign(const Scalar s)
//	{
//		return (s >= 0) ? 1 : -1;
//	}
//
//	inline Scalar pos(const Scalar s)
//	{
//		return (s >= 0) ? 1 : 0;
//	}
//
//	inline Scalar neg(const Scalar s)
//	{
//		return (s < 0) ? 1 : 0;
//	}
//
//	inline bool equal(const Scalar& s1, const Scalar& s2)
//	{
//		return mag(s1 - s2) <= ScalarVSMALL;
//	}
//
//	inline bool notEqual(const Scalar s1, const Scalar s2)
//	{
//		return mag(s1 - s2) > ScalarVSMALL;
//	}
//
//	inline Scalar limit(const Scalar s1, const Scalar s2)
//	{
//		return (mag(s1) < mag(s2)) ? s1 : 0;
//	}
//
//	inline Scalar minMod(const Scalar s1, const Scalar s2)
//	{
//		return (mag(s1) < mag(s2)) ? s1 : s2;
//	}
//
//	inline Scalar magSqr(const Scalar s)
//	{
//		return s * s;
//	}
//
//	inline Scalar sqr(const Scalar s)
//	{
//		return s * s;
//	}
//
//	inline Scalar sqrtSumSqr(const Scalar a, const Scalar b)
//	{
//		Scalar maga = mag(a);
//		Scalar magb = mag(b);
//
//		if (maga > magb)
//		{
//			return maga * ::sqrt(1.0 + sqr(magb / maga));
//		}
//		else
//		{
//			return magb < ScalarVSMALL ? 0 : magb * ::sqrt(1.0 + sqr(maga / magb));
//		}
//	}
//
//	inline Scalar pow3(const Scalar s)
//	{
//		return s * sqr(s);
//	}
//
//	inline Scalar pow4(const Scalar s)
//	{
//		return sqr(sqr(s));
//	}
//
//	inline Scalar pow5(const Scalar s)
//	{
//		return s * pow4(s);
//	}
//
//	inline Scalar pow6(const Scalar s)
//	{
//		return pow3(sqr(s));
//	}
//
//	inline Scalar inv(const Scalar s)
//	{
//		return 1.0 / s;
//	}
//
//	inline Scalar dot(const Scalar s1, const Scalar s2)
//	{
//		return s1 * s2;
//	}
//
//	inline Scalar cmptMultiply(const Scalar s1, const Scalar s2)
//	{
//		return s1 * s2;
//	}
//
//	inline Scalar cmptDivide(const Scalar s1, const Scalar s2)
//	{
//		return s1 / s2;
//	}
//
//	inline Scalar cmptSumMultiply(const Scalar s1, const Scalar s2)
//	{
//		return s1 * s2;
//	}
//
//	inline Scalar cmptMax(const Scalar s)
//	{
//		return s;
//	}
//
//	inline Scalar cmptMin(const Scalar s)
//	{
//		return s;
//	}
//
//	inline Scalar cmptAv(const Scalar s)
//	{
//		return s;
//	}
//
//	inline Scalar cmptMag(const Scalar s)
//	{
//		return mag(s);
//	}
//
//
//	inline Scalar cmptSign(const Scalar s)
//	{
//		return sign(s);
//	}
//
//
//	// Standard C++ transcendental functions
//	transFunc(sqrt)
//		transFunc(cbrt)
//		transFunc(exp)
//		transFunc(log)
//		transFunc(log10)
//		transFunc(sin)
//		transFunc(cos)
//		transFunc(tan)
//		transFunc(asin)
//		transFunc(acos)
//		transFunc(atan)
//		transFunc(sinh)
//		transFunc(cosh)
//		transFunc(tanh)
//		transFunc(asinh)
//		transFunc(acosh)
//		transFunc(atanh)
//
//		// Standard ANSI-C (but not in <cmath>) transcendental functions
//
//		transFunc(erf)
//		transFunc(erfc)
//		transFunc(lgamma)
//
//		transFunc(j0)
//		transFunc(j1)
//
//		transFunc(y0)
//		transFunc(y1)
//
//
//		// Stabilization around zero for division
//		inline Scalar stabilise(const Scalar& s, const Scalar& theSmall)
//	{
//		if (s >= 0)
//		{
//			return s + theSmall;
//		}
//		else
//		{
//			return s - theSmall;
//		}
//	}
//
//
//	inline Scalar cmptStabilise
//	(
//		const Scalar& s,
//		const Scalar& theSmall,
//		const Scalar& value
//	)
//	{
//		if (mag(s) < theSmall)
//		{
//			return sign(s)*value;
//		}
//		else
//		{
//			return s;
//		}
//	}
//
//
//	// * * * * * * * * * * * * * * * IOstream Operators  * * * * * * * * * * * * //
//
//	Scalar readScalar(Istream&);
//	Istream& operator>>(Istream&, Scalar&);
//	Ostream& operator<<(Ostream&, const Scalar);
//
//
//	// ************************************************************************* //
//}