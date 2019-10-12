#pragma once
#ifndef _Entity2d_Polygon_Tools_Header
#define _Entity2d_Polygon_Tools_Header

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <Entity2d_Polygon_SIDE.hxx>

namespace AutLib
{

	class Entity2d_Polygon_Tools
	{

	public:

		typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
		typedef K::Point_2 Point;

		static Entity2d_Polygon_SIDE CheckSide(const Point& pt, Point* pt_begin, Point* pt_end, K traits = K());
	


	};
}

#endif // !_Entity2d_Polygon_Tools_Header
