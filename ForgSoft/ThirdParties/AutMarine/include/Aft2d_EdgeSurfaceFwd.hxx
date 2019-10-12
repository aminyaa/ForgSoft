#pragma once
#ifndef _Aft2d_EdgeSurfaceFwd_Header
#define _Aft2d_EdgeSurfaceFwd_Header

namespace AutLib
{

	// Forward Declarations

	struct Aft2d_EdgeSurfaceTraits;

	template<class EdgeTraits>
	class Aft_Edge;

	typedef Aft_Edge<Aft2d_EdgeSurfaceTraits> Aft2d_EdgeSurface;
}

#endif // !_Aft2d_EdgeSurfaceFwd_Header
