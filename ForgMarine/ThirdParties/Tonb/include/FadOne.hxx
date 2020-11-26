#pragma once
#ifndef _FadOne_Header
#define _FadOne_Header

#include <error.hxx>
#include <IOstream.hxx>
#include <token.hxx>

#include <products.hxx>

#include <sstream>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * Forward declaration of template friend fuctions * * * * * * * //

	template<int nVars> class FadOne;

	template<int nVars>
	FadOne<nVars> operator+(const FadOne<nVars>&, const FadOne<nVars>&);

	template<int nVars>
	FadOne<nVars> operator+(const double, const FadOne<nVars>&);

	template<int nVars>
	FadOne<nVars> operator+(const FadOne<nVars>&, const double);

	template<int nVars>
	FadOne<nVars> operator-(const FadOne<nVars>&);

	template<int nVars>
	FadOne<nVars> operator-(const FadOne<nVars>&, const FadOne<nVars>&);

	template<int nVars>
	FadOne<nVars> operator-(const double, const FadOne<nVars>&);

	template<int nVars>
	FadOne<nVars> operator-(const FadOne<nVars>&, const double);

	template<int nVars>
	FadOne<nVars> operator*(const FadOne<nVars>&, const FadOne<nVars>&);

	template<int nVars>
	FadOne<nVars> operator*(const double, const FadOne<nVars>&);

	template<int nVars>
	FadOne<nVars> operator*(const FadOne<nVars>&, const double);

	template<int nVars>
	FadOne<nVars> operator/(const FadOne<nVars>&, const FadOne<nVars>&);

	template<int nVars>
	FadOne<nVars> operator/(const double, const FadOne<nVars>&);

	template<int nVars>
	FadOne<nVars> operator/(const FadOne<nVars>&, const double);

	template<int nVars>
	bool operator<(const FadOne<nVars>&, const FadOne<nVars>&);

	template<int nVars>
	bool operator<=(const FadOne<nVars>&, const FadOne<nVars>&);

	template<int nVars>
	bool operator>(const FadOne<nVars>&, const FadOne<nVars>&);

	template<int nVars>
	bool operator>=(const FadOne<nVars>&, const FadOne<nVars>&);

	template<int nVars>
	bool operator==(const FadOne<nVars>&, const FadOne<nVars>&);

	template<int nVars>
	bool operator!=(const FadOne<nVars>&, const FadOne<nVars>&);

	template<int nVars>
	Istream& operator>>(Istream&, FadOne<nVars>&);

	template<int nVars>
	Ostream& operator<<(Ostream&, const FadOne<nVars>&);


	/*---------------------------------------------------------------------------*\
							   Class FadOne Declaration
	\*---------------------------------------------------------------------------*/

	template<int nVars>
	class FadOne
	{
		// Private data

			//- Length of data list
		static const label Length = nVars + 1;

		//- Value and derivatives
		double data_[Length];


		// Private Member Functions


	public:

		//- Component type
		typedef FadOne<nVars> cmptType;


		// Member constants

		enum
		{
			dim = 3,         // Dimensionality of space
			rank = 0,        // Rank od Scalar is 0
			nComponents = 1  // Number of components in FadOne is 1
		};

		// Static data members

		static const char* const typeName;
		static const char* componentNames[];
		static const FadOne<nVars> zero;
		static const FadOne<nVars> one;


		// Constructors

			//- Construct null
		FadOne();

		//- Construct from value
		explicit FadOne(const double& v);

		//- Construct from Istream
		explicit FadOne(Istream&);

		//- Construct as copy
		FadOne(const FadOne<nVars>&);


		// Destructor - default


		// Member Functions

			//- Return value
		const double& value() const;
		double& value();

		//- Return derivative
		const double& deriv(const label i) const;
		double& deriv(const label i);


		// Member Operators

		void operator=(const double&);
		void operator=(const FadOne<nVars>&);

		void operator+=(const double&);
		void operator+=(const FadOne<nVars>&);
		void operator-=(const double&);
		void operator-=(const FadOne<nVars>&);
		void operator*=(const double&);
		void operator*=(const FadOne<nVars>&);
		void operator/=(const double&);
		void operator/=(const FadOne<nVars>&);


		// Friend Functions


		// Friend operators

		friend FadOne<nVars> operator+ <nVars>
			(
				const FadOne<nVars>&,
				const FadOne<nVars>&
				);

		friend FadOne<nVars> operator+ <nVars>
			(
				const double,
				const FadOne<nVars>&
				);

		friend FadOne<nVars> operator+ <nVars>
			(
				const FadOne<nVars>&,
				const double
				);

		friend FadOne<nVars> operator- <nVars>(const FadOne<nVars>&);

		friend FadOne<nVars> operator- <nVars>
			(
				const FadOne<nVars>&,
				const FadOne<nVars>&
				);

		friend FadOne<nVars> operator- <nVars>
			(
				const double,
				const FadOne<nVars>&
				);

		friend FadOne<nVars> operator- <nVars>
			(
				const FadOne<nVars>&,
				const double
				);

		friend FadOne<nVars> operator* <nVars>
			(
				const FadOne<nVars>&,
				const FadOne<nVars>&
				);

		friend FadOne<nVars> operator* <nVars>
			(
				const double,
				const FadOne<nVars>&
				);

		friend FadOne<nVars> operator* <nVars>
			(
				const FadOne<nVars>&,
				const double
				);

		friend FadOne<nVars> operator/ <nVars>
			(
				const FadOne<nVars>&,
				const FadOne<nVars>&
				);

		friend FadOne<nVars> operator/ <nVars>
			(
				const double,
				const FadOne<nVars>&
				);

		friend FadOne<nVars> operator/ <nVars>
			(
				const FadOne<nVars>&,
				const double
				);

		friend bool operator< <nVars>
			(
				const FadOne<nVars>&,
				const FadOne<nVars>&
				);

		friend bool operator<= <nVars>
			(
				const FadOne<nVars>&,
				const FadOne<nVars>&
				);

		friend bool operator> <nVars>
			(
				const FadOne<nVars>&,
				const FadOne<nVars>&
				);

		friend bool operator>= <nVars>
			(
				const FadOne<nVars>&,
				const FadOne<nVars>&
				);

		friend bool operator== <nVars>
			(
				const FadOne<nVars>&,
				const FadOne<nVars>&
				);

		friend bool operator!= <nVars>
			(
				const FadOne<nVars>&,
				const FadOne<nVars>&
				);


		// IOstream Operators

		friend Istream& operator>> <nVars>(Istream&, FadOne<nVars>&);
		friend Ostream& operator<< <nVars>(Ostream&, const FadOne<nVars>&);
	};


	template<int nVars>
	word name(const FadOne<nVars>& u)
	{
		std::ostringstream osBuffer;
		osBuffer << u;
		return osBuffer.str();
	}

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <FadOneI.hxx>
#include <FadOneFunctions.hxx>
#include <FadOneFunctionsI.hxx>

#ifdef NoRepository
#include <FadOne.cxx>
#endif

#endif // !_FadOne_Header
