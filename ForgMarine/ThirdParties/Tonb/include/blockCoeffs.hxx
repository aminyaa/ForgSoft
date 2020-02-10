#pragma once
#ifndef _blockCoeffs_Header
#define _blockCoeffs_Header

#include <scalarBlockCoeff.hxx>
#include <sphericalTensorBlockCoeff.hxx>
#include <symmTensorBlockCoeff.hxx>
#include <tensorBlockCoeff.hxx>
#include <scalarField.hxx>

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef BlockCoeff<scalar> scalarBlockCoeff;
	typedef BlockCoeff<vector> vectorBlockCoeff;
	typedef BlockCoeff<sphericalTensor> sphericalTensorBlockCoeff;
	typedef BlockCoeff<symmTensor> symmTensorBlockCoeff;
	typedef BlockCoeff<tensor> tensorBlockCoeff;


	/* * * * * * * * * * * * * * * * Global functions  * * * * * * * * * * * * * */

	template<class Type>
	scalar sumMult
	(
		const Field<Type>& f1,
		const Field<Type>& f2
	)
	{
		Type result = pTraits<Type>::zero;

		typename BlockCoeff<Type>::multiply mult;

		for (register label i = 0; i < f1.size(); i++)
		{
			result += mult(f1[i], f2[i]);
		}

		return cmptSum(result);
	}


	template<class Type>
	scalar gSumMult
	(
		const Field<Type>& f1,
		const Field<Type>& f2
	)
	{
		scalar SumProd = sumMult(f1, f2);
		reduce(SumProd, sumOp<scalar>());
		return SumProd;
	}


	template<>
	inline scalar sumMult
	(
		const scalarField& f1,
		const scalarField& f2
	)
	{
		return sumProd(f1, f2);
	}


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_blockCoeffs_Header
