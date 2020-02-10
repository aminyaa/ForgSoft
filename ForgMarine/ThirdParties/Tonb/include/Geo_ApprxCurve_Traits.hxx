#pragma once
#ifndef _Geo_ApprxCurve_Traits_Header
#define _Geo_ApprxCurve_Traits_Header

#include <gp_Pnt2d.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec2d.hxx>
#include <gp_Vec.hxx>

#include <memory>

class Geom2d_Curve;
class Geom_Curve;

namespace tnbLib
{

	template<class CurveType>
	struct Geo_ApprxCurve_Traits
	{};

	template<>
	struct Geo_ApprxCurve_Traits<Geom2d_Curve>
	{
		typedef gp_Pnt2d ptType;
		typedef gp_Vec2d vtType;
	};

	template<>
	struct Geo_ApprxCurve_Traits<Geom_Curve>
	{
		typedef gp_Pnt ptType;
		typedef gp_Vec vtType;
	};
}

#endif // !_Geo_ApprxCurve_Traits_Header
