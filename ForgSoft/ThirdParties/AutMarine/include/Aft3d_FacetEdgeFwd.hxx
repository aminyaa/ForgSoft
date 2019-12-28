#pragma once
#ifndef _Aft3d_FacetEdgeFwd_Header
#define _Aft3d_FacetEdgeFwd_Header

#include <Mesh_BndEdge_Position.hxx>

namespace AutLib
{
	// Forward Declarations
	template<class BndEdgeTraits, Mesh_BndEdge_Position POS>
	class Aft_TBndEdge;

	struct Aft3d_FacetEdgeTraits;

	typedef Aft_TBndEdge<Aft3d_FacetEdgeTraits, Mesh_BndEdge_Position_Facet>
		Aft3d_FacetEdge;
}

#endif // !_Aft3d_FacetEdgeFwd_Header
