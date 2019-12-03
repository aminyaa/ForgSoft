#pragma once
#ifndef _Aft3d_BndEdgeFwd_Header
#define _Aft3d_BndEdgeFwd_Header

namespace AutLib
{

	// Forward Declarations
	template<class BndEdgeTraits>
	class Aft_BndEdge;

	struct Aft3d_BndEdgeTraits;

	typedef Aft_BndEdge<Aft3d_BndEdgeTraits>
		Aft3d_BndEdge;
}

#endif // !_Aft3d_BndEdgeFwd_Header
