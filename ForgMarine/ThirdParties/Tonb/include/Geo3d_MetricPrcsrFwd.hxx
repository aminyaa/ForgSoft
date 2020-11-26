#pragma once
#ifndef _Geo3d_MetricPrcsrFwd_Header
#define _Geo3d_MetricPrcsrFwd_Header

#include <Geo3d_SizeFunctionFwd.hxx>

namespace tnbLib
{

	// Forward Declarations
	template<class SizeFun, class MetricFun>
	class Geo_MetricPrcsr;

	typedef Geo_MetricPrcsr<Geo3d_SizeFunction, void>
		Geo3d_MetricPrcsr;
}

#endif // !_Geo3d_MetricPrcsrFwd_Header