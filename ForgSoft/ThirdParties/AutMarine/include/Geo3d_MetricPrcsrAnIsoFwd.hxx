#pragma once
#ifndef _Geo3d_MetricPrcsrAnIsoFwd_Header
#define _Geo3d_MetricPrcsrAnIsoFwd_Header

#include <Geo3d_SizeFunctionFwd.hxx>
#include <Geo3d_MetricFunctionFwd.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class SizeFun, class MetricFun>
	class Geo_MetricPrcsr;

	typedef Geo_MetricPrcsr<Geo3d_SizeFunction, Geo3d_MetricFunction>
		Geo3d_MetricPrcsrAnIso;
}

#endif // !_Geo3d_MetricPrcsrAnIsoFwd_Header
