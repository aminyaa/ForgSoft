#pragma once
#ifndef _Aft3d_OptNodeAnIso_Calculator_Header
#define _Aft3d_OptNodeAnIso_Calculator_Header

#include <Aft_OptNode_Calculator.hxx>
#include <Aft3d_FacetAnIso.hxx>
#include <Geo3d_SizeFunction.hxx>
#include <Geo3d_MetricFunction.hxx>

namespace AutLib
{

	typedef Aft_OptNode_Calculator<Aft3d_FacetAnIso, Geo3d_SizeFunction, Geo3d_MetricFunction>
		Aft3d_OptNodeAnIso_Calculator;
}

#endif // !_Aft3d_OptNodeAnIso_Calculator_Header
