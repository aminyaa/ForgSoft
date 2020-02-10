#pragma once
#ifndef _Geo_MetricPrcsr_Traits_Header
#define _Geo_MetricPrcsr_Traits_Header

#include <Geo2d_MetricFunctionFwd.hxx>
#include <Geo3d_MetricFunctionFwd.hxx>

namespace tnbLib
{

	// Forward Declarations
	class NumAlg_AdaptiveInteg_Info;
	class Geo_MetricPrcsrAnIso_Info;

	template<class MetricFun> struct geo_metric_processor_info_type {};

	template<> struct geo_metric_processor_info_type<Geo2d_MetricFunction>
	{
		typedef Geo_MetricPrcsrAnIso_Info type;
	};

	template<> struct geo_metric_processor_info_type<Geo3d_MetricFunction>
	{
		typedef Geo_MetricPrcsrAnIso_Info type;
	};

	template<> struct geo_metric_processor_info_type<void>
	{
		typedef NumAlg_AdaptiveInteg_Info type;
	};

}

#endif // !_Geo_MetricPrcsr_Traits_Header