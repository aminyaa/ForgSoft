#pragma once
#ifndef _Geo2d_MetricFunctionFwd_Header
#define _Geo2d_MetricFunctionFwd_Header

namespace tnbLib
{

	// Forward Declarations
	template<class Point>
	class Geo_MetricFunction;

	class Pnt2d;

	typedef Geo_MetricFunction<Pnt2d> Geo2d_MetricFunction;
}

#endif // !_Geo2d_MetricFunctionFwd_Header