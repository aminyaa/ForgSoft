#pragma once
#ifndef _Aft2d_EdgeSurfaceTraits_Header
#define _Aft2d_EdgeSurfaceTraits_Header

#include <Aft2d_NodeSurface.hxx>
#include <Aft2d_ElementSurfaceFwd.hxx>

namespace AutLib
{

	struct Aft2d_EdgeSurfaceTraits
	{

		typedef Aft2d_NodeSurface nodeType;
		typedef void facetType;
		typedef Aft2d_ElementSurface elementType;

		static constexpr bool geomType = true;
	};
}

#endif // !_Aft2d_EdgeSurfaceTraits_Header