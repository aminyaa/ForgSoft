#pragma once
#ifndef _CadRepair_NormalizeMetric_Info_Header
#define _CadRepair_NormalizeMetric_Info_Header

#include <Standard_TypeDef.hxx>
#include <Global_AccessMethod.hxx>

#include <memory>

namespace AutLib
{

	// Forward Declarations
	class Numeric_AdaptIntegrationInfo;

	class CadRepair_NormalizeMetric_Info
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

		CadRepair_NormalizeMetric_Info();

		//- Macros
		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, MaxDet)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Integer, NbSegmentsU)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Integer, NbSegmentsV)

			GLOBAL_ACCESS_SINGLE(std::shared_ptr<intgInfo>, IntgInfo)
	};
}

#endif // !_CadRepair_NormalizeMetric_Info_Header
