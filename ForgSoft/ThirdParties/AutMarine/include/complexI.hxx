#pragma once
inline 
AutLib::complex AutLib::complex::conjugate() const
{
	return complex(re, -im);
}

namespace AutLib
{
	inline const complex& complex::operator=(const complex& c)
	{
		re = c.re;
		im = c.im;
		return *this;
	}


	inline void complex::operator+=(const complex& c)
	{
		re += c.re;
		im += c.im;
	}


	inline void complex::operator-=(const complex& c)
	{
		re -= c.re;
		im -= c.im;
	}


	inline void complex::operator*=(const complex& c)
	{
		*this = (*this)*c;
	}


	inline void complex::operator/=(const complex& c)
	{
		*this = *this / c;
	}


	inline const complex& complex::operator=(const scalar s)
	{
		re = s;
		im = 0.0;
		return *this;
	}


	inline void complex::operator+=(const scalar s)
	{
		re += s;
	}


	inline void complex::operator-=(const scalar s)
	{
		re -= s;
	}


	inline void complex::operator*=(const scalar s)
	{
		re *= s;
		im *= s;
	}


	inline void complex::operator/=(const scalar s)
	{
		re /= s;
		im /= s;
	}


	inline complex complex::operator!() const
	{
		return conjugate();
	}


	inline bool complex::operator==(const complex& c) const
	{
		return (equal(re, c.re) && equal(im, c.im));
	}


	inline bool complex::operator!=(const complex& c) const
	{
		return !operator==(c);
	}

	inline scalar magSqr(const complex& c)
	{
		return (c.re*c.re + c.im*c.im);
	}


	inline complex sqr(const complex& c)
	{
		return c * c;
	}


	inline scalar mag(const complex& c)
	{
		return sqrt(magSqr(c));
	}


	inline const complex& max(const complex& c1, const complex& c2)
	{
		if (mag(c1) > mag(c2))
		{
			return c1;
		}
		else
		{
			return c2;
		}
	}


	inline const complex& min(const complex& c1, const complex& c2)
	{
		if (mag(c1) < mag(c2))
		{
			return c1;
		}
		else
		{
			return c2;
		}
	}


	inline complex limit(const complex& c1, const complex& c2)
	{
		return complex(limit(c1.re, c2.re), limit(c1.im, c2.im));
	}


	inline const complex& sum(const complex& c)
	{
		return c;
	}


	template<class Cmpt>
	class Tensor;

	inline complex transform(const Tensor<scalar>&, const complex c)
	{
		return c;
	}

	inline complex operator+(const complex& c1, const complex& c2)
	{
		return complex
		(
			c1.re + c2.re,
			c1.im + c2.im
		);
	}


	inline complex operator-(const complex& c)
	{
		return complex
		(
			-c.re,
			-c.im
		);
	}


	inline complex operator-(const complex& c1, const complex& c2)
	{
		return complex
		(
			c1.re - c2.re,
			c1.im - c2.im
		);
	}


	inline complex operator*(const complex& c1, const complex& c2)
	{
		return complex
		(
			c1.re*c2.re - c1.im*c2.im,
			c1.im*c2.re + c1.re*c2.im
		);
	}


	inline complex operator/(const complex& c1, const complex& c2)
	{
		scalar sqrC2 = magSqr(c2);

		return complex
		(
			(c1.re*c2.re + c1.im*c2.im) / sqrC2,
			(c1.im*c2.re - c1.re*c2.im) / sqrC2
		);
	}


	inline complex operator*(const scalar s, const complex& c)
	{
		return complex(s*c.re, s*c.im);
	}


	inline complex operator*(const complex& c, const scalar s)
	{
		return complex(s*c.re, s*c.im);
	}


	inline complex operator/(const complex& c, const scalar s)
	{
		return complex(c.re / s, c.im / s);
	}


	inline complex operator/(const scalar s, const complex& c)
	{
		scalar sqrC2 = magSqr(c);

		// Bug fix, Hua Shan.  2/Apr/2010
		return complex
		(
			s*c.re / sqrC2,
			-s * c.im / sqrC2
		);
	}
}