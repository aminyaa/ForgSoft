#pragma once
#ifndef _Geo_MetricFunctionTraits_Header
#define _Geo_MetricFunctionTraits_Header

#include <Pnt2d.hxx>
#include <Pnt3d.hxx>

namespace tnbLib
{

	// Forward Declarations
	class Entity2d_Metric1;
	class Entity2d_Metric2;
	class Entity3d_Metric1;

	template<class T> struct point_type_from_metric {};

	template<> struct point_type_from_metric<Entity2d_Metric1> { typedef Pnt2d ptType; };
	template<> struct point_type_from_metric<Entity2d_Metric2> { typedef Pnt2d ptType; };

	template<class T> struct metric_type_from_point {};

	template<> struct metric_type_from_point<Pnt2d> { typedef Entity2d_Metric1 metricType; };
	template<> struct metric_type_from_point<Pnt3d> { typedef Entity3d_Metric1 metricType; };

	template<class T> struct metric2_type_from_point {};

	template<> struct metric2_type_from_point<Pnt2d> { typedef Entity2d_Metric2 metricType; };
}

#endif // !_Geo_MetricFunctionTraits_Header