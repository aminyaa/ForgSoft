#pragma once
#ifndef _Aft3d_OptNodeAnIso_CalculatorFwd_Header
#define _Aft3d_OptNodeAnIso_CalculatorFwd_Header

#include <Aft3d_FacetAnIsoFwd.hxx>
#include <Geo3d_SizeFunctionFwd.hxx>
#include <Geo3d_MetricFunctionFwd.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class FrontType, class SizeFun, class MetricFun>
	class Aft_OptNode_Calculator;

	typedef Aft_OptNode_Calculator<Aft3d_FacetAnIso, Geo3d_SizeFunction, Geo3d_MetricFunction>
		Aft3d_OptNodeAnIso_Calculator;
}

#endif // !_Aft3d_OptNodeAnIso_CalculatorFwd_Header
