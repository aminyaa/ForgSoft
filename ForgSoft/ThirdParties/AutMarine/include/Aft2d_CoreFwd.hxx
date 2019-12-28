#pragma once
#ifndef _Aft2d_CoreFwd_Header
#define _Aft2d_CoreFwd_Header

#include <Aft2d_EdgeFwd.hxx>
#include <Geo2d_SizeFunctionFwd.hxx>
#include <Geo2d_MetricFunctionFwd.hxx>
#include <Aft2d_FrontInfoFwd.hxx>
#include <Aft2d_FrontGlobalDataFwd.hxx>
#include <Aft2d_OptNode_CalculatorFwd.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class OptNodeAlg, class SizeFun, class FrontInfo, class FrontData, class MetricFun>
	class Aft_Core;

	typedef Aft_Core<Aft2d_OptNode_Calculator, Geo2d_SizeFunction, Aft2d_FrontInfo, Aft2d_FrontGlobalData, void>
		Aft2d_Core;
}

#endif // !_Aft2d_CoreFwd_Header
