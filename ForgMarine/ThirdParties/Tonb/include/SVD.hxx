#pragma once
#ifndef _SVD_Header
#define _SVD_Header

#include <scalarMatrices.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //


	/*---------------------------------------------------------------------------*\
						  Class SVD Declaration
	\*---------------------------------------------------------------------------*/

	class SVD
	{
		// Private data

			//- Rectangular matrix with the same dimensions as the input
		scalarRectangularMatrix U_;

		//- square matrix V
		scalarRectangularMatrix V_;

		//- The singular values
		DiagonalMatrix<scalar> S_;

		//- The matrix product V S^(-1) U^T
		scalarRectangularMatrix VSinvUt_;

		//- The number of zero singular values
		label nZeros_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		SVD(const SVD&);

		//- Disallow default bitwise assignment
		void operator=(const SVD&);

		template<class T>
		const T sign(const T& a, const T& b);


	public:

		// Constructors

			//- Construct from a rectangular Matrix
		SVD(const scalarRectangularMatrix& A, const scalar minCondition = 0);


		// Access functions

			//- Return U
		const scalarRectangularMatrix& U() const;

		//- Return the square matrix V
		const scalarRectangularMatrix& V() const;

		//- Return the singular values
		const scalarDiagonalMatrix& S() const;

		//- Return VSinvUt (the pseudo inverse)
		const scalarRectangularMatrix& VSinvUt() const;

		//- Return the number of zero singular values
		label nZeros() const;

		//- Return the minimum non-zero singular value
		scalar minNonZeroS() const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <SVDI.hxx>

#endif // !_SVD_Header
