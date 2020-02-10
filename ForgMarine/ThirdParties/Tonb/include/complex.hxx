#pragma once
#ifndef _complex_Header
#define _complex_Header

#include <scalar.hxx>
#include <bool.hxx>
#include <word.hxx>
#include <contiguous.hxx>

namespace tnbLib
{

	// Forward declaration of friend functions and operators

	class complex;

	inline scalar magSqr(const complex&);
	inline complex sqr(const complex&);
	inline scalar mag(const complex&);
	inline const complex& max(const complex&, const complex&);
	inline const complex& min(const complex&, const complex&);
	inline complex limit(const complex&, const complex&);
	inline const complex& sum(const complex&);
	inline complex operator+(const complex&, const complex&);
	inline complex operator-(const complex&);
	inline complex operator-(const complex&, const complex&);
	inline complex operator*(const complex&, const complex&);
	inline complex operator/(const complex&, const complex&);
	inline complex operator*(const scalar, const complex&);
	inline complex operator*(const complex&, const scalar);
	inline complex operator/(const complex&, const scalar);
	inline complex operator/(const scalar, const complex&);
	Istream& operator>>(Istream&, complex&);
	Ostream& operator<<(Ostream&, const complex&);


	/*---------------------------------------------------------------------------*\
							   Class complex Declaration
	\*---------------------------------------------------------------------------*/

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
		complex();

		//- Construct given real and imaginary parts
		complex(const scalar Re, const scalar Im);

		//- Construct from Istream
		complex(Istream&);


		// Member functions

			   // Access

		scalar Re() const;
		scalar Im() const;

		// Edit

		scalar& Re();
		scalar& Im();

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


	// * * * * * * * * * * * * * * Global functions  * * * * * * * * * * * * * * //

	//- Return a string representation of a complex
	word name(const complex&);


	//- Data associated with complex type are contiguous
	template<>
	inline bool contiguous<complex>() { return true; }


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#include <complexI.hxx>

#endif // !_complex_Header
