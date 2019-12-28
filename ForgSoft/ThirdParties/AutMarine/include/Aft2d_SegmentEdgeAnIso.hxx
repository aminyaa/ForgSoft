#pragma once
#ifndef _Aft2d_SegmentEdgeAnIso_Header
#define _Aft2d_SegmentEdgeAnIso_Header

#include <Aft_TBndEdge.hxx>
#include <Aft2d_TBndEdgeAnIsoTraits.hxx>

namespace AutLib
{
	typedef Aft_TBndEdge<Aft2d_TBndEdgeAnIsoTraits, Mesh_BndEdge_Position_Segment>
		Aft2d_SegmentEdgeAnIso;

	template<>
	static std::vector<std::shared_ptr<Aft2d_SegmentEdgeAnIso>>
		Aft2d_SegmentEdgeAnIso::GetTopology
		(
			const Entity2d_Chain& theChain,
			const std::shared_ptr<typename Aft2d_TBndEdgeAnIsoTraits::curveType>& theCurve
		);

	template<>
	static void Aft2d_SegmentEdgeAnIso::MergeDangles
	(
		const std::vector<std::shared_ptr<Aft2d_SegmentEdgeAnIso>>& theWire,
		const Standard_Real theTol
	);
}

#endif // !_Aft2d_SegmentEdgeAnIso_Header
