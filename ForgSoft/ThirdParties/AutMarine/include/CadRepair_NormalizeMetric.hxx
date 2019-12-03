#pragma once
#ifndef _CadRepair_NormalizeMetric_Header
#define _CadRepair_NormalizeMetric_Header

#include <Global_Verbose.hxx>
#include <Global_Done.hxx>
#include <CadRepair_NormalizeMetric_Info.hxx>

namespace AutLib
{

	// Forward Declarations
	class CadAnalys_ApprxSurfMetric;

	template<class SurfType>
	class CadRepair_NormalizeMetric
		: public Global_Done
		, public Global_Verbose
	{

		typedef CadRepair_NormalizeMetric_Info info;
		typedef Numeric_AdaptIntegrationInfo intgInfo;

		/*Private Data*/


		std::shared_ptr<SurfType> theSurface_;
		std::shared_ptr<CadAnalys_ApprxSurfMetric> theMetric_;

		std::shared_ptr<info> theInfo_;

		Standard_Boolean Applied_;
		Standard_Boolean toApply_;


		std::shared_ptr<SurfType> theNormalized_;


		//- private functions and operators

		Standard_Real
			CalcMaxCharLengthU
			(
				intgInfo& theInfo
			) const;

		Standard_Real
			CalcMaxCharLengthV
			(
				intgInfo& theInfo
			) const;

		std::shared_ptr<SurfType>& ChangeNormalized()
		{
			return theNormalized_;
		}

		Standard_Boolean& ChangeApplied()
		{
			return Applied_;
		}

	public:

		CadRepair_NormalizeMetric
		(
			const std::shared_ptr<info>& theInfo
		)
			: theInfo_(theInfo)
			, Applied_(Standard_False)
			, toApply_(Standard_False)
		{}

		CadRepair_NormalizeMetric
		(
			const std::shared_ptr<SurfType>& theSurface,
			const std::shared_ptr<CadAnalys_ApprxSurfMetric>& theMetric,
			const std::shared_ptr<info>& theInfo
		)
			: theInfo_(theInfo)
			, theSurface_(theSurface)
			, theMetric_(theMetric)
			, Applied_(Standard_False)
			, toApply_(Standard_False)
		{}


		const std::shared_ptr<info>& Info() const
		{
			return theInfo_;
		}

		const std::shared_ptr<SurfType>& Surface() const
		{
			return theSurface_;
		}

		const std::shared_ptr<CadAnalys_ApprxSurfMetric>& Metric() const
		{
			return theMetric_;
		}

		const std::shared_ptr<SurfType>& Normalized() const
		{
			return theNormalized_;
		}

		Standard_Boolean Applied() const
		{
			return Applied_;
		}

		Standard_Boolean ToApply() const
		{
			return toApply_;
		}

		void Perform();

		void LoadSurface
		(
			const std::shared_ptr<SurfType>& theSurface
		)
		{
			theSurface_ = theSurface;
		}

		void LoadMetric
		(
			const std::shared_ptr<CadAnalys_ApprxSurfMetric>& theMetric
		)
		{
			theMetric_ = theMetric;
		}

		void ToApply(const Standard_Boolean apply)
		{
			toApply_ = apply;
		}
	};
}

#include <CadRepair_NormalizeMetricI.hxx>

#endif // !_CadRepair_NormalizeMetric_Header
