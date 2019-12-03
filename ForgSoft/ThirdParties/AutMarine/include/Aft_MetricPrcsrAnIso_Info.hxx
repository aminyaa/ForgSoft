#pragma once
#ifndef _Aft_MetricPrcsrAnIso_Info_Header
#define _Aft_MetricPrcsrAnIso_Info_Header

#include <Standard_TypeDef.hxx>
#include <Global_AccessMethod.hxx>

#include <memory>

namespace AutLib
{

	// Forward Declarations
	class Numeric_AdaptIntegrationInfo;

	class Aft_MetricPrcsrAnIso_Info
	{

		/*private Data*/

		Standard_Integer theNbSamples_;
		Standard_Integer theNbIters_;

		Standard_Real theTolerance_;

		std::shared_ptr<Numeric_AdaptIntegrationInfo> theInfo_;

	public:

		static const Standard_Integer DEFAULT_NB_SAMPLES;
		static const Standard_Integer DEFAULT_NB_ITERS;

		static const Standard_Real DEFAULT_TOLERANCE;

		Aft_MetricPrcsrAnIso_Info()
			: theNbSamples_(DEFAULT_NB_SAMPLES)
			, theNbIters_(DEFAULT_NB_ITERS)
			, theTolerance_(DEFAULT_TOLERANCE)
		{}

		const std::shared_ptr<Numeric_AdaptIntegrationInfo>& IntegInfo() const
		{
			return theInfo_;
		}

		void OverrideIntegInfo(const std::shared_ptr<Numeric_AdaptIntegrationInfo>& theInfo)
		{
			theInfo_ = theInfo;
		}

		//- macros

		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Integer, NbSamples)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Integer, NbIters)

			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Tolerance)
	};
}

#endif // !_Aft_MetricPrcsrAnIso_Info_Header
