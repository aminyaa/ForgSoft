#pragma once
#ifndef _Mesh2d_Curve_Header
#define _Mesh2d_Curve_Header

#include <Mesh_Curve.hxx>
#include <Mesh2d_CurveEntity.hxx>

namespace AutLib
{
	typedef Mesh_Curve<Geom2d_Curve, Geo2d_MetricPrcsr>
		Mesh2d_Curve;
}

#endif // !_Mesh2d_Curve_Header
