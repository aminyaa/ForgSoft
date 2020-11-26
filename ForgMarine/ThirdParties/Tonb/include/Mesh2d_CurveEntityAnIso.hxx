#pragma once
#ifndef _Mesh2d_CurveEntityAnIso_Header
#define _Mesh2d_CurveEntityAnIso_Header

#include <Mesh_CurveEntity.hxx>
#include <Geo2d_MetricPrcsrAnIso.hxx>

#include <Geom2d_Curve.hxx>

namespace tnbLib
{
	typedef Mesh_CurveEntity<Geom2d_Curve, Geo2d_MetricPrcsrAnIso>
		Mesh2d_CurveEntityAnIso;
}

#endif // !_Mesh2d_CurveEntityAnIso_Header