#pragma once
#ifndef _Aft2d_gSegmentEdge_Header
#define _Aft2d_gSegmentEdge_Header

#include <Mesh_TBndEdge.hxx>
#include <Aft2d_gBndEdgeSurfaceTraits.hxx>

namespace tnbLib
{
	typedef Mesh_TBndEdge<Aft2d_gBndEdgeSurfaceTraits, Mesh_BndEdge_Position_Segment>
		Aft2d_gSegmentEdge;

	template<>
	static std::vector<std::shared_ptr<Aft2d_gSegmentEdge>>
		Aft2d_gSegmentEdge::GetTopology
		(
			const Entity2d_Chain& theChain,
			const std::shared_ptr<typename Aft2d_gBndEdgeSurfaceTraits::curveType>& theCurve
		);

	template<>
	static void Aft2d_gSegmentEdge::MergeDangles
	(
		const std::vector<std::shared_ptr<Aft2d_gSegmentEdge>>& theWire,
		const Standard_Real theTol
	);

}

#endif // !_Aft2d_gSegmentEdge_Header