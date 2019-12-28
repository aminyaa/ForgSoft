#pragma once
#ifndef _Aft2d_BndEdgeSurface_Header
#define _Aft2d_BndEdgeSurface_Header

#include <Aft_BndEdge.hxx>
#include <Aft2d_BndEdgeSurfaceTraits.hxx>
#include <Aft2d_BndNodeSurface.hxx>

namespace AutLib
{
	typedef Aft_BndEdge<Aft2d_BndEdgeSurfaceTraits>
		Aft2d_BndEdgeSurface;
}

#endif // !_Aft2d_BndEdgeSurface_Header