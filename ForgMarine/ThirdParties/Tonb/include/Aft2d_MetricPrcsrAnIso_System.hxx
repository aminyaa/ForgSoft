#pragma once
#ifndef _Aft2d_MetricPrcsrAnIso_System_Header
#define _Aft2d_MetricPrcsrAnIso_System_Header

#include <memory>

namespace tnbLib
{

	// Forward Declarations
	class NumAlg_AdaptiveInteg_Info;
	class Aft_MetricPrcsrAnIso_Info;

	namespace sysLib
	{

		extern std::shared_ptr<NumAlg_AdaptiveInteg_Info> gl_metric_prcsr_aniso_intg_info;
		extern std::shared_ptr<Aft_MetricPrcsrAnIso_Info> gl_aft_metric_prcsr_aniso_info;

		void init_gl_aft_metric_prcsr_aniso_info();
	}


}

#endif // !_Aft2d_MetricPrcsrAnIso_System_Header