#pragma once
#ifndef _Geo2d_PrimShape_Header
#define _Geo2d_PrimShape_Header

#include <Entity2d_Triangulation.hxx>
#include <Geo_PrimShape.hxx>


namespace AutLib
{

	typedef Geo_PrimShape<Pnt2d, connectivity::triple>
		Geo2d_PrimShape;
}

#endif // !_Geo2d_PrimShape_Header
