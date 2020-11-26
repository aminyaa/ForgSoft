#pragma once
#ifndef _EigenSolver_Header
#define _EigenSolver_Header

#include <SquareMatrix.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Class forward declarations

	/*---------------------------------------------------------------------------*\
							   Class EigenSolver Declaration
	\*---------------------------------------------------------------------------*/

	template<class T>
	class EigenSolver
	{
		// Private data

			//- Eigenvalues
		List<T> values_;

		//- Eigenvectors
		List<List<T> > vectors_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		EigenSolver(const EigenSolver&);

		//- Disallow default bitwise assignment
		void operator=(const EigenSolver&);


		//- Check matrix for shape and symmetry
		void checkMatrix(const SquareMatrix<T>& mtx) const;

		//- Factorise into eigen-values and eigen-vectors
		void factorise(const SquareMatrix<T>& mtx);

		//- Rotate the matrix
		inline void rotate
		(
			SquareMatrix<T>& a,
			const T s,
			const T tau,
			const label i,
			const label j,
			const label k,
			const label l
		) const;


	public:

		// Static data members


		// Constructors

			//- Construct from matrix
		EigenSolver(const SquareMatrix<T>& mtx);


		// Destructor - default


		// Member Functions

			//- Return nth eigen value
		T eigenValue(const label n) const;

		// Return nth eigen vector
		const List<T>& eigenVector(const label n) const;

	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <EigenSolver.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_EigenSolver_Header
