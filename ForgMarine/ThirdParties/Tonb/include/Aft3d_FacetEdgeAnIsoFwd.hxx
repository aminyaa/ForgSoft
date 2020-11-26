#pragma once
#ifndef _Aft3d_FacetEdgeAnIsoFwd_Header
#define _Aft3d_FacetEdgeAnIsoFwd_Header

#include <Mesh_BndEdge_Position.hxx>

namespace tnbLib
{
	// Forward Declarations
	template<class BndEdgeTraits, Mesh_BndEdge_Position POS>
	class Mesh_TBndEdge;

	struct Aft3d_FacetEdgeAnIsoTraits;

	typedef Mesh_TBndEdge<Aft3d_FacetEdgeAnIsoTraits, Mesh_BndEdge_Position_Facet>
		Aft3d_FacetAnIsoEdge;
}

#endif // !_Aft3d_FacetEdgeAnIsoFwd_Header