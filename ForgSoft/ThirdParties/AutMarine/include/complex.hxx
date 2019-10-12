#pragma once
#ifndef _complex_Header
#define _complex_Header

#include <scalar.hxx>
#include <contiguous.hxx>

namespace AutLib
{

	class complex
	{

		// private data

		//- Real and imaginary parts of the complex number
		scalar re, im;

	public:

		//- Component type
		typedef complex cmptType;


		// Static data members

		static const char* const typeName;

		static const complex zero;
		static const complex one;


		// Constructors

		//- Construct null
		complex()
		{}

		//- Construct given real and imaginary parts
		complex(const scalar Re, const scalar Im)
			: re(Re)
			, im(Im)
		{}

		//- Construct from Istream
		complex(Istream&);


		// Member functions

		// Access

		scalar Re() const { return re; }
		scalar Im() const { return im; }

		// Edit

		scalar& Re() { return re; }
		scalar& Im() { return im; }

		// Operators

		complex conjugate() const;


		// Member operators

		const complex& operator=(const complex&);
		void operator+=(const complex&);
		void operator-=(const complex&);
		void operator*=(const complex&);
		void operator/=(const complex&);

		const complex& operator=(const scalar);
		void operator+=(const scalar);
		void operator-=(const scalar);
		void operator*=(const scalar);
		void operator/=(const scalar);

		complex operator!() const;

		bool operator==(const complex&) const;
		bool operator!=(const complex&) const;


		// Friend functions

		friend scalar magSqr(const complex& c);
		friend complex sqr(const complex& c);
		friend scalar mag(const complex& c);
		friend const complex& max(const complex&, const complex&);
		friend const complex& min(const complex&, const complex&);

		friend complex limit(const complex&, const complex&);

		friend const complex& sum(const complex&);


		// Friend operators

		friend complex operator+(const complex&, const complex&);
		friend complex operator-(const complex&);
		friend complex operator-(const complex&, const complex&);
		friend complex operator*(const complex&, const complex&);
		friend complex operator/(const complex&, const complex&);

		friend complex operator*(const scalar, const complex&);
		friend complex operator*(const complex&, const scalar);
		friend complex operator/(const complex&, const scalar);
		friend complex operator/(const scalar, const complex&);


		// IOstream operators

		friend Istream& operator>>(Istream&, complex&);
		friend Ostream& operator<<(Ostream&, const complex&);
	};

	//- Return a string representation of a complex
	word name(const complex&);


	//- Data associated with complex type are contiguous
	template<>
	inline bool contiguous<complex>()
	{
		return true;
	}
}

#include <complexI.hxx>

#endif // !_complex_Header
