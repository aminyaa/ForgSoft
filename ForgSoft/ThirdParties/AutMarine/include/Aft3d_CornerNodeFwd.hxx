#pragma once
#ifndef _Aft3d_CornerNodeFwd_Header
#define _Aft3d_CornerNodeFwd_Header

#include <Mesh_BndNode_Position.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class BndNodeTraits, Mesh_BndNode_Position POS>
	class Aft_TBndNode;

	struct Aft3d_TBndNodeTraits;

	typedef Aft_TBndNode<Aft3d_TBndNodeTraits, Mesh_BndNode_Position_Corner>
		Aft3d_CornerNode;
}

#endif // !_Aft3d_CornerNodeFwd_Header