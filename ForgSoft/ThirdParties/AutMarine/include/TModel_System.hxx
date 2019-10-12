#pragma once
#ifndef _TModel_System_Header
#define _TModel_System_Header

#include <memory>

namespace AutLib
{

	// Forward Declarations
	class Cad_CurveInfo;
	class TModel_FixWireInfo;

	namespace tModelSys
	{

		extern std::shared_ptr<Cad_CurveInfo> par_curve_info;
		extern std::shared_ptr<Cad_CurveInfo> curve_info;


		//- Fix wire
		extern std::shared_ptr<TModel_FixWireInfo> fix_wire;

		void InitRunTime();
	}
}

#endif // !_TModel_System_Header
