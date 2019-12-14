#pragma once
#ifndef _Aft2d_SegmentEdge_Header
#define _Aft2d_SegmentEdge_Header

#include <Aft_TBndEdge.hxx>
#include <Aft2d_TBndEdgeTraits.hxx>

namespace AutLib
{
	typedef Aft_TBndEdge<Aft2d_TBndEdgeTraits, Mesh_BndEdge_Position_Segment>
		Aft2d_SegmentEdge;

	template<>
	static std::vector<std::shared_ptr<Aft2d_SegmentEdge>>
		Aft2d_SegmentEdge::GetTopology
		(
			const Entity2d_Chain& theChain, 
			const std::shared_ptr<typename Aft2d_TBndEdgeTraits::curveType>& theCurve
		);

	template<>
	static void Aft2d_SegmentEdge::MergeDangles
	(
		const std::vector<std::shared_ptr<Aft2d_SegmentEdge>>& theWire,
		const Standard_Real theTol
	);
}

#endif // !_Aft2d_SegmentEdge_Header
