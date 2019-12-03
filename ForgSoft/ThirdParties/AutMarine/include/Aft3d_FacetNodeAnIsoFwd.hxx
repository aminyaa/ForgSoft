#pragma once
#ifndef _Aft3d_FacetNodeAnIsoFwd_Header
#define _Aft3d_FacetNodeAnIsoFwd_Header

#include <Mesh_BndNode_Position.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class BndNodeTraits, Mesh_BndNode_Position POS>
	class Aft_TBndNode;

	struct Aft3d_FacetNodeAnIsoTraits;

	typedef Aft_TBndNode<Aft3d_FacetNodeAnIsoTraits, Mesh_BndNode_Position_Facet>
		Aft3d_FacetNodeAnIso;
}

#endif // !_Aft3d_FacetNodeAnIsoFwd_Header
