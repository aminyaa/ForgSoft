#pragma once
#include <scalar.hxx>
namespace AutLib
{
	template<class Type>
	inline const Type& operator*(const Type& t, const one&)
	{
		return t;
	}

	template<class Type>
	inline const Type& operator*(const one&, const Type& t)
	{
		return t;
	}

	template<class Type>
	inline Type operator/(const one&, const Type& t)
	{
		return scalar(1) / t;
	}
}