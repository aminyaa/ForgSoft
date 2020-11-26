#pragma once
#ifndef _Aft2d_BndEdgeSurfaceFwd_Header
#define _Aft2d_BndEdgeSurfaceFwd_Header

namespace tnbLib
{
	// Forward Declarations
	template<class BndEdgeTraits>
	class Aft_BndEdge;

	struct Aft2d_BndEdgeSurfaceTraits;

	typedef Aft_BndEdge<Aft2d_BndEdgeSurfaceTraits>
		Aft2d_BndEdgeSurface;
}

#endif // !_Aft2d_BndEdgeSurfaceFwd_Header