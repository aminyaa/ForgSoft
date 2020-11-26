#pragma once
#ifndef _Mesh2d_CurveAnIso_Header
#define _Mesh2d_CurveAnIso_Header

#include <Mesh_Curve.hxx>
#include <Mesh2d_CurveEntityAnIso.hxx>

namespace tnbLib
{
	typedef Mesh_Curve<Geom2d_Curve, Geo2d_MetricPrcsrAnIso>
		Mesh2d_CurveAnIso;
}

#endif // !_Mesh2d_CurveAnIso_Header