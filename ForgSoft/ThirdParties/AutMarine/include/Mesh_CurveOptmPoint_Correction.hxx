#pragma once
#ifndef _Mesh_CurveOptmPoint_Correction_Header
#define _Mesh_CurveOptmPoint_Correction_Header

#include <Global_Done.hxx>
#include <Mesh_CurveEntity.hxx>
#include <Mesh_CurveOptmPoint_CorrectionInfo.hxx>

#include <memory>

namespace AutLib
{

	template<class CurveType, class SizeMap>
	class Mesh_CurveOptmPoint_Correction
		: public Global_Done
	{

		typedef Mesh_CurveEntity<CurveType, SizeMap> entity;
		typedef Mesh_CurveOptmPoint_CorrectionInfo info;

		/*Private Data*/

		Standard_Real theU0_;
		Standard_Real theGuess_;

		const entity& theCurve_;

		const info& theInfo_;

		Standard_Real theCorrected_;

	public:

		Mesh_CurveOptmPoint_Correction
		(
			const Standard_Real theU0,
			const Standard_Real theGuess,
			const entity& theCurve,
			const info& theInfo
		)
			: theU0_(theU0)
			, theGuess_(theGuess)
			, theCurve_(theCurve)
			, theInfo_(theInfo)
		{}

		Standard_Real U0() const
		{
			return theU0_;
		}

		Standard_Real Guess() const
		{
			return theGuess_;
		}

		Standard_Real Corrected() const
		{
			return theCorrected_;
		}

		const entity& Curve() const
		{
			return theCurve_;
		}

		const info& Info() const
		{
			return theInfo_;
		}

		void Perform();
	};


}

#include <Mesh_CurveOptmPoint_CorrectionI.hxx>

#endif // !_Mesh_CurveOptmPoint_Correction_Header