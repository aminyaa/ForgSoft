#pragma once
#ifndef _Geo_ApprxCurve_System_Header
#define _Geo_ApprxCurve_System_Header

#include <memory>

namespace AutLib
{

	// Forward Declarations
	class Geo_ApprxCurveInfo;

	namespace approxCurveSys
	{

		extern std::shared_ptr<Geo_ApprxCurveInfo> gl_approx_curve2d_info;
		extern std::shared_ptr<Geo_ApprxCurveInfo> gl_approx_curve3d_info;

		void init_approx_curve_info();
	}
}

#endif // !_Geo_ApprxCurve_System_Header
