#pragma once
#ifndef _Aft2d_OptNodeSurface_Calculator_Header
#define _Aft2d_OptNodeSurface_Calculator_Header

#include <Aft_OptNode_Calculator.hxx>
#include <Aft2d_EdgeSurface.hxx>
#include <Geo2d_SizeFunction.hxx>
#include <Geo2d_MetricFunction.hxx>

namespace AutLib
{

	typedef Aft_OptNode_Calculator<Aft2d_EdgeSurface, Geo2d_SizeFunction, Geo2d_MetricFunction>
		Aft2d_OptNodeSurface_Calculator;
}

#endif // !_Aft2d_OptNodeSurface_Calculator_Header
