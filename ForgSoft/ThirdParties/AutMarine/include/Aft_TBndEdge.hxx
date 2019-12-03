#pragma once
#ifndef _Aft_TBndEdge_Header
#define _Aft_TBndEdge_Header

#include <Aft_BndEdge.hxx>
#include <Aft_BndEdgeAdaptor.hxx>

namespace AutLib
{

	template<class TBndEdgeTraits, Mesh_BndEdge_Position POS = Mesh_BndEdge_Position_Segment>
	class Aft_TBndEdge
		: public Aft_BndEdgeAdaptor
		<
		typename TBndEdgeTraits::curveType,
		typename TBndEdgeTraits::surfType,
		typename TBndEdgeTraits::facetType, 
		typename TBndEdgeTraits::metricMap, POS
		>
		, public Aft_BndEdge<typename TBndEdgeTraits::bndEdgeTraits>
	{

		/*Private Data*/

	public:

		typedef Aft_BndEdge<typename TBndEdgeTraits::bndEdgeTraits> bndEdgeType;
		typedef TBndEdgeTraits traitsType;

		Aft_TBndEdge()
		{}

		Aft_TBndEdge
		(
			const Standard_Integer theIndex
		)
			: Aft_BndEdge<typename TBndEdgeTraits::bndEdgeTraits>(theIndex)
		{}

		Aft_TBndEdge
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<typename Aft_BndEdge<typename TBndEdgeTraits::bndEdgeTraits>::nodeType>& theNode0,
			const std::shared_ptr<typename Aft_BndEdge<typename TBndEdgeTraits::bndEdgeTraits>::nodeType>& theNode1
		)
			: Aft_BndEdge<typename TBndEdgeTraits::bndEdgeTraits>(theIndex, theNode0, theNode1)
		{}
	};
}

#endif // !_Aft_TBndEdge_Header
