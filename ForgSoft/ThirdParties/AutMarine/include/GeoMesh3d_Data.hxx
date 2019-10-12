#pragma once
#ifndef _GeoMesh2d_Data_Header
#define _GeoMesh2d_Data_Header

#include <GeoMesh_Data.hxx>
#include <Entity3d_Tetrahedralization.hxx>
#include <Mesh3d_Element.hxx>
#include <Mesh3d_Node.hxx>
#include <Mesh3d_Edge.hxx>
#include <Mesh3d_Facet.hxx>

namespace AutLib
{
	typedef GeoMesh_Data<Mesh3d_Element>
		GeoMesh3d_Data;

	template<>
	void GeoMesh3d_Data::Construct(const triangulation& theTriangulation);
}

#endif // !_GeoMesh2d_Data_Header
