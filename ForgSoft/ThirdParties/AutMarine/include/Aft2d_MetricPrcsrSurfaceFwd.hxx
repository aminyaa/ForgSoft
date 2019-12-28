#pragma once
#ifndef _Aft2d_MetricPrcsrSurfaceFwd_Header
#define _Aft2d_MetricPrcsrSurfaceFwd_Header

#include <Aft2d_EdgeSurfaceFwd.hxx>
#include <Geo2d_SizeFunctionFwd.hxx>
#include <Geo2d_MetricFunctionFwd.hxx>
#include <Entity2d_BoxFwd.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class FrontType, class SizeFun, class MetricFun>
	class Aft_MetricPrcsr;

	typedef Aft_MetricPrcsr<Aft2d_EdgeSurface, Geo2d_SizeFunction, Geo2d_MetricFunction>
		Aft2d_MetricPrcsrSurface;
}

#endif // !_Aft2d_MetricPrcsrSurfaceFwd_Header
