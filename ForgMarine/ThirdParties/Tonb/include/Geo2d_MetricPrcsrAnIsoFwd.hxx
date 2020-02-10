#pragma once
#ifndef _Geo2d_MetricPrcsrAnIsoFwd_Header
#define _Geo2d_MetricPrcsrAnIsoFwd_Header

#include <Geo2d_SizeFunctionFwd.hxx>
#include <Geo2d_MetricFunctionFwd.hxx>

namespace tnbLib
{

	// Forward Declarations
	template<class SizeFun, class MetricFun>
	class Geo_MetricPrcsr;

	typedef Geo_MetricPrcsr<Geo2d_SizeFunction, Geo2d_MetricFunction>
		Geo2d_MetricPrcsrAnIso;
}

#endif // !_Geo2d_MetricPrcsrAnIsoFwd_Header