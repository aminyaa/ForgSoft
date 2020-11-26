#pragma once
#ifndef _Aft3d_OptNode_CalculatorFwd_Header
#define _Aft3d_OptNode_CalculatorFwd_Header

#include <Aft3d_FacetFwd.hxx>
#include <Geo3d_SizeFunctionFwd.hxx>


namespace tnbLib
{

	// Forward Declarations
	template<class FrontType, class SizeFun, class MetricFun>
	class Aft_OptNode_Calculator;

	typedef Aft_OptNode_Calculator<Aft3d_Facet, Geo3d_SizeFunction, void>
		Aft3d_OptNode_Calculator;
}

#endif // !_Aft3d_OptNode_CalculatorFwd_Header