#pragma once
#ifndef _Aft2d_BndNodeSurface_Header
#define _Aft2d_BndNodeSurface_Header

#include <Mesh_BndNode.hxx>
#include <Aft2d_BndNodeSurfaceTraits.hxx>

namespace tnbLib
{

	typedef Mesh_BndNode<Aft2d_BndNodeSurfaceTraits>
		Aft2d_BndNodeSurface;
}

#endif // !_Aft2d_BndNodeSurface_Header