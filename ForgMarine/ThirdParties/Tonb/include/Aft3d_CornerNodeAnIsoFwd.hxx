#pragma once
#ifndef _Aft3d_CornerNodeAnIsoFwd_Header
#define _Aft3d_CornerNodeAnIsoFwd_Header

#include <Mesh_BndNode_Position.hxx>

namespace tnbLib
{

	// Forward Declarations
	template<class BndNodeTraits, Mesh_BndNode_Position POS>
	class Mesh_TBndNode;

	struct Aft3d_CornerNodeAnIsoTraits;

	typedef Mesh_TBndNode<Aft3d_CornerNodeAnIsoTraits, Mesh_BndNode_Position_Corner>
		Aft3d_CornerNodeAnIso;
}

#endif // !_Aft3d_CornerNodeAnIsoFwd_Header