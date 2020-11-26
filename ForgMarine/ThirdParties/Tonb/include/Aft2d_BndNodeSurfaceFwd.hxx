#pragma once
#ifndef _Aft2d_BndNodeSurfaceFwd_Header
#define _Aft2d_BndNodeSurfaceFwd_Header

namespace tnbLib
{

	// Forward Declaration
	template<class BndNodeTraits>
	class Aft_BndNode;

	struct Aft2d_BndNodeSurfaceTraits;

	typedef Aft_BndNode<Aft2d_BndNodeSurfaceTraits>
		Aft2d_BndNodeSurface;
}

#endif // !_Aft2d_BndNodeSurfaceFwd_Header