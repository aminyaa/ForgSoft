#pragma once
#ifndef _Geo_MetricFunctionTraits_Header
#define _Geo_MetricFunctionTraits_Header

#include <Pnt2d.hxx>
#include <Pnt3d.hxx>

namespace AutLib
{

	// Forward Declarations
	class Entity2d_Metric1;
	class Entity2d_Metric2;

	template<class T> struct point_type_from_metric{};

	template<> struct point_type_from_metric<Entity2d_Metric1> { typedef Pnt2d ptType; };
	template<> struct point_type_from_metric<Entity2d_Metric2> { typedef Pnt2d ptType; };

	template<class T> struct metric_type_from_point{};

	template<> struct metric_type_from_point<Pnt2d> { typedef Entity2d_Metric1 metricType; };
}

#endif // !_Geo_MetricFunctionTraits_Header
