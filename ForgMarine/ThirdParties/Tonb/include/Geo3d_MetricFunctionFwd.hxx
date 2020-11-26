#pragma once
#ifndef _Geo3d_MetricFunctionFwd_Header
#define _Geo3d_MetricFunctionFwd_Header

namespace tnbLib
{

	// Forward Declarations
	template<class Point>
	class Geo_MetricFunction;

	class Pnt3d;

	typedef Geo_MetricFunction<Pnt3d> Geo3d_MetricFunction;
}

#endif // !_Geo3d_MetricFunctionFwd_Header