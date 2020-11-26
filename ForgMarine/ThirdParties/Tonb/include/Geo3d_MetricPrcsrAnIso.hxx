#pragma once
#ifndef _Geo3d_MetricPrcsrAnIso_Header
#define _Geo3d_MetricPrcsrAnIso_Header

#include <Geo_MetricPrcsr.hxx>
#include <Geo3d_SizeFunction.hxx>
#include <Geo3d_MetricFunction.hxx>

namespace tnbLib
{
	typedef Geo_MetricPrcsr<Geo3d_SizeFunction, Geo3d_MetricFunction>
		Geo3d_MetricPrcsrAnIso;

	template<>
	Standard_Real Geo3d_MetricPrcsrAnIso::CalcDistance(const Pnt3d& theP0, const Pnt3d& theP1) const;

	template<>
	Standard_Real Geo3d_MetricPrcsrAnIso::CalcUnitDistance(const Pnt3d& theP0, const Pnt3d& theP1) const;
}

#endif // !_Geo3d_MetricPrcsrAnIso_Header