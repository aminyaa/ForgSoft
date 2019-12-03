#pragma once
#ifndef _Aft_TBndNode_Header
#define _Aft_TBndNode_Header

#include <Aft_BndNode.hxx>
#include <Mesh_BndNode_Position.hxx>
#include <Mesh_BndNodeGeomAdaptor.hxx>

namespace AutLib
{

	template<class TBndNodeTraits, Mesh_BndNode_Position POS = Mesh_BndNode_Position_Corner>
	class Aft_TBndNode
		: public Aft_BndNode<typename TBndNodeTraits::bndNodeTraits>
		, public Mesh_BndNodeGeomAdaptor
		<
		typename TBndNodeTraits::curveType,
		typename TBndNodeTraits::surfType, POS
		>
	{

		/*Private Data*/

	public:

		typedef Aft_BndNode<typename TBndNodeTraits::bndNodeTraits> base;

		Aft_TBndNode()
		{}

		Aft_TBndNode
		(
			const Standard_Integer theIndex
		)
			: Aft_BndNode<typename TBndNodeTraits::bndNodeTraits>(theIndex)
		{}

		Aft_TBndNode
		(
			const Standard_Integer theIndex,
			const typename Aft_BndNode<typename TBndNodeTraits::bndNodeTraits>::Point& theCoord
		)
			: Aft_BndNode<typename TBndNodeTraits::bndNodeTraits>(theIndex, theCoord)
		{}

		//- Static functions and operators

		static std::shared_ptr<Aft_TBndNode>
			MergeNodes
			(
				const std::shared_ptr<Aft_TBndNode>& theNode0,
				const std::shared_ptr<Aft_TBndNode>& theNode1,
				const typename base::base::Merge_Alg theAlg
			);
	};
}

#endif // !_Aft_TBndNode_Header
