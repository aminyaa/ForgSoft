#pragma once
#ifndef _Geo_CascadeTraits_Header
#define _Geo_CascadeTraits_Header

#include <Pnt2d.hxx>
#include <Pnt3d.hxx>

class Geom2d_Curve;
class Geom2d_Circle;
class Geom_Curve;
class gp_Vec2d;
class gp_Vec;

namespace AutLib
{

	namespace cascadeLib
	{

		template<class T> struct pt_type_from_curve {};

		template<> struct pt_type_from_curve<Geom2d_Curve> { typedef Pnt2d ptType; };
		template<> struct pt_type_from_curve<Geom2d_Circle> { typedef Pnt2d ptType; };
		template<> struct pt_type_from_curve<Geom_Curve> { typedef Pnt3d ptType; };

		template<class T> struct vec_type_from_point {};

		template<> struct vec_type_from_point<Pnt2d> { typedef gp_Vec2d vcType; };
		template<> struct vec_type_from_point<Pnt3d> { typedef gp_Vec vcType; };
	}
}

#endif // !_Geo_CascadeTraits_Header
