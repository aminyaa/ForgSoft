#pragma once
#ifndef _scalarBlockCoeff_Header
#define _scalarBlockCoeff_Header

#include <BlockCoeff.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							  Class BlockCoeff Declaration
	\*---------------------------------------------------------------------------*/

	template<>
	class BlockCoeff<scalar>
		:
		public blockCoeffBase
	{
	public:

		// Public data types

			//- Component type
		typedef scalar Type;

		typedef Type xType;

		//- Coefficient type
		typedef scalar scalarType;


		//- Multiplication trait
		class multiply
		{
		public:

			multiply() {}

			Type operator()(const scalarType& c, const Type& x) const
			{
				return c * x;
			}
			Type operator()(const BlockCoeff<Type>& c, const Type& x) const
			{
				return c.asScalar()*x;
			}

			// Inverse functions
			scalarType inverse(const scalarType& c) const
			{
				return 1.0 / c;
			}

			// Triple product of coefficients
			scalarType tripleProduct
			(
				const scalarType& a,
				const scalarType& b,
				const scalarType& c
			) const
			{
				return a * c / b;
			}
		};


	private:

		// Private data

			//- Scalar coefficient
		scalar scalarCoeff_;


	public:

		// Constructors

			//- Construct null
		explicit BlockCoeff();

		//- Construct as copy
		BlockCoeff(const BlockCoeff<scalar>&);

		//- Construct from Istream
		BlockCoeff(Istream&);

		//- Clone
		BlockCoeff<scalar> clone() const;


		// Destructor

		~BlockCoeff();


		// Member functions

			//- Return active type
		blockCoeffBase::activeLevel activeType() const;

		//- Return as scalar
		const scalar& asScalar() const
		{
			return scalarCoeff_;
		}

		scalar& asScalar()
		{
			return scalarCoeff_;
		}

		//- Return as linear
		const scalar& asLinear() const
		{
			return scalarCoeff_;
		}

		scalar& asLinear()
		{
			return scalarCoeff_;
		}

		//- Return as square
		const scalar& asSquare() const
		{
			return scalarCoeff_;
		}

		scalar& asSquare()
		{
			return scalarCoeff_;
		}


		//- Return component
		scalar component(const direction) const;


		// Member operators

		void operator=(const BlockCoeff<scalar>&);


		// IOstream operators

		friend Ostream& operator<<
			(
				Ostream&,
				const BlockCoeff<scalar>&
				);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_scalarBlockCoeff_Header
