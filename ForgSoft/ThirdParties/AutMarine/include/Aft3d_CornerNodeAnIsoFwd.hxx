#pragma once
#ifndef _Aft3d_CornerNodeAnIsoFwd_Header
#define _Aft3d_CornerNodeAnIsoFwd_Header

#include <Mesh_BndNode_Position.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class BndNodeTraits, Mesh_BndNode_Position POS>
	class Aft_TBndNode;

	struct Aft3d_CornerNodeAnIsoTraits;

	typedef Aft_TBndNode<Aft3d_CornerNodeAnIsoTraits, Mesh_BndNode_Position_Corner>
		Aft3d_CornerNodeAnIso;
}

#endif // !_Aft3d_CornerNodeAnIsoFwd_Header
