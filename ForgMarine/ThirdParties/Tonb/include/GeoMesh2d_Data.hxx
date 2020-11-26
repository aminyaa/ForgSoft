#pragma once
#ifndef _GeoMesh2d_Data_Header
#define _GeoMesh2d_Data_Header

#include <GeoMesh_Data.hxx>
#include <Entity2d_Triangulation.hxx>
#include <Mesh2d_Element.hxx>
#include <Mesh2d_Node.hxx>
#include <Mesh2d_Edge.hxx>

namespace tnbLib
{
	typedef GeoMesh_Data<Mesh2d_Element>
		GeoMesh2d_Data;

	template<>
	void GeoMesh2d_Data::Construct(const triangulation& theTriangulation);
}

#endif // !_GeoMesh2d_Data_Header