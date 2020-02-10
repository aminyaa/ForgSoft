#pragma once
#ifndef _GeoMetricFun2d_Uniform_Header
#define _GeoMetricFun2d_Uniform_Header

#include <Pnt2d.hxx>
#include <Entity2d_Metric1.hxx>
#include <Entity2d_Metric2.hxx>
#include <GeoMetricFun_Uniform.hxx>

namespace tnbLib
{

	typedef GeoMetricFun_Uniform<Pnt2d>
		GeoMetricFun2d_Uniform;
}

#endif // !_GeoMetricFun2d_Uniform_Header