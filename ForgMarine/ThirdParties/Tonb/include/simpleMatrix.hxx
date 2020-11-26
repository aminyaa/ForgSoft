#pragma once
#ifndef _simpleMatrix_Header
#define _simpleMatrix_Header

#include <scalarMatrices.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Forward declaration of friend functions and operators

	template<class Type>
	class simpleMatrix;

	template<class Type>
	simpleMatrix<Type> operator+
		(
			const simpleMatrix<Type>&,
			const simpleMatrix<Type>&
			);

	template<class Type>
	simpleMatrix<Type> operator-
		(
			const simpleMatrix<Type>&,
			const simpleMatrix<Type>&
			);

	template<class Type>
	simpleMatrix<Type> operator*
		(
			const scalar,
			const simpleMatrix<Type>&
			);

	template<class Type>
	Ostream& operator<<
		(
			Ostream&,
			const simpleMatrix<Type>&
			);


	/*---------------------------------------------------------------------------*\
							   Class simpleMatrix Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class simpleMatrix
		:
		public scalarSquareMatrix
	{
		// Private data

		Field<Type> source_;


	public:

		// Constructors

			//- Construct given size
			//  Note: this does not initialise the coefficients or the source.
		simpleMatrix(const label);

		//- Construct given size and initial values for the
		//  coefficients and source
		simpleMatrix(const label, const scalar, const Type&);

		//- Construct from components
		simpleMatrix(const scalarSquareMatrix&, const Field<Type>&);

		//- Construct from Istream
		simpleMatrix(Istream&);

		//- Construct as copy
		simpleMatrix(const simpleMatrix<Type>&);


		// Member Functions

			// Access

				//- Return access to the source
		Field<Type>& source()
		{
			return source_;
		}

		//- Return const-access to the source
		const Field<Type>& source() const
		{
			return source_;
		}


		//- Solve the matrix using Gaussian elimination with pivoting
		//  and return the solution
		Field<Type> solve() const;

		//- Solve the matrix using LU decomposition with pivoting
		//  and return the solution
		Field<Type> LUsolve() const;


		// Member Operators

		void operator=(const simpleMatrix<Type>&);


		// Ostream Operator

		friend Ostream& operator<< <Type>
			(
				Ostream&,
				const simpleMatrix<Type>&
				);
	};


	// Global operators

	template<class Type>
	simpleMatrix<Type> operator+
		(
			const simpleMatrix<Type>&,
			const simpleMatrix<Type>&
			);

	template<class Type>
	simpleMatrix<Type> operator-
		(
			const simpleMatrix<Type>&,
			const simpleMatrix<Type>&
			);

	template<class Type>
	simpleMatrix<Type> operator*
		(
			const scalar,
			const simpleMatrix<Type>&
			);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <simpleMatrix.cxx>
#endif

#endif // !_simpleMatrix_Header
