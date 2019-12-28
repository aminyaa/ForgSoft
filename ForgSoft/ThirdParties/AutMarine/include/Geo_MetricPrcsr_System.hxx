#pragma once
#ifndef _Geo_MetricPrcsr_System_Header
#define _Geo_MetricPrcsr_System_Header

#include <memory>

namespace AutLib
{

	// Forward Declarations
	class Geo_MetricPrcsrAnIso_Info;
	class Numeric_AdaptIntegrationInfo;

	namespace metricPrcsrSys
	{

		extern std::shared_ptr<Numeric_AdaptIntegrationInfo> metric_processor_integration_info;
		extern std::shared_ptr<Geo_MetricPrcsrAnIso_Info> metric_processor_aniso_info;

		void initiate_metric_processor_run_time_info();
	}
}

#endif // !_Geo_MetricPrcsr_System_Header
