#pragma once
#ifndef _Aft2d_BndEdge_Header
#define _Aft2d_BndEdge_Header

#include <Mesh_BndEdge.hxx>
#include <Aft2d_BndEdgeTraits.hxx>

namespace tnbLib
{
	typedef Mesh_BndEdge<Aft2d_BndEdgeTraits>
		Aft2d_BndEdge;
}

#endif // !_Aft2d_BndEdge_Header