#pragma once
#ifndef _Aft2d_MetricPrcsrAnIso_System_Header
#define _Aft2d_MetricPrcsrAnIso_System_Header

#include <memory>

namespace AutLib
{

	// Forward Declarations
	class Numeric_AdaptIntegrationInfo;
	class Aft_MetricPrcsrAnIso_Info;

	namespace metricSys
	{

		extern std::shared_ptr<Numeric_AdaptIntegrationInfo> mesh2d_metric_prcsr_aniso_intg_info;
		extern std::shared_ptr<Aft_MetricPrcsrAnIso_Info> mesh2d_aft_metric_prcsr_aniso_info;

		void InitRunTime();
	}

	
}

#endif // !_Aft2d_MetricPrcsrAnIso_System_Header
