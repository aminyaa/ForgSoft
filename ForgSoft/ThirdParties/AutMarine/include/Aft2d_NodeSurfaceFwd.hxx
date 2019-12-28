#pragma once
#ifndef _Aft2d_NodeSurfaceFwd_Header
#define _Aft2d_NodeSurfaceFwd_Header

namespace AutLib
{

	// Forward Declarations

	struct Aft2d_NodeSurfaceTraits;

	template<class NodeTraits>
	class Aft_Node;

	typedef Aft_Node<Aft2d_NodeSurfaceTraits> Aft2d_NodeSurface;
}

#endif // !_Aft2d_NodeSurfaceFwd_Header