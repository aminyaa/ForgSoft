#pragma once
#ifndef _Aft2d_MetricPrcsrSurface_Header
#define _Aft2d_MetricPrcsrSurface_Header

#include <Aft_MetricPrcsr.hxx>
#include <Aft2d_EdgeSurface.hxx>
#include <Geo2d_SizeFunction.hxx>
#include <Geo2d_MetricFunction.hxx>
#include <Entity2d_BoxFwd.hxx>

namespace AutLib
{

	typedef Aft_MetricPrcsr<Aft2d_EdgeSurface, Geo2d_SizeFunction, Geo2d_MetricFunction>
		Aft2d_MetricPrcsrSurface;

	template<>
	Entity2d_Box Aft2d_MetricPrcsrSurface::CalcSearchRegion
	(
		const Standard_Real theRadius,
		const Entity2d_Metric1& theMetric,
		const Pnt2d& theCentre
	) const;

	template<>
	Entity2d_Box Aft2d_MetricPrcsrSurface::CalcSearchRegion
	(
		const Standard_Real theRaius,
		const Pnt2d& theCentre,
		const Aft2d_EdgeSurface& theFront
	) const;

	template<>
	Entity2d_Box Aft2d_MetricPrcsrSurface::CalcSearchRegion
	(
		const Standard_Real theRaius,
		const Aft2d_EdgeSurface& theFront
	) const;

	template<>
	Entity2d_Box Aft2d_MetricPrcsrSurface::CalcEffectiveFront
	(
		const Standard_Real theRadius,
		const Pnt2d& theCentre,
		const Aft2d_EdgeSurface& theFront
	) const;
}

#endif // !_Aft2d_MetricPrcsrSurface_Header
