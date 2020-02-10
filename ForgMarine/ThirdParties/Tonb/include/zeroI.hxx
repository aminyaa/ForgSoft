#pragma once
namespace tnbLib
{

	template<class Type>
	const Type& operator+(const Type& t, const zero&)
	{
		return t;
	}

	template<class Type>
	const Type& operator+(const zero&, const Type& t)
	{
		return t;
	}

	template<class Type>
	const Type& operator-(const Type& t, const zero&)
	{
		return t;
	}

	template<class Type>
	Type operator-(const zero&, const Type& t)
	{
		return -t;
	}

	template<class Type>
	zero operator*(const Type& t, const zero&)
	{
		return zero();
	}

	template<class Type>
	zero operator*(const zero&, const Type& t)
	{
		return zero();
	}

	template<class Type>
	zero operator/(const zero&, const Type& t)
	{
		return zero();
	}
}