#pragma once
#ifndef _Aft2d_OptNode_CalculatorFwd_Header
#define _Aft2d_OptNode_CalculatorFwd_Header

#include <Aft2d_EdgeFwd.hxx>
#include <Geo2d_SizeFunctionFwd.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class FrontType, class SizeFun, class MetricFun>
	class Aft_OptNode_Calculator;

	typedef Aft_OptNode_Calculator<Aft2d_Edge, Geo2d_SizeFunction, void>
		Aft2d_OptNode_Calculator;
}

#endif // !_Aft2d_OptNode_CalculatorFwd_Header
