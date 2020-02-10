#pragma once
#ifndef _Geo3d_SizeFunctionFwd_Header
#define _Geo3d_SizeFunctionFwd_Header

namespace tnbLib
{

	// Forward Declarations
	template<class Point>
	class Geo_SizeFunction;

	class Pnt3d;

	typedef Geo_SizeFunction<Pnt3d> Geo3d_SizeFunction;
}

#endif // !_Geo3d_SizeFunctionFwd_Header