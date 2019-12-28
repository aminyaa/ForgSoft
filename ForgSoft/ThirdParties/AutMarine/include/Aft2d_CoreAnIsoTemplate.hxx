#pragma once
#ifndef _Aft2d_CoreAnIsoTemplate_Header
#define _Aft2d_CoreAnIsoTemplate_Header

#include <Aft_Core.hxx>
#include <Aft2d_FrontAnIsoInfo.hxx>
#include <Aft2d_FrontAnIsoGlobalData.hxx>

namespace AutLib
{

	template<class OptNodeAlg, class SizeFun, class MetricFun>
	using Aft2d_CoreAnIsoTemplate = Aft_Core<OptNodeAlg, SizeFun, Aft2d_FrontAnIsoInfo, Aft2d_FrontAnIsoGlobalData, MetricFun>;
}

#endif // !_Aft2d_CoreAnIsoTemplate_Header
