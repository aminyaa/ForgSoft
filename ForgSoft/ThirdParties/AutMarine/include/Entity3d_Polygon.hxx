#pragma once
#ifndef _Entity3d_Polygon_Header
#define _Entity3d_Polygon_Header

#include <Pnt3d.hxx>
#include <Entity_Polygon.hxx>

namespace AutLib
{

	typedef Entity_Polygon<Pnt3d> Entity3d_Polygon;

	template<>
	void Entity3d_Polygon::ExportToPlt(std::fstream& File) const;

	template<>
	void Entity3d_Polygon::ExportToPlt(OFstream& File) const;
}

#endif // !_Entity3d_Polygon_Header
