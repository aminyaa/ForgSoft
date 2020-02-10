#pragma once
#ifndef _DenseMatrixTools_Header
#define _DenseMatrixTools_Header

#include <SquareMatrix.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						  Class DenseMatrixTools Declaration
	\*---------------------------------------------------------------------------*/

	template<class> class Field;
	template<template<class> class Field, class Type>
	class FieldField;

	namespace DenseMatrixTools
	{
		//- Solve using Gauss Elimination with pivoting.  Destroys matrix and b
		template<class Type>
		static void solve(SquareMatrix<Type>& A, List<Type>& x, List<Type>& b);

		//- Q-R decomposition
		template<class Form, class Type>
		static void qrDecompose
		(
			const label nCols,
			FieldField<Field, Type>& A,
			Matrix<Form, Type>& R
		);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <DenseMatrixTools.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_DenseMatrixTools_Header
