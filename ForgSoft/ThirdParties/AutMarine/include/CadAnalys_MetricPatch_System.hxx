#pragma once
#ifndef _CadAnalys_MetricPatch_System_Header
#define _CadAnalys_MetricPatch_System_Header

#include <Standard_TypeDef.hxx>

#include <memory>

namespace AutLib
{

	// Forward Declarations
	class Numeric_AdaptIntegrationInfo;

	namespace cadAnalysSys
	{

		extern std::shared_ptr<Numeric_AdaptIntegrationInfo> normalize_metric_intg_info;

		void InitRunTime();
	}
}

#endif // !_CadAnalys_MetricPatch_System_Header
