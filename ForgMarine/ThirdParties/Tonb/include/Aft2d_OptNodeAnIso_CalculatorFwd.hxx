#pragma once
#ifndef _Aft2d_OptNodeAnIso_CalculatorFwd_Header
#define _Aft2d_OptNodeAnIso_CalculatorFwd_Header

#include <Aft2d_EdgeAnIsoFwd.hxx>
#include <Geo2d_SizeFunctionFwd.hxx>
#include <Geo2d_MetricFunctionFwd.hxx>

namespace tnbLib
{

	// Forward Declarations
	template<class FrontType, class SizeFun, class MetricFun>
	class Aft_OptNode_Calculator;

	typedef Aft_OptNode_Calculator<Aft2d_EdgeAnIso, Geo2d_SizeFunction, Geo2d_MetricFunction>
		Aft2d_OptNodeAnIso_Calculator;
}

#endif // !_Aft2d_OptNodeAnIso_CalculatorFwd_Header