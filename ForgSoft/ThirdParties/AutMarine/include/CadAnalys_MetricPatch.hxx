#pragma once
#ifndef _CadAnalys_MetricPatch_Header
#define _CadAnalys_MetricPatch_Header

#include <Global_Done.hxx>
#include <CadAnalys_MetricPatch_Info.hxx>

namespace AutLib
{

	// Forward Declarations
	class CadAnalys_ApprxSurfMetric;

	template<class SurfType>
	class CadAnalys_MetricPatch
		: public Global_Done
	{

		typedef CadAnalys_MetricPatch_Info info;
		typedef Numeric_AdaptIntegrationInfo intgInfo;

		/*Private Data*/

		std::shared_ptr<SurfType> theSurface_;
		std::shared_ptr<CadAnalys_ApprxSurfMetric> theMetric_;

		std::shared_ptr<info> theInfo_;

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

	public:

		CadAnalys_MetricPatch(const std::shared_ptr<info>& theInfo)
			: theInfo_(theInfo)
		{}

		CadAnalys_MetricPatch
		(
			const std::shared_ptr<SurfType>& theSurface,
			const std::shared_ptr<CadAnalys_ApprxSurfMetric>& theMetric, 
			const std::shared_ptr<info>& theInfo
		)
			: theInfo_(theInfo)
			, theSurface_(theSurface)
			, theMetric_(theMetric)
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
	};
}

#include <CadAnalys_MetricPatchI.hxx>

#endif // !_CadAnalys_MetricPatch_Header
