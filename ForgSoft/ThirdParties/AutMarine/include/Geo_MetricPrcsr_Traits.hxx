#pragma once
#ifndef _Geo_MetricPrcsr_Traits_Header
#define _Geo_MetricPrcsr_Traits_Header

#include <Geo2d_MetricFunctionFwd.hxx>
#include <Geo3d_MetricFunctionFwd.hxx>

namespace AutLib
{

	// Forward Declarations
	class Numeric_AdaptIntegrationInfo;
	class Geo_MetricPrcsrAnIso_Info;

	template<class MetricFun> struct geo_metric_processor_info_type{};

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
		typedef Numeric_AdaptIntegrationInfo type;
	};

}

#endif // !_Geo_MetricPrcsr_Traits_Header
