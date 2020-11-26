#pragma once
#ifndef _Geo2d_MetricPrcsrFwd_Header
#define _Geo2d_MetricPrcsrFwd_Header

#include <Geo2d_SizeFunctionFwd.hxx>

namespace tnbLib
{

	// Forward Declarations
	template<class SizeFun, class MetricFun>
	class Geo_MetricPrcsr;

	typedef Geo_MetricPrcsr<Geo2d_SizeFunction, void>
		Geo2d_MetricPrcsr;
}

#endif // !_Geo2d_MetricPrcsrFwd_Header