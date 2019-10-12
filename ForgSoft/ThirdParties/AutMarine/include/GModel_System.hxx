#pragma once
#ifndef _GModel_System_Header
#define _GModel_System_Header


#include <memory>

namespace AutLib
{

	// Forward Declarations
	class Cad_CurveInfo;
	class GModel_FixWireInfo;

	namespace gModelSys
	{
		extern std::shared_ptr<Cad_CurveInfo> par_curve_info;
		extern std::shared_ptr<Cad_CurveInfo> curve_info;


		//- Fix wire
		extern std::shared_ptr<GModel_FixWireInfo> fix_wire;

		void InitRunTime();
	}
}

#endif // !_GModel_System_Header
