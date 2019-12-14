#pragma once
#ifndef _CadRepair_ApproxSurfMetric_System_Header
#define _CadRepair_ApproxSurfMetric_System_Header

#include <memory>

namespace AutLib
{

	// Forward Declarations
	class CadRepair_ApproxSurfMetric_Info;

	namespace cadRepairSys
	{

		extern std::shared_ptr<CadRepair_ApproxSurfMetric_Info> gl_surface_metric_approximate_info;
	}
}

#endif // !_CadRepair_ApproxSurfMetric_System_Header
