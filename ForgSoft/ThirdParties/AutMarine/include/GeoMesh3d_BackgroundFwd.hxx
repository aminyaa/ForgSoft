#pragma once
#ifndef _GeoMesh3d_BackgroundFwd_Header
#define _GeoMesh3d_BackgroundFwd_Header

#include <Standard_TypeDef.hxx>
#include <GeoMesh3d_DataFwd.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class MeshData, class Type>
	class GeoMesh_Background;

	typedef GeoMesh_Background<GeoMesh3d_Data, Standard_Real>
		GeoMesh3d_Background;
}

#endif // !_GeoMesh3d_BackgroundFwd_Header
