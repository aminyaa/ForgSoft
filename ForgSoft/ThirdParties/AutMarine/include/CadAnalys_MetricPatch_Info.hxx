#pragma once
#ifndef _CadAnalys_MetricPatch_Info_Header
#define _CadAnalys_MetricPatch_Info_Header

#include <Global_Verbose.hxx>
#include <Global_AccessMethod.hxx>

#include <memory>

namespace AutLib
{

	// Forward Declarations
	class Numeric_AdaptIntegrationInfo;

	class CadAnalys_MetricPatch_Info
		: public Global_Verbose
	{

		typedef Numeric_AdaptIntegrationInfo intgInfo;

		/*Private Data*/

		Standard_Real theMaxDet_;

		Standard_Integer theNbSegmentsU_;
		Standard_Integer theNbSegmentsV_;

		std::shared_ptr<intgInfo> theIntgInfo_;

	public:

		static const Standard_Real DEFAULT_MAX_DETERMINANT;

		static const Standard_Integer DEFAULT_NB_SEGMENTS_U;
		static const Standard_Integer DEFAULT_NB_SEGMENTS_V;

		CadAnalys_MetricPatch_Info();

		//- Macros
		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, MaxDet)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Integer, NbSegmentsU)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Integer, NbSegmentsV)

			GLOBAL_ACCESS_SINGLE(std::shared_ptr<intgInfo>, IntgInfo)

	};
}

#endif // !_CadAnalys_MetricPatch_Info_Header
