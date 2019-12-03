#pragma once
#ifndef _Aft2d_BndNodeSurface_Header
#define _Aft2d_BndNodeSurface_Header

#include <Aft_BndNode.hxx>
#include <Aft2d_BndNodeSurfaceTraits.hxx>

namespace AutLib
{

	typedef Aft_BndNode<Aft2d_BndNodeSurfaceTraits>
		Aft2d_BndNodeSurface;
}

#endif // !_Aft2d_BndNodeSurface_Header