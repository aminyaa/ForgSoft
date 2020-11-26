#pragma once
#ifndef _Mesh_CurveOptmPoint_Correction_Header
#define _Mesh_CurveOptmPoint_Correction_Header

#include <Global_Done.hxx>
#include <Mesh_CurveEntity.hxx>
#include <Mesh_CurveOptmPoint_Correction_Info.hxx>

#include <memory>

namespace tnbLib
{

	class Mesh_CurveOptmPoint_Correction_Base
	{

		typedef Mesh_CurveOptmPoint_Correction_Info info;

		/*Private Data*/

		Standard_Real theU0_;
		Standard_Real theGuess_;

		Standard_Real theCorrected_;

		const info& theInfo_;

	protected:

		Mesh_CurveOptmPoint_Correction_Base
		(
			const Standard_Real theU0,
			const Standard_Real theGuess,
			const info& theInfo
		)
			: theU0_(theU0)
			, theGuess_(theGuess)
			, theInfo_(theInfo)
			, theCorrected_(0)
		{}

		auto& ChangeCorrected()
		{
			return theCorrected_;
		}

	public:

		const auto& Info() const
		{
			return theInfo_;
		}

		auto Corrected() const
		{
			return theCorrected_;
		}

		//- macros

		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, U0)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Guess)
	};

	template<class gCurveType, class MetricPrcsrType>
	class Mesh_CurveOptmPoint_Correction
		: public Global_Done
		, public Mesh_CurveOptmPoint_Correction_Base
	{

		typedef Mesh_CurveEntity<gCurveType, MetricPrcsrType> entity;
		typedef Mesh_CurveOptmPoint_Correction_Info info;

		/*Private Data*/

		const entity& theCurve_;

	public:

		Mesh_CurveOptmPoint_Correction
		(
			const Standard_Real theU0,
			const Standard_Real theGuess,
			const entity& theCurve,
			const info& theInfo
		)
			: Mesh_CurveOptmPoint_Correction_Base(theU0, theGuess, theInfo)
			, theCurve_(theCurve)
		{}

		const auto& Entity() const
		{
			return theCurve_;
		}

		void Perform();
	};
}

#include <Mesh_CurveOptmPoint_CorrectionI.hxx>

#endif // !_Mesh_CurveOptmPoint_Correction_Header