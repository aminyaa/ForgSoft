#pragma once
#ifndef _GeoMesh2d_MetricBackgroundFwd_Header
#define _GeoMesh2d_MetricBackgroundFwd_Header

#include <GeoMesh2d_DataFwd.hxx>

namespace tnbLib
{

	// Forward Declarations
	template<class MeshData, class Type>
	class GeoMesh_Background;

	class Entity2d_Metric1;

	typedef GeoMesh_Background<GeoMesh2d_Data, Entity2d_Metric1>
		GeoMesh2d_MetricBackground;
}

#endif // !_GeoMesh2d_MetricBackgroundFwd_Header