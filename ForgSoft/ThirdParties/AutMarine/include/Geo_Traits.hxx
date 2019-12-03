#pragma once
#ifndef _Geo_Traits_Header
#define _Geo_Traits_Header

#include <Traits.hxx>

class gp_Trsf2d;
class gp_Trsf;

namespace AutLib
{

	class Pnt2d;
	class Pnt3d;

	template<class Point> struct transform_point_type {};
	template<> struct transform_point_type<Pnt2d> { typedef gp_Trsf2d type; };
	template<> struct transform_point_type<Pnt3d> { typedef gp_Trsf type; };
}

#endif // !_Geo_Traits_Header
