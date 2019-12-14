#pragma once
#ifndef _CadRepair_NormalizeMetric_Info_Header
#define _CadRepair_NormalizeMetric_Info_Header

#include <Standard_TypeDef.hxx>
#include <Global_AccessMethod.hxx>
#include <Global_Verbose.hxx>

#include <memory>

namespace AutLib
{

	// Forward Declarations
	class Numeric_AdaptIntegrationInfo;

	class CadRepair_NormalizeMetric_Info
		: public Global_Verbose
	{

		typedef Numeric_AdaptIntegrationInfo intgInfo;

		/*Private Data*/

		Standard_Real theMaxDet_;

		Standard_Integer theNbSegmentsU_;
		Standard_Integer theNbSegmentsV_;

		std::shared_ptr<intgInfo> theIntgInfo_;

		Standard_Boolean toApply_;

	public:

		static const Standard_Real DEFAULT_MAX_DETERMINANT;

		static const Standard_Integer DEFAULT_NB_SEGMENTS_U;
		static const Standard_Integer DEFAULT_NB_SEGMENTS_V;

		CadRepair_NormalizeMetric_Info();

		Standard_Boolean ToApply() const
		{
			return toApply_;
		}

		void ToApply(const Standard_Boolean apply)
		{
			toApply_ = apply;
		}

		void OverrideIntegInfo(const std::shared_ptr<intgInfo>& theInfo)
		{
			theIntgInfo_ = theInfo;
		}

		//- Macros
		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, MaxDet)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Integer, NbSegmentsU)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Integer, NbSegmentsV)

			GLOBAL_ACCESS_SINGLE(std::shared_ptr<intgInfo>, IntgInfo)
	};
}

#endif // !_CadRepair_NormalizeMetric_Info_Header
