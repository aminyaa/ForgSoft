#pragma once
#ifndef _Aft2d_MetricPrcsrAnIsoFwd_Header
#define _Aft2d_MetricPrcsrAnIsoFwd_Header

#include <Aft2d_EdgeAnIsoFwd.hxx>
#include <Geo2d_SizeFunctionFwd.hxx>
#include <Geo2d_MetricFunctionFwd.hxx>
#include <Entity2d_BoxFwd.hxx>

namespace tnbLib
{

	// Forward Declarations
	template<class FrontType, class SizeFun, class MetricFun>
	class Aft_MetricPrcsr;

	typedef Aft_MetricPrcsr<Aft2d_EdgeAnIso, Geo2d_SizeFunction, Geo2d_MetricFunction>
		Aft2d_MetricPrcsrAnIso;
}

#endif // !_Aft2d_MetricPrcsrAnIsoFwd_Header
