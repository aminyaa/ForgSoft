#pragma once
#ifndef _Entity2d_PolygonFwd_Header
#define _Entity2d_PolygonFwd_Header

namespace AutLib
{

	// Forward Declarations
	template<class Point>
	class Entity_Polygon;

	class Pnt2d;

	typedef Entity_Polygon<Pnt2d> Entity2d_Polygon;
}

#endif // !_Entity2d_PolygonFwd_Header
