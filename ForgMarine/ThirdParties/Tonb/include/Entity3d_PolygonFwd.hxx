#pragma once
#ifndef _Entity3d_PolygonFwd_Header
#define _Entity3d_PolygonFwd_Header

namespace tnbLib
{

	// Forward Declarations

	template<class Point>
	class Entity_Polygon;

	class Pnt3d;

	typedef Entity_Polygon<Pnt3d> Entity3d_Polygon;
}

#endif // !_Entity3d_PolygonFwd_Header
