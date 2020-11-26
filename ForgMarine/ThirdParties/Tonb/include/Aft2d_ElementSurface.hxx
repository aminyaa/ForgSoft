#pragma once
#ifndef _Aft2d_ElementSurface_Header
#define _Aft2d_ElementSurface_Header

#include <Aft_Element.hxx>
#include <Aft2d_ElementSurfaceTraits.hxx>

namespace tnbLib
{

	typedef Aft_Element
		<
		Aft2d_ElementSurfaceTraits,
		Mesh_ElementType_Triangle2D
		> Aft2d_ElementSurface;
}

#endif // !_Aft2d_ElementSurface_Header