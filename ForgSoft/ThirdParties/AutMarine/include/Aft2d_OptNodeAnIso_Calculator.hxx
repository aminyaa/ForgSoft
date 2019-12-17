#pragma once
#ifndef _Aft2d_OptNodeAnIso_Calculator_Header
#define _Aft2d_OptNodeAnIso_Calculator_Header

#include <Aft_OptNode_Calculator.hxx>
#include <Aft2d_EdgeAnIso.hxx>
#include <Geo2d_SizeFunction.hxx>
#include <Geo2d_MetricFunction.hxx>

namespace AutLib
{

	typedef Aft_OptNode_Calculator<Aft2d_EdgeAnIso, Geo2d_SizeFunction, Geo2d_MetricFunction>
		Aft2d_OptNodeAnIso_Calculator;
}

#endif // !_Aft2d_OptNodeAnIso_Calculator_Header
