#pragma once
#ifndef _Mesh_MetricMapTraits_Header
#define _Mesh_MetricMapTraits_Header

#include <Pnt2d.hxx>

namespace AutLib
{

	template<class Point>
	struct metric_map_traits {};

	// Forward Declarations
	class Entity2d_Metric1;

	template<>
	struct metric_map_traits<Pnt2d> { typedef Entity2d_Metric1 type; };
}

#endif // !_Mesh_MetricMapTraits_Header