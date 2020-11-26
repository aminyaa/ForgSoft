#pragma once
#ifndef _Aft2d_CoreSurfaceFwd_Header
#define _Aft2d_CoreSurfaceFwd_Header

#include <Aft2d_FrontSurfaceInfoFwd.hxx>
#include <Aft2d_FrontSurfaceGlobalDataFwd.hxx>
#include <Geo2d_SizeFunctionFwd.hxx>
#include <Geo2d_MetricFunctionFwd.hxx>
#include <Aft2d_OptNodeSurface_CalculatorFwd.hxx>

namespace tnbLib
{

	// Forward Declarations
	template
		<
		class OptNodeAlg,
		class SizeFun,
		class FrontInfo,
		class FrontData,
		class MetricFun
		>
		class Aft_Core;

	typedef Aft_Core
		<
		Aft2d_OptNodeSurface_Calculator,
		Geo2d_SizeFunction,
		Aft2d_FrontSurfaceInfo, Aft2d_FrontSurfaceGlobalData,
		Geo2d_MetricFunction> Aft2d_CoreSurface;
}

#endif // !_Aft2d_CoreSurfaceFwd_Header