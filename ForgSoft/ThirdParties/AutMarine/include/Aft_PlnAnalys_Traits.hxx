#pragma once
#ifndef _Aft_PlnAnalys_Traits_Header
#define _Aft_PlnAnalys_Traits_Header

#include <Aft2d_PlnRegionFwd.hxx>
#include <Aft2d_PlnRegionAnIsoFwd.hxx>
#include <Aft2d_gPlnRegionSurfaceFwd.hxx>
#include <Aft2d_tPlnRegionSurfaceFwd.hxx>
#include <Geo2d_SizeFunctionFwd.hxx>
#include <Geo2d_MetricFunctionFwd.hxx>
#include <Aft2d_EdgeFwd.hxx>
#include <Aft2d_EdgeAnIsoFwd.hxx>
#include <Aft2d_EdgeSurface.hxx>

namespace AutLib
{

	// Forward Declarations
	class Cad2d_Plane;
	class GModel_Plane;
	class TModel_Plane;

	class Pln_Curve;
	class GModel_parCurve;
	class TModel_parCurve;

	template<class PlnType, class SizeFun, class MetricFun = void>
	struct Aft_PlnAnalys_Traits{};

	template<>
	struct Aft_PlnAnalys_Traits<Cad2d_Plane, Geo2d_SizeFunction>
	{
		typedef Pln_Curve curveType;
		typedef Aft2d_Edge frontType;

		typedef Aft2d_PlnRegion regionType;
	};

	template<>
	struct Aft_PlnAnalys_Traits<Cad2d_Plane, Geo2d_SizeFunction, Geo2d_MetricFunction>
	{
		typedef Pln_Curve curveType;
		typedef Aft2d_EdgeAnIso frontType;

		typedef Aft2d_PlnRegionAnIso regionType;
	};

	template<>
	struct Aft_PlnAnalys_Traits<GModel_Plane, Geo2d_SizeFunction, Geo2d_MetricFunction>
	{
		typedef GModel_parCurve curveType;
		typedef Aft2d_EdgeSurface frontType;

		typedef Aft2d_gPlnRegionSurface regionType;
	};

	template<>
	struct Aft_PlnAnalys_Traits<TModel_Plane, Geo2d_SizeFunction, Geo2d_MetricFunction>
	{
		typedef GModel_parCurve curveType;
		typedef Aft2d_EdgeSurface frontType;

		typedef Aft2d_tPlnRegionSurface regionType;
	};
}

#endif // !_Aft_PlnAnalys_Traits_Header
