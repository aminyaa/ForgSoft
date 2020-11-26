#pragma once
#ifndef _Aft2d_SegmentNodeAnIso_Header
#define _Aft2d_SegmentNodeAnIso_Header

#include <Mesh_TBndNode.hxx>
#include <Aft2d_TBndNodeAnIsoTraits.hxx>

namespace tnbLib
{

	typedef Mesh_TBndNode<Aft2d_TBndNodeAnIsoTraits, Mesh_BndNode_Position_Segment>
		Aft2d_SegmentNodeAnIso;
}

#endif // !_Aft2d_SegmentNodeAnIso_Header