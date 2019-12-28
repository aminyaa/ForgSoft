#pragma once
#ifndef _Geo3d_ApprxCurve_Header
#define _Geo3d_ApprxCurve_Header

#include <Geo2d_ApprxCurve.hxx>
#include <Entity3d_Chain.hxx>

#include <Standard_Handle.hxx>

class Geom_Curve;

#include <memory>

namespace AutLib
{

	typedef Geo_ApprxCurve<Handle(Geom_Curve), true>
		Geo3d_ApprxCurve;
}

#endif // !_Geo3d_ApprxCurve_Header
