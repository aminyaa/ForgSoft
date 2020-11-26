#pragma once
#ifndef _Aft3d_FacetNodeAnIsoFwd_Header
#define _Aft3d_FacetNodeAnIsoFwd_Header

#include <Mesh_BndNode_Position.hxx>

namespace tnbLib
{

	// Forward Declarations
	template<class BndNodeTraits, Mesh_BndNode_Position POS>
	class Mesh_TBndNode;

	struct Aft3d_FacetNodeAnIsoTraits;

	typedef Mesh_TBndNode<Aft3d_FacetNodeAnIsoTraits, Mesh_BndNode_Position_Facet>
		Aft3d_FacetNodeAnIso;
}

#endif // !_Aft3d_FacetNodeAnIsoFwd_Header