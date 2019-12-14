#pragma once
#ifndef _Cad2d_Plane_System_Header
#define _Cad2d_Plane_System_Header

#include <memory>

namespace AutLib
{

	// Forward Declarations
	class Cad_CurveInfo;
	class Cad2d_PlaneInfo;
	class Geo_ApprxCurveInfo;

	namespace sysLib
	{
		extern std::shared_ptr<Geo_ApprxCurveInfo> gl_pln_approx_curve_info;

		extern std::shared_ptr<Cad_CurveInfo> gl_pln_curve_info;
		extern std::shared_ptr<Cad2d_PlaneInfo> gl_plane_info;

		void init_pln_curve_info();

		void init_plane_info();

		void init_pln_approx_curve_info();
	}
}

#endif // !_Cad2d_Plane_System_Header
