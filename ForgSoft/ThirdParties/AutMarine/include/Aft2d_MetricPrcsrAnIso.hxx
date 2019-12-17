#pragma once
#ifndef _Aft2d_MetricPrcsrAnIso_Header
#define _Aft2d_MetricPrcsrAnIso_Header

#include <Aft_MetricPrcsr.hxx>
#include <Aft2d_EdgeAnIso.hxx>
#include <Geo2d_SizeFunction.hxx>
#include <Geo2d_MetricFunction.hxx>
#include <Geo2d_MetricPrcsrAnIso.hxx>
#include <Entity2d_BoxFwd.hxx>

namespace AutLib
{

	// Forward Declarations
	class Entity2d_Metric1;

	typedef Aft_MetricPrcsr<Aft2d_EdgeAnIso, Geo2d_SizeFunction, Geo2d_MetricFunction>
		Aft2d_MetricPrcsrAnIso;

	template<>
	Entity2d_Box Aft2d_MetricPrcsrAnIso::CalcSearchRegion
	(
		const Standard_Real theRadius,
		const Entity2d_Metric1& theMetric, 
		const Pnt2d& theCentre
	) const;

	template<>
	Entity2d_Box Aft2d_MetricPrcsrAnIso::CalcSearchRegion
	(
		const Standard_Real theRadius, 
		const Pnt2d& theCentre, 
		const Aft2d_EdgeAnIso& theFront
	) const;

	template<>
	Entity2d_Box Aft2d_MetricPrcsrAnIso::CalcSearchRegion
	(
		const Standard_Real theRadius,
		const Aft2d_EdgeAnIso& theFront
	) const;

	template<>
	Entity2d_Box Aft2d_MetricPrcsrAnIso::CalcEffectiveFront
	(
		const Standard_Real theRadius, 
		const Pnt2d& theCentre, 
		const Aft2d_EdgeAnIso& theFront
	) const;
}

#endif // !_Aft2d_MetricPrcsrAnIso_Header
