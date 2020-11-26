#pragma once
#ifndef _Mesh_TBndEdge_Header
#define _Mesh_TBndEdge_Header

#include <Mesh_BndEdge.hxx>
#include <Mesh_BndEdgeAdaptor.hxx>
#include <Entity2d_ChainFwd.hxx>

#include <vector>

namespace tnbLib
{

	template<class TBndEdgeTraits, Mesh_BndEdge_Position POS = Mesh_BndEdge_Position_Segment>
	class Mesh_TBndEdge
		: public Mesh_BndEdgeAdaptor
		<
		typename TBndEdgeTraits::curveType,
		typename TBndEdgeTraits::surfType,
		typename TBndEdgeTraits::bndEdgeTraits::facetType,
		typename TBndEdgeTraits::metricPrcsr, POS
		>
		, public Mesh_BndEdge<typename TBndEdgeTraits::bndEdgeTraits>
	{

		/*Private Data*/

	public:

		typedef Mesh_BndEdge<typename TBndEdgeTraits::bndEdgeTraits> bndEdgeType;
		typedef TBndEdgeTraits traitsType;
		typedef typename TBndEdgeTraits::metricPrcsr metricPrcsr;

		Mesh_TBndEdge()
		{}

		Mesh_TBndEdge
		(
			const Standard_Integer theIndex
		)
			: Mesh_BndEdge<typename TBndEdgeTraits::bndEdgeTraits>(theIndex)
		{}

		Mesh_TBndEdge
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<typename Mesh_BndEdge<typename TBndEdgeTraits::bndEdgeTraits>::nodeType>& theNode0,
			const std::shared_ptr<typename Mesh_BndEdge<typename TBndEdgeTraits::bndEdgeTraits>::nodeType>& theNode1
		)
			: Mesh_BndEdge<typename TBndEdgeTraits::bndEdgeTraits>(theIndex, theNode0, theNode1)
		{}


		//- static functions and operators

		static std::vector<std::shared_ptr<Mesh_TBndEdge>>
			GetTopology
			(
				const Entity2d_Chain& theChain,
				const std::shared_ptr<typename TBndEdgeTraits::curveType>& theCurve
			);

		static void MergeDangles
		(
			const std::vector<std::shared_ptr<Mesh_TBndEdge>>& theWire,
			const Standard_Real theTol
		);

		static std::vector<std::shared_ptr<typename TBndEdgeTraits::bndEdgeTraits::edgeType>>
			UpCast
			(
				const std::vector<std::shared_ptr<Mesh_TBndEdge>>& theEdges
			);


	};
}

#include <Mesh_TBndEdgeI.hxx>

#endif // !_Mesh_TBndEdge_Header
