#pragma once
#ifndef _Mesh2d_PlnCurveFwd_Header
#define _Mesh2d_PlnCurveFwd_Header

#include <Geo2d_SizeFunctionFwd.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class CurveType, class SizeFun, class MetricFun>
	class Mesh_PlnCurve;

	class Pln_Curve;

	typedef Mesh_PlnCurve<Pln_Curve, Geo2d_SizeFunction, void>
		Mesh2d_PlnCurve;
}

#endif // !_Mesh2d_PlnCurveFwd_Header
