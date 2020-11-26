#pragma once
#ifndef _tensorBlockCoeffTwoNorm_Header
#define _tensorBlockCoeffTwoNorm_Header

#include <blockCoeffs.hxx>
#include <blockCoeffNorms.hxx>
#include <BlockCoeffNorm.hxx>
#include <BlockCoeffTwoNorm.hxx>
#include <runTimeSelectionTables.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{


	/*---------------------------------------------------------------------------*\
							Class BlockCoeffTwoNorm Declaration
	\*---------------------------------------------------------------------------*/

	template<>
	inline scalar BlockCoeffTwoNorm<tensor>::normalize
	(
		const BlockCoeff<tensor>& a
	)
	{
		if (a.activeType() == BlockCoeff<tensor>::SCALAR)
		{
			return mag(a.asScalar());
		}
		else if (a.activeType() == BlockCoeff<tensor>::LINEAR)
		{
			return mag(a.asLinear());
		}
		else
		{
			FatalErrorIn
			(
				"scalar BlockCoeffTwoNorm<Type>(const BlockCoeff<Type>& a)"
			) << "Unknown type" << abort(FatalError);

			return 0;
		}
	}


	template<>
	inline void BlockCoeffTwoNorm<tensor>::coeffMag
	(
		const CoeffField<tensor>& a,
		Field<scalar>& b
	)
	{
		if (a.activeType() == BlockCoeff<tensor>::SCALAR)
		{
			b = mag(a.asScalar());
		}
		else if (a.activeType() == BlockCoeff<tensor>::LINEAR)
		{
			b = mag(a.asLinear());
		}
		else
		{
			FatalErrorIn
			(
				"scalar BlockCoeffTwoNorm<Type>(const BlockCoeff<Type>& b)"
			) << "Unknown type" << abort(FatalError);
		}
	}


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_tensorBlockCoeffTwoNorm_Header
