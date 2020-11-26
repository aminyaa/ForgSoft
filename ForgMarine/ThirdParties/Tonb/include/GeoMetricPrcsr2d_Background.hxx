#pragma once
#ifndef _GeoMetricPrcsr2d_Background_Header
#define _GeoMetricPrcsr2d_Background_Header

#include <Geo_MetricPrcsr.hxx>
#include <Geo2d_SizeFunction.hxx>
#include <GeoMetricFun2d_Background.hxx>

namespace tnbLib
{

	typedef Geo_MetricPrcsr<Geo2d_SizeFunction, GeoMetricFun2d_Background>
		GeoMetricPrcsr2d_Background;

	template<>
	Standard_Real GeoMetricPrcsr2d_Background::CalcDistance(const Pnt2d& theP0, const Pnt2d& theP1) const;


}

#endif // !_GeoMetricPrcsr2d_Background_Header