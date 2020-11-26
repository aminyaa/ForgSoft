#pragma once
#ifndef _Geo_ApprxCurve_System_Header
#define _Geo_ApprxCurve_System_Header

#include <memory>

namespace tnbLib
{

	// Forward Declarations
	class Geo_ApprxCurve_Info;

	namespace sysLib
	{

		extern std::shared_ptr<Geo_ApprxCurve_Info> gl_approx_curve2d_info;
		extern std::shared_ptr<Geo_ApprxCurve_Info> gl_approx_curve3d_info;

		void init_gl_approx_curve_info();
	}
}

#endif // !_Geo_ApprxCurve_System_Header
