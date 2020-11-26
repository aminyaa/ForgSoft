#pragma once
#ifndef _Geo2d_MetricPrcsrAnIso_Header
#define _Geo2d_MetricPrcsrAnIso_Header

#include <Geo_MetricPrcsr.hxx>
#include <Geo2d_SizeFunction.hxx>
#include <Geo2d_MetricFunction.hxx>
#include <Entity2d_Metric1.hxx>

namespace tnbLib
{
	typedef Geo_MetricPrcsr<Geo2d_SizeFunction, Geo2d_MetricFunction>
		Geo2d_MetricPrcsrAnIso;

	template<>
	Standard_Real Geo2d_MetricPrcsrAnIso::CalcDistance(const Pnt2d& theP0, const Pnt2d& theP1) const;

	template<>
	Standard_Real Geo2d_MetricPrcsrAnIso::CalcUnitDistance(const Pnt2d& theP0, const Pnt2d& theP1) const;
}

#endif // !_Geo2d_MetricPrcsrAnIso_Header
