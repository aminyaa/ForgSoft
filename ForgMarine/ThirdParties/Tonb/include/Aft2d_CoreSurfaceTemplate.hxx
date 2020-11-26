#pragma once
#ifndef _Aft2d_CoreSurfaceTemplate_Header
#define _Aft2d_CoreSurfaceTemplate_Header

#include <Aft_Core.hxx>
#include <Aft2d_FrontSurfaceInfo.hxx>
#include <Aft2d_FrontSurfaceGlobalData.hxx>

namespace tnbLib
{

	template<class OptNodeAlg, class SizeFun, class MetricFun>
	using Aft2d_CoreSurfaceTemplate = 
		Aft_Core
		<
		OptNodeAlg,
		SizeFun, Aft2d_FrontSurfaceInfo,
		Aft2d_FrontSurfaceGlobalData, MetricFun
		>;
}

#endif // !_Aft2d_CoreSurfaceTemplate_Header