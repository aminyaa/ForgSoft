#pragma once
#ifndef _Aft2d_ElementSurfaceFwd_Header
#define _Aft2d_ElementSurfaceFwd_Header

#include <Aft_Element.hxx>

namespace AutLib
{

	// Forward Declarations

	struct Aft2d_ElementSurfaceTraits;

	typedef Aft_Element<Aft2d_ElementSurfaceTraits, Mesh_ElementType_Triangle2D>
		Aft2d_ElementSurface;
}

#endif // !_Aft3d_ElementSurfaceFwd_Header