#pragma once
#ifndef _Aft2d_CornerNodeAnIso_Header
#define _Aft2d_CornerNodeAnIso_Header

#include <Mesh_TBndNode.hxx>
#include <Aft2d_TBndNodeAnIsoTraits.hxx>

namespace tnbLib
{

	typedef Mesh_TBndNode<Aft2d_TBndNodeAnIsoTraits, Mesh_BndNode_Position_Corner>
		Aft2d_CornerNodeAnIso;
}

#endif // !_Aft2d_CornerNodeAnIso_Header