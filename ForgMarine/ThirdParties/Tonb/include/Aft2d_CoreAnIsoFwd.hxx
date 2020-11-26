#pragma once
#ifndef _Aft2d_CoreAnIsoFwd_Header
#define _Aft2d_CoreAnIsoFwd_Header

#include <Aft2d_FrontAnIsoInfoFwd.hxx>
#include <Aft2d_FrontAnIsoGlobalDataFwd.hxx>
#include <Geo2d_SizeFunctionFwd.hxx>
#include <Geo2d_MetricFunctionFwd.hxx>
#include <Aft2d_OptNodeAnIso_CalculatorFwd.hxx>

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
		Aft2d_OptNodeAnIso_Calculator,
		Geo2d_SizeFunction,
		Aft2d_FrontAnIsoInfo,
		Aft2d_FrontAnIsoGlobalData,
		Geo2d_MetricFunction
		> Aft2d_CoreAnIso;
}

#endif // !_Aft2d_CoreAnIsoFwd_Header