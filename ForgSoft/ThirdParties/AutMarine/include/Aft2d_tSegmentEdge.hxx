#pragma once
#ifndef _Aft2d_tSegmentEdge_Header
#define _Aft2d_tSegmentEdge_Header

#include <Aft_TBndEdge.hxx>
#include <Aft2d_tBndEdgeSurfaceTraits.hxx>

namespace AutLib
{
	typedef Aft_TBndEdge<Aft2d_tBndEdgeSurfaceTraits, Mesh_BndEdge_Position_Segment>
		Aft2d_tSegmentEdge;

	template<>
	static std::vector<std::shared_ptr<Aft2d_tSegmentEdge>>
		Aft2d_tSegmentEdge::GetTopology
		(
			const Entity2d_Chain& theChain,
			const std::shared_ptr<typename Aft2d_tBndEdgeSurfaceTraits::curveType>& theCurve
		);

	template<>
	static void Aft2d_tSegmentEdge::MergeDangles
	(
		const std::vector<std::shared_ptr<Aft2d_tSegmentEdge>>& theWire,
		const Standard_Real theTol
	);
}

#endif // !_Aft2d_tSegmentEdge_Header
