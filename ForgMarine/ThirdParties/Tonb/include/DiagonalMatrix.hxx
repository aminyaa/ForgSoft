#pragma once
#ifndef _DiagonalMatrix_Header
#define _DiagonalMatrix_Header

#include <List.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * *  * * * * * * Class Forward declaration  * * * * * * * * * * * //

	template<class Form, class Type> class Matrix;

	/*---------------------------------------------------------------------------*\
							   Class DiagonalMatrix Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class DiagonalMatrix
		: public List<Type>
	{
	public:

		// Constructors

			//- Construct from diagonal component of a Matrix
		template<class Form>
		DiagonalMatrix<Type>(const Matrix<Form, Type>&);

		//- Construct empty from size
		DiagonalMatrix<Type>(const label size);

		//- Construct from size and a value
		DiagonalMatrix<Type>(const label, const Type&);


		// Member functions

			//- Invert the diaganol matrix and return itself
		DiagonalMatrix<Type>& invert();
	};


	// Global functions

	//- Return the diagonal Matrix inverse
	template<class Type>
	DiagonalMatrix<Type> inv(const DiagonalMatrix<Type>&);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <DiagonalMatrixI.hxx>

#endif // !_DiagonalMatrix_Header
