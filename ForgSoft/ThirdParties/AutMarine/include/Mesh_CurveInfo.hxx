#pragma once
#ifndef _Mesh_CurveInfo_Header
#define _Mesh_CurveInfo_Header

#include <Standard_TypeDef.hxx>

#include <memory>

namespace AutLib
{

	// Forward Declarations
	class Numeric_AdaptIntegrationInfo;
	class Numeric_NewtonSolverInfo;
	class Mesh_CurveOptmPoint_CorrectionInfo;

	class Mesh_CurveInfo
	{

		typedef Numeric_AdaptIntegrationInfo intgInfo;
		typedef Numeric_NewtonSolverInfo iterInfo;
		typedef Mesh_CurveOptmPoint_CorrectionInfo corrInfo;

		/*Private Data*/

		Standard_Integer theMaxLevel_LengthCalc_;
		Standard_Real theUnderRelaxation_;

		Standard_Boolean IgnoreNonConvergency_;

		std::shared_ptr<intgInfo> theOverallLengthIntgInfo_;
		std::shared_ptr<intgInfo> theNewtonIntgInfo_;

		std::shared_ptr<iterInfo> theNewtonIterInfo_;

		std::shared_ptr<corrInfo> theCorrAlgInfo_;

	public:

		static const Standard_Integer DEFAULT_MAX_LEVEL_LENGTH_CALC;
		static const Standard_Real DEFAULT_UNDER_RELAXATION;

		Mesh_CurveInfo()
			: theMaxLevel_LengthCalc_(DEFAULT_MAX_LEVEL_LENGTH_CALC)
			, theUnderRelaxation_(DEFAULT_UNDER_RELAXATION)
			, IgnoreNonConvergency_(Standard_False)
		{}

		Standard_Integer MaxLevel_LengthCalc() const
		{
			return theMaxLevel_LengthCalc_;
		}

		Standard_Real UnderRelaxation() const
		{
			return theUnderRelaxation_;
		}

		Standard_Boolean IgnoreNonConvergency() const
		{
			return IgnoreNonConvergency_;
		}

		const std::shared_ptr<intgInfo>& OverallLengthIntgInfo() const
		{
			return theOverallLengthIntgInfo_;
		}

		const std::shared_ptr<intgInfo>& NewtonIntgInfo() const
		{
			return theNewtonIntgInfo_;
		}

		const std::shared_ptr<iterInfo>& NewtonIterInfo() const
		{
			return theNewtonIterInfo_;
		}

		const std::shared_ptr<corrInfo>& CorrAlgInfo() const
		{
			return theCorrAlgInfo_;
		}

		void SetMaxLevel_LengthCalc(const Standard_Integer theValue)
		{
			theMaxLevel_LengthCalc_ = theValue;
		}

		void SetUnderRelaxation(const Standard_Real theUR)
		{
			theUnderRelaxation_ = theUR;
		}

		void SetIgnoreNonConvergency(const Standard_Boolean NonConvergency)
		{
			IgnoreNonConvergency_ = NonConvergency;
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
	};
}

#endif // !_Mesh_CurveInfo_Header
