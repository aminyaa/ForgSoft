#pragma once
#ifndef _Aft_NodeAdaptor_Header
#define _Aft_NodeAdaptor_Header

#include <Mesh_NodeAdaptor.hxx>

namespace tnbLib
{

	Mesh_EntityToEntityAdaptor(Node, FrontEdge, EdgeType);
	Mesh_EntityToEntityAdaptor(Node, FrontFacet, FacetType);

	template<class EdgeType, class ElementType, class FacetType = void>
	class Aft_NodeAdaptor
		: public Mesh_NodeToFrontEdgeAdaptor<EdgeType>
		, public Mesh_NodeToFrontFacetAdaptor<FacetType>
	{

		/*Private Data*/

	public:

		typedef Mesh_NodeAdaptor<EdgeType, ElementType, FacetType> meshAdaptor;
		typedef Mesh_NodeToFrontEdgeAdaptor<EdgeType> frontEdgeAdaptor;
		typedef Mesh_NodeToFrontFacetAdaptor<FacetType> frontFacetAdaptor;

		Aft_NodeAdaptor()
		{}
	};


	template<class EdgeType, class ElementType>
	class Aft_NodeAdaptor<EdgeType, ElementType, void>
		: public Mesh_NodeToFrontEdgeAdaptor<EdgeType>
	{

		/*Private Data*/

	public:

		typedef Mesh_NodeAdaptor<EdgeType, ElementType> meshAdaptor;
		typedef Mesh_NodeToFrontEdgeAdaptor<EdgeType> frontEdgeAdaptor;

		Aft_NodeAdaptor()
		{}
	};
}

#endif // !_Aft_NodeAdaptor_Header