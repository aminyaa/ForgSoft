#pragma once
#ifndef _SizeMap2d_FullIntAnIsoInfo_Header
#define _SizeMap2d_FullIntAnIsoInfo_Header

#include <Standard_TypeDef.hxx>

#include <memory>

namespace AutLib
{

	// Forward Declarations
	class SizeMap2d_AnIso_OptmPoint_IterCorrectInfo;
	class Numeric_AdaptIntegrationInfo;

	class SizeMap2d_FullIntAnIsoInfo
	{

		typedef SizeMap2d_AnIso_OptmPoint_IterCorrectInfo iterCorrInfo;
		typedef Numeric_AdaptIntegrationInfo adaptIntgInfo;

		/*Private Data*/

		std::shared_ptr<iterCorrInfo> theIterCorrInfo_;
		std::shared_ptr<adaptIntgInfo> theAdaptIntgInfo_;

		Standard_Integer theNbSamples_;

	public:

		static const Standard_Integer DEFAULT_NB_SAMPLES;

		SizeMap2d_FullIntAnIsoInfo();

		const std::shared_ptr<iterCorrInfo>& IterCorrInfo() const
		{
			return theIterCorrInfo_;
		}

		const std::shared_ptr<adaptIntgInfo>& AdaptIntgInfo() const
		{
			return theAdaptIntgInfo_;
		}

		Standard_Integer NbSamples() const
		{
			return theNbSamples_;
		}

		void OverrideIterCorrInfo
		(
			const std::shared_ptr<iterCorrInfo>& theInfo
		)
		{
			theIterCorrInfo_ = theInfo;
		}

		void OverrideAdaptIntgInfo
		(
			const std::shared_ptr<adaptIntgInfo>& theInfo
		)
		{
			theAdaptIntgInfo_ = theInfo;
		}

		void SetNbSamples(const Standard_Integer theNb)
		{
			theNbSamples_ = theNb;
		}
	};
}

#endif // !_SizeMap2d_FullIntAnIsoInfo_Header