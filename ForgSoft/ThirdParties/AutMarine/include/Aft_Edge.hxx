#pragma once
#ifndef _Aft_Edge_Header
#define _Aft_Edge_Header

#include <Mesh_Edge.hxx>
#include <Mesh_EdgeAdaptor.hxx>
#include <Aft_EntityIdentifier.hxx>

#include <vector>

namespace AutLib
{

	template<class EdgeTraits>
	class Aft_Edge
		: public Mesh_Edge<EdgeTraits>
		, public Aft_EntityIdentifier<typename EdgeTraits::nodeType, (bool)EdgeTraits::geomInfo>
	{

		/*Private Data*/

	public:

		typedef Mesh_Edge<EdgeTraits> base;

		typedef typename EdgeTraits::nodeType nodeType;
		typedef std::shared_ptr<nodeType> node_ptr;
		typedef typename nodeType::ptType Point;

		template< bool cond, typename U >
		using resolvedType = typename std::enable_if< cond, U >::type;

		enum
		{
			nbNodes = 2
		};

		Aft_Edge()
		{}

		Aft_Edge(const Standard_Integer theIndex)
			: base(theIndex)
		{}

		Aft_Edge
		(
			const Standard_Integer theIndex,
			const node_ptr& theNode0,
			const node_ptr& theNode1
		)
			: base(theIndex, theNode0, theNode1)
		{}

		Standard_Integer NbNodes() const
		{
			return (Standard_Integer)nbNodes;
		}

		Standard_Real SearchRadius() const
		{
			Debug_Null_Pointer(base::Node0());
			Debug_Null_Pointer(base::Node1());

			return MAX
			(
				base::Node0()->Radius(),
				base::Node1()->Radius()
			);
		}

		void Reverse();

		//- Static functions and operators

		static Standard_Boolean IsOnFront(const std::shared_ptr<Aft_Edge>& theEdge)
		{
			Debug_Null_Pointer(theEdge);
			return theEdge->Node0()->IsOnFrontEdges(theEdge->Index());
		}

		static Standard_Boolean IsLess
		(
			const std::shared_ptr<Aft_Edge>& theEdge0,
			const std::shared_ptr<Aft_Edge>& theEdge1
		)
		{
			Debug_Null_Pointer(theEdge0);
			Debug_Null_Pointer(theEdge1);
			return theEdge0->Index() < theEdge1->Index();
		}

		static Standard_Boolean IsLess
		(
			const std::weak_ptr<Aft_Edge>& theEdge0,
			const std::weak_ptr<Aft_Edge>& theEdge1
		)
		{
			Debug_Null_Pointer(theEdge0.lock());
			Debug_Null_Pointer(theEdge1.lock());
			return theEdge0.lock()->Index() < theEdge1.lock()->Index();
		}

		static Standard_Real Length(const std::shared_ptr<Aft_Edge>& theEdge)
		{
			Debug_Null_Pointer(theEdge);
			return theEdge->CharLength();
		}

		static std::vector<std::shared_ptr<nodeType>> RetrieveNodes
		(
			const std::vector<std::shared_ptr<Aft_Edge>>& theEdges
		);


	};
}

#include <Aft_EdgeI.hxx>

#endif // !_Aft_Edge_Header