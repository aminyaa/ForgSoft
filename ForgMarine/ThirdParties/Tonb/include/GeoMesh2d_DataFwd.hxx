#pragma once
#ifndef _GeoMesh2d_DataFwd_Header
#define _GeoMesh2d_DataFwd_Header

#include <Mesh2d_ElementFwd.hxx>

namespace tnbLib
{

	// Forward Declarations
	template<class ElementType>
	class GeoMesh_Data;

	typedef GeoMesh_Data<Mesh2d_Element>
		GeoMesh2d_Data;
}

#endif // !_GeoMesh2d_DataFwd_Header