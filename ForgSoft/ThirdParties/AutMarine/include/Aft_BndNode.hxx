#pragma once
#ifndef _Aft_BndNode_Header
#define _Aft_BndNode_Header

#include <Mesh_NodeAdaptor.hxx>

namespace AutLib
{

	template<class BndNodeTraits>
	class Aft_BndNode
		: public Mesh_NodeAdaptor
		<
		typename BndNodeTraits::edgeType,
		void,
		typename BndNodeTraits::facetType
		>
		, public BndNodeTraits::nodeType
	{

		/*Private Data*/

	public:

		typedef typename BndNodeTraits::nodeType nodeType;
		typedef typename nodeType::ptType Point;

		typedef typename BndNodeTraits::nodeType base;

		using nodeType::Merge_Alg;

		Aft_BndNode()
		{}

		Aft_BndNode
		(
			const Standard_Integer theIndex
		)
			: nodeType(theIndex)
		{}

		Aft_BndNode
		(
			const Standard_Integer theIndex,
			const Point& theCoord
		)
			: nodeType(theIndex, theCoord)
		{}
	};
}

#endif // !_Aft_BndNode_Header
