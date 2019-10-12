#pragma once
#ifndef _Entity2d_Polygon_Header
#define _Entity2d_Polygon_Header

#include <Pnt2d.hxx>
#include <Entity_Polygon.hxx>

namespace AutLib
{

	typedef Entity_Polygon<Pnt2d> Entity2d_Polygon;

	template<>
	void Entity2d_Polygon::ExportToPlt(std::fstream& File) const;

}

#endif // !_Entity2d_Polygon_Header
