#pragma once
#ifndef _Mesh_Curve_Info_Header
#define _Mesh_Curve_Info_Header

#include <Standard_TypeDef.hxx>
#include <Global_AccessMethod.hxx>

#include <memory>

namespace tnbLib
{

	// Forward Declarations
	class NumAlg_AdaptiveInteg_Info;
	class NumAlg_NewtonSolver_Info;
	class Mesh_CurveOptmPoint_Correction_Info;

	class Mesh_Curve_Info
	{

		typedef NumAlg_AdaptiveInteg_Info intgInfo;
		typedef NumAlg_NewtonSolver_Info iterInfo;
		typedef Mesh_CurveOptmPoint_Correction_Info corrInfo;

		/*Private Data*/

		Standard_Integer theLengthCalcMaxLevel_;
		Standard_Real theUnderRelaxation_;

		Standard_Boolean IgnoreNonConvergency_;

		std::shared_ptr<intgInfo> theOverallLengthIntgInfo_;
		std::shared_ptr<intgInfo> theNewtonIntgInfo_;

		std::shared_ptr<iterInfo> theNewtonIterInfo_;

		std::shared_ptr<corrInfo> theCorrAlgInfo_;

	public:

		static const Standard_Integer DEFAULT_MAX_LEVEL_LENGTH_CALC;
		static const Standard_Real DEFAULT_UNDER_RELAXATION;

		Mesh_Curve_Info()
			: theLengthCalcMaxLevel_(DEFAULT_MAX_LEVEL_LENGTH_CALC)
			, theUnderRelaxation_(DEFAULT_UNDER_RELAXATION)
			, IgnoreNonConvergency_(Standard_True)
		{}

		auto IgnoreNonConvergency() const
		{
			return IgnoreNonConvergency_;
		}

		const auto& OverallLengthIntgInfo() const
		{
			return theOverallLengthIntgInfo_;
		}

		const auto& NewtonIntgInfo() const
		{
			return theNewtonIntgInfo_;
		}

		const auto& NewtonIterInfo() const
		{
			return theNewtonIterInfo_;
		}

		const auto& CorrAlgInfo() const
		{
			return theCorrAlgInfo_;
		}

		void SetIgnoreNonConvergency(const Standard_Boolean theCondition)
		{
			IgnoreNonConvergency_ = theCondition;
		}

		void OverrideOverallLengthIntgInfo(const std::shared_ptr<intgInfo>& theInfo)
		{
			theOverallLengthIntgInfo_ = theInfo;
		}

		void OverrideNewtonIntgInfo(const std::shared_ptr<intgInfo>& theInfo)
		{
			theNewtonIntgInfo_ = theInfo;
		}

		void OverrideNewtonIterInfo(const std::shared_ptr<iterInfo>& theInfo)
		{
			theNewtonIterInfo_ = theInfo;
		}

		void OverrideCorrAlgInfo(const std::shared_ptr<corrInfo>& theInfo)
		{
			theCorrAlgInfo_ = theInfo;
		}

		//- Macros

		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Integer, LengthCalcMaxLevel)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, UnderRelaxation)

	};
}

#endif // !_Mesh_Curve_Info_Header
