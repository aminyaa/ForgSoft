#pragma once
#ifndef _Mesh_TBndNode_Header
#define _Mesh_TBndNode_Header

#include <Mesh_BndNode.hxx>
#include <Mesh_BndNode_Position.hxx>
#include <Mesh_BndNodeGeomAdaptor.hxx>
#include <Mesh_BndMergeAlg.hxx>

namespace tnbLib
{

	template<class TBndNodeTraits, Mesh_BndNode_Position POS = Mesh_BndNode_Position_Corner>
	class Mesh_TBndNode
		: public Mesh_BndNode<typename TBndNodeTraits::bndNodeTraits>
		, public Mesh_BndNodeGeomAdaptor
		<
		typename TBndNodeTraits::curveType,
		typename TBndNodeTraits::surfType, POS
		>
	{

		/*Private Data*/

	public:

		typedef Mesh_BndNode<typename TBndNodeTraits::bndNodeTraits> base;

		Mesh_TBndNode()
		{}

		Mesh_TBndNode
		(
			const Standard_Integer theIndex
		)
			: Mesh_BndNode<typename TBndNodeTraits::bndNodeTraits>(theIndex)
		{}

		Mesh_TBndNode
		(
			const Standard_Integer theIndex,
			const typename Mesh_BndNode<typename TBndNodeTraits::bndNodeTraits>::Point& theCoord
		)
			: Mesh_BndNode<typename TBndNodeTraits::bndNodeTraits>(theIndex, theCoord)
		{}

		//- Static functions and operators

		static std::shared_ptr<Mesh_TBndNode>
			MergeNodes
			(
				const std::shared_ptr<Mesh_TBndNode>& theNode0,
				const std::shared_ptr<Mesh_TBndNode>& theNode1,
				const Mesh_BndMergeAlg theAlg
			);
	};
}

#include <Mesh_TBndNodeI.hxx>

#endif // !_Mesh_TBndNode_Header
