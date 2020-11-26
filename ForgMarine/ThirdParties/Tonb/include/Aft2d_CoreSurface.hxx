#pragma once
#ifndef _Aft2d_CoreSurface_Header
#define _Aft2d_CoreSurface_Header

#include <Aft2d_CoreSurfaceTemplate.hxx>
#include <Geo2d_SizeFunction.hxx>
#include <Geo2d_MetricFunction.hxx>
#include <Aft2d_OptNodeSurface_Calculator.hxx>

namespace tnbLib
{

	typedef Aft2d_CoreSurfaceTemplate
		<
		Aft2d_OptNodeSurface_Calculator,
		Geo2d_SizeFunction,
		Geo2d_MetricFunction
		> Aft2d_CoreSurface;
}

#endif // !_Aft2d_CoreSurface_Header