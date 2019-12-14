#pragma once
#ifndef _Aft2d_CoreSurface_Header
#define _Aft2d_CoreSurface_Header

#include <Aft_Core.hxx>
#include <Aft2d_FrontSurfaceInfo.hxx>
#include <Aft2d_FrontSurfaceGlobalData.hxx>
#include <Geo2d_SizeFunction.hxx>
#include <Geo2d_MetricFunction.hxx>
#include <Aft2d_OptNodeSurface_Calculator.hxx>

namespace AutLib
{

	typedef Aft_Core
		<
		Aft2d_OptNodeSurface_Calculator,
		Geo2d_SizeFunction, 
		Aft2d_FrontSurfaceInfo, 
		Aft2d_FrontSurfaceGlobalData
		> Aft2d_CoreSurface;
}

#endif // !_Aft2d_CoreSurface_Header
