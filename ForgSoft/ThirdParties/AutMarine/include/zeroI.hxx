#pragma once
namespace AutLib
{
	template<class Type>
	inline const Type& operator+(const Type& t, const zero&)
	{
		return t;
	}

	template<class Type>
	inline const Type& operator+(const zero&, const Type& t)
	{
		return t;
	}

	template<class Type>
	inline const Type& operator-(const Type& t, const zero&)
	{
		return t;
	}

	template<class Type>
	inline Type operator-(const zero&, const Type& t)
	{
		return -t;
	}

	template<class Type>
	inline zero operator*(const Type& t, const zero&)
	{
		return zero();
	}

	template<class Type>
	inline zero operator*(const zero&, const Type& t)
	{
		return zero();
	}

	template<class Type>
	inline zero operator/(const zero&, const Type& t)
	{
		return zero();
	}
}