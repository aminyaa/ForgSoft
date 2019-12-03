#pragma once
#ifndef _Cad2d_Plane_System_Header
#define _Cad2d_Plane_System_Header

#include <memory>

namespace AutLib
{

	// Forward Declarations
	class Cad_CurveInfo;

	namespace sysLib
	{

		extern std::shared_ptr<Cad_CurveInfo> gl_pln_curve_info;

		void init_pln_curve_info();
	}
}

#endif // !_Cad2d_Plane_System_Header
