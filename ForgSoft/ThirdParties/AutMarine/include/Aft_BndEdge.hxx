#pragma once
#ifndef _Aft_BndEdge_Header
#define _Aft_BndEdge_Header

#include <Mesh_EdgeAdaptor.hxx>

namespace AutLib
{

	template<class BndEdgeTraits>
	class Aft_BndEdge
		: public Mesh_EdgeAdaptor<void, typename BndEdgeTraits::facetType>
		, public BndEdgeTraits::edgeType
	{

		/*Private Data*/

	public:

		typedef typename BndEdgeTraits::edgeType edgeType;
		typedef typename edgeType::nodeType nodeType;
		typedef typename BndEdgeTraits::nodeType bndNodeType;

		Aft_BndEdge()
		{}

		Aft_BndEdge
		(
			const Standard_Integer theIndex
		)
			: edgeType(theIndex)
		{}

		Aft_BndEdge
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<nodeType>& theNode0,
			const std::shared_ptr<nodeType>& theNode1
		)
			: edgeType(theIndex, theNode0, theNode1)
		{}
	};
}

#include <Aft_BndEdgeI.hxx>

#endif // !_Aft_BndEdge_Header
