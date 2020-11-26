#pragma once
#include <scalar.hxx>
namespace tnbLib
{

	template<class Type>
	const Type& operator*(const Type& t, const one&)
	{
		return t;
	}

	template<class Type>
	const Type& operator*(const one&, const Type& t)
	{
		return t;
	}

	template<class Type>
	Type operator/(const one&, const Type& t)
	{
		return scalar(1) / t;
	}
}