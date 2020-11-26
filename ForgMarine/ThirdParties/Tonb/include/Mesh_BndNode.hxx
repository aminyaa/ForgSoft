#pragma once
#ifndef _Mesh_BndNode_Header
#define _Mesh_BndNode_Header

#include <Mesh_NodeAdaptor.hxx>

namespace tnbLib
{

	template<class BndNodeTraits>
	class Mesh_BndNode
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

		Mesh_BndNode()
		{}

		Mesh_BndNode
		(
			const Standard_Integer theIndex
		)
			: nodeType(theIndex)
		{}

		Mesh_BndNode
		(
			const Standard_Integer theIndex,
			const Point& theCoord
		)
			: nodeType(theIndex, theCoord)
		{}
	};
}

#endif // !_Mesh_BndNode_Header
