#pragma once
#ifndef _Geo_MetricPrcsrAnIso_Info_Header
#define _Geo_MetricPrcsrAnIso_Info_Header

#include <Standard_TypeDef.hxx>
#include <Global_AccessMethod.hxx>

#include <memory>

namespace tnbLib
{

	// Forward Declarations
	class NumAlg_AdaptiveInteg_Info;

	class Geo_MetricPrcsrAnIso_Info
	{

		/*Private Data*/

		Standard_Integer theNbSamples_;

		std::shared_ptr<NumAlg_AdaptiveInteg_Info> theIntgInfo_;

	public:

		static const Standard_Integer DEFAULT_NB_SAMPLES;

		Geo_MetricPrcsrAnIso_Info()
			: theNbSamples_(DEFAULT_NB_SAMPLES)
		{}


		const std::shared_ptr<NumAlg_AdaptiveInteg_Info>& IntegInfo() const
		{
			return theIntgInfo_;
		}

		void OverrideIntegInfo
		(
			const std::shared_ptr<NumAlg_AdaptiveInteg_Info>& theInfo
		)
		{
			theIntgInfo_ = theInfo;
		}

		//- Macros
		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Integer, NbSamples)
	};
}

#endif // !_Geo_MetricPrcsrAnIso_Info_Header