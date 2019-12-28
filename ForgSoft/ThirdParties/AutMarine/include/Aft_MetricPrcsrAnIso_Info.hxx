#pragma once
#ifndef _Aft_MetricPrcsrAnIso_Info_Header
#define _Aft_MetricPrcsrAnIso_Info_Header

#include <Geo_MetricPrcsrAnIso_Info.hxx>
#include <Global_AccessMethod.hxx>

#include <memory>

namespace AutLib
{

	// Forward Declarations

	class Aft_MetricPrcsrAnIso_Info
		: public Geo_MetricPrcsrAnIso_Info
	{

		/*private Data*/

		Standard_Integer theNbSamples_;
		Standard_Integer theNbIters_;

		Standard_Real theTolerance_;

	public:

		static const Standard_Integer DEFAULT_NB_SAMPLES;
		static const Standard_Integer DEFAULT_NB_ITERS;

		static const Standard_Real DEFAULT_TOLERANCE;

		Aft_MetricPrcsrAnIso_Info()
			: theNbSamples_(DEFAULT_NB_SAMPLES)
			, theNbIters_(DEFAULT_NB_ITERS)
			, theTolerance_(DEFAULT_TOLERANCE)
		{}

		//- macros

		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Integer, NbSamples)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Integer, NbIters)

			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Tolerance)
	};
}

#endif // !_Aft_MetricPrcsrAnIso_Info_Header
