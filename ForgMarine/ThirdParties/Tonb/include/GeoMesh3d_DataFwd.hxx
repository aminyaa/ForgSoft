#pragma once
#ifndef _GeoMesh3d_DataFwd_Header
#define _GeoMesh3d_DataFwd_Header

#include <Mesh3d_ElementFwd.hxx>

namespace tnbLib
{

	// Forward Declarations
	template<class ElementType>
	class GeoMesh_Data;

	typedef GeoMesh_Data<Mesh3d_Element>
		GeoMesh3d_Data;
}

#endif // !_GeoMesh3d_DataFwd_Header