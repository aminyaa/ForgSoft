#pragma once
#ifndef _doubleFloat_Header
#define _doubleFloat_Header

#include <label.hxx>
#include <products.hxx>

#include <cmath>

#ifndef DUMMY_SCALAR_FUNCTIONS
#define DUMMY_SCALAR_FUNCTIONS
inline float j0f(float x) { return float(_j0(double(x))); }
inline float j1f(float x) { return float(_j1(double(x))); }
inline float y0f(float x) { return float(_y0(double(x))); }
inline float y1f(float x) { return float(_y1(double(x))); }
inline float jnf(const int n, const float s) { return float(_jn(n, double(s))); }
inline float ynf(const int n, const float s) { return float(_yn(n, double(s))); }
#endif

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	template<class Cmpt>
	class typeOfRank<Cmpt, 0>
	{
	public:

		typedef Cmpt type;
	};


	template<class Cmpt>
	class symmTypeOfRank<Cmpt, 0>
	{
	public:

		typedef Cmpt type;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	template<class T>
	inline bool equal(const T& s1, const T& s2)
	{
		return s1 == s2;
	}


#define MAXMINPOW(retType, type1, type2)          \
                                                  \
MAXMIN(retType, type1, type2)                     \
                                                  \
inline double pow(const type1 s, const type2 e)   \
{                                                 \
    return ::pow(double(s), double(e));           \
}

	MAXMINPOW(long double, long double, long double)
		MAXMINPOW(long double, long double, double)
		MAXMINPOW(long double, long double, float)
		MAXMINPOW(long double, long double, int)
		MAXMINPOW(long double, double, long double)
		MAXMINPOW(long double, float, long double)
		MAXMINPOW(long double, int, long double)

		MAXMINPOW(double, double, double)
		MAXMINPOW(double, double, float)
		MAXMINPOW(double, float, double)
		MAXMINPOW(float, float, float)
		MAXMINPOW(double, double, int)
		MAXMINPOW(double, int, double)
		MAXMINPOW(double, double, long)
		MAXMINPOW(double, long, double)
		MAXMINPOW(float, float, int)
		MAXMINPOW(float, int, float)
		MAXMINPOW(float, float, long)
		MAXMINPOW(float, long, float)

#undef MAXMINPOW


		// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#endif // !_doubleFloat_Header
