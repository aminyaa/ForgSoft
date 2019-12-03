#pragma once
#ifndef _Aft2d_CoreAnIso_Header
#define _Aft2d_CoreAnIso_Header

#include <Aft_Core.hxx>
#include <Aft2d_FrontAnIsoInfo.hxx>
#include <Aft2d_FrontAnIsoGlobalData.hxx>
#include <Geo2d_SizeFunction.hxx>
#include <Geo2d_MetricFunction.hxx>
#include <Aft2d_OptNodeAnIso_Calculator.hxx>

namespace AutLib
{

	typedef Aft_Core<Aft2d_OptNodeAnIso_Calculator, Geo2d_SizeFunction, Aft2d_FrontAnIsoInfo, Aft2d_FrontAnIsoGlobalData>
		Aft2d_CoreAnIso;
}


#endif // !_Aft2d_CoreAnIso_Header
