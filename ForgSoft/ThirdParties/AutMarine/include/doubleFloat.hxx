#pragma once
#ifndef _doubleFloat_Header
#define _doubleFloat_Header

#include <label.hxx>
#include <products.hxx>

#include <cmath>

#ifndef DUMMY_SCALAR_FUNCTIONS
#define DUMMY_SCALAR_FUNCTIONS
inline float j0f(float x)
{
	return float(_j0(double(x)));
}
inline float j1f(float x)
{
	return float(_j1(double(x)));
}
inline float y0f(float x)
{
	return float(_y0(double(x)));
}
inline float y1f(float x)
{
	return float(_y1(double(x)));
}
inline float jnf(const int n, const float s)
{
	return float(_jn(n, double(s)));
}
inline float ynf(const int n, const float s)
{
	return float(_yn(n, double(s)));
}
#endif

namespace AutLib
{

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

	template<class T>
	inline bool equal(const T& s1, const T& s2)
	{
		return s1 == s2;
	}

	inline long double max(const long double s1, const long double s2) { return (s1 > s2) ? s1 : s2; }

	inline long double min(const long double s1, const long double s2) { return (s1 < s2) ? s1 : s2; }

	inline double pow(const long double s, const long double e) { return ::pow(double(s), double(e)); }

	inline long double max(const long double s1, const double s2) { return (s1 > s2) ? s1 : s2; }

	inline long double min(const long double s1, const double s2) { return (s1 < s2) ? s1 : s2; }

	inline double pow(const long double s, const double e) { return ::pow(double(s), double(e)); }

	inline long double max(const long double s1, const float s2) { return (s1 > s2) ? s1 : s2; }

	inline long double min(const long double s1, const float s2) { return (s1 < s2) ? s1 : s2; }

	inline double pow(const long double s, const float e) { return ::pow(double(s), double(e)); }

	inline long double max(const long double s1, const int s2) { return (s1 > s2) ? s1 : s2; }

	inline long double min(const long double s1, const int s2) { return (s1 < s2) ? s1 : s2; }

	inline double pow(const long double s, const int e) { return ::pow(double(s), double(e)); }

	inline long double max(const double s1, const long double s2) { return (s1 > s2) ? s1 : s2; }

	inline long double min(const double s1, const long double s2) { return (s1 < s2) ? s1 : s2; }

	inline double pow(const double s, const long double e) { return ::pow(double(s), double(e)); }

	inline long double max(const float s1, const long double s2) { return (s1 > s2) ? s1 : s2; }

	inline long double min(const float s1, const long double s2) { return (s1 < s2) ? s1 : s2; }

	inline double pow(const float s, const long double e) { return ::pow(double(s), double(e)); }

	inline long double max(const int s1, const long double s2) { return (s1 > s2) ? s1 : s2; }

	inline long double min(const int s1, const long double s2) { return (s1 < s2) ? s1 : s2; }

	inline double pow(const int s, const long double e) { return ::pow(double(s), double(e)); }


	inline double max(const double s1, const double s2) { return (s1 > s2) ? s1 : s2; }

	inline double min(const double s1, const double s2) { return (s1 < s2) ? s1 : s2; }

	inline double pow(const double s, const double e) { return ::pow(double(s), double(e)); }

	inline double max(const double s1, const float s2) { return (s1 > s2) ? s1 : s2; }

	inline double min(const double s1, const float s2) { return (s1 < s2) ? s1 : s2; }

	inline double pow(const double s, const float e) { return ::pow(double(s), double(e)); }

	inline double max(const float s1, const double s2) { return (s1 > s2) ? s1 : s2; }

	inline double min(const float s1, const double s2) { return (s1 < s2) ? s1 : s2; }

	inline double pow(const float s, const double e) { return ::pow(double(s), double(e)); }

	inline float max(const float s1, const float s2) { return (s1 > s2) ? s1 : s2; }

	inline float min(const float s1, const float s2) { return (s1 < s2) ? s1 : s2; }

	inline double pow(const float s, const float e) { return ::pow(double(s), double(e)); }

	inline double max(const double s1, const int s2) { return (s1 > s2) ? s1 : s2; }

	inline double min(const double s1, const int s2) { return (s1 < s2) ? s1 : s2; }

	inline double pow(const double s, const int e) { return ::pow(double(s), double(e)); }

	inline double max(const int s1, const double s2) { return (s1 > s2) ? s1 : s2; }

	inline double min(const int s1, const double s2) { return (s1 < s2) ? s1 : s2; }

	inline double pow(const int s, const double e) { return ::pow(double(s), double(e)); }

	inline double max(const double s1, const long s2) { return (s1 > s2) ? s1 : s2; }

	inline double min(const double s1, const long s2) { return (s1 < s2) ? s1 : s2; }

	inline double pow(const double s, const long e) { return ::pow(double(s), double(e)); }

	inline double max(const long s1, const double s2) { return (s1 > s2) ? s1 : s2; }

	inline double min(const long s1, const double s2) { return (s1 < s2) ? s1 : s2; }

	inline double pow(const long s, const double e) { return ::pow(double(s), double(e)); }

	inline float max(const float s1, const int s2) { return (s1 > s2) ? s1 : s2; }

	inline float min(const float s1, const int s2) { return (s1 < s2) ? s1 : s2; }

	inline double pow(const float s, const int e) { return ::pow(double(s), double(e)); }

	inline float max(const int s1, const float s2) { return (s1 > s2) ? s1 : s2; }

	inline float min(const int s1, const float s2) { return (s1 < s2) ? s1 : s2; }

	inline double pow(const int s, const float e) { return ::pow(double(s), double(e)); }

	inline float max(const float s1, const long s2) { return (s1 > s2) ? s1 : s2; }

	inline float min(const float s1, const long s2) { return (s1 < s2) ? s1 : s2; }

	inline double pow(const float s, const long e) { return ::pow(double(s), double(e)); }

	inline float max(const long s1, const float s2) { return (s1 > s2) ? s1 : s2; }

	inline float min(const long s1, const float s2) { return (s1 < s2) ? s1 : s2; }

	inline double pow(const long s, const float e) { return ::pow(double(s), double(e)); }
}

#endif // !_doubleFloat_Header
