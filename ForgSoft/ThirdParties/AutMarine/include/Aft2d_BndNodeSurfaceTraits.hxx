#pragma once
#ifndef _Aft2d_BndNodeSurfaceTraits_Header
#define _Aft2d_BndNodeSurfaceTraits_Header

#include <Aft2d_BndEdgeSurfaceFwd.hxx>
#include <Aft2d_NodeSurface.hxx>

namespace AutLib
{

	struct Aft2d_BndNodeSurfaceTraits
	{
		typedef Aft2d_BndEdgeSurface edgeType;
		typedef Aft2d_NodeSurface nodeType;
		typedef void facetType;
	};
}

#endif // !_Aft2d_BndNodeSurfaceTraits_Header
