#pragma once
#ifndef _tensorBlockCoeffMaxNorm_Header
#define _tensorBlockCoeffMaxNorm_Header

#include <blockCoeffs.hxx>
#include <blockCoeffNorms.hxx>
#include <BlockCoeffNorm.hxx>
#include <BlockCoeffMaxNorm.hxx>
#include <runTimeSelectionTables.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							Class BlockCoeffMaxNorm Declaration
	\*---------------------------------------------------------------------------*/

	template<>
	inline scalar BlockCoeffMaxNorm<tensor>::normalize
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
			return cmptMax(cmptMag(a.asLinear()));
		}
		else
		{
			FatalErrorIn
			(
				"scalar BlockCoeffMaxNorm<tensor>(const BlockCoeff<tensor>& a)"
			) << "Unknown type" << abort(FatalError);

			return 0;
		}
	}


	template<>
	inline void BlockCoeffMaxNorm<tensor>::coeffMag
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
			b = cmptMax(cmptMag(a.asLinear()));
		}
		else
		{
			FatalErrorIn
			(
				"scalar BlockCoeffMaxNorm<Type>(const BlockCoeff<tensor>& b)"
			) << "Unknown type" << abort(FatalError);
		}
	}


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_tensorBlockCoeffMaxNorm_Header
