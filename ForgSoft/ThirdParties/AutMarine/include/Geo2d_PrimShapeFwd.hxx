#pragma once
#ifndef _Geo2d_PrimShapeFwd_Header
#define _Geo2d_PrimShapeFwd_Header

#include <Entity_Connectivity.hxx>

namespace AutLib
{

	// Forward Declarations

	template<class Point, class ConnectType>
	class Geo_PrimShape;

	class Pnt2d;

	typedef Geo_PrimShape<Pnt2d, connectivity::dual>
		Geo2d_PrimShape;

}

#endif // !_Geo2d_PrimShapeFwd_Header
