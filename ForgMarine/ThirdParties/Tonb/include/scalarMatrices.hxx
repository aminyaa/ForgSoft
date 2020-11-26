#ifndef _scalarMatrices_Header
#define _scalarMatrices_Header

#include <RectangularMatrix.hxx>
#include <SquareMatrix.hxx>
#include <DiagonalMatrix.hxx>

#include <scalarSquareMatrix.hxx>
#include <scalarField.hxx>
#include <labelList.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	typedef RectangularMatrix<scalar> scalarRectangularMatrix;
	typedef DiagonalMatrix<scalar> scalarDiagonalMatrix;

	void multiply
	(
		scalarRectangularMatrix& answer,         // value changed in return
		const scalarRectangularMatrix& A,
		const scalarRectangularMatrix& B
	);

	void multiply
	(
		scalarRectangularMatrix& answer,         // value changed in return
		const scalarRectangularMatrix& A,
		const scalarRectangularMatrix& B,
		const scalarRectangularMatrix& C
	);

	void multiply
	(
		scalarRectangularMatrix& answer,         // value changed in return
		const scalarRectangularMatrix& A,
		const scalarDiagonalMatrix& B,
		const scalarRectangularMatrix& C
	);

	//- Return the inverse of matrix A using SVD
	scalarRectangularMatrix SVDinv
	(
		const scalarRectangularMatrix& A,
		scalar minCondition = 0
	);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_scalarMatrices_Header
