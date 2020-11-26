#pragma once
#ifndef _Mesh_NodeAdaptor_Header
#define _Mesh_NodeAdaptor_Header

#include <Mesh_EntityAdaptorM.hxx>

namespace tnbLib
{

	Mesh_EntityToEntityAdaptor(Node, BoundaryEdge, EdgeType);
	Mesh_EntityToEntityAdaptor(Node, BoundaryFacet, FacetType);

	Mesh_EntityToEntityAdaptor(Node, Edge, EdgeType);
	Mesh_EntityToEntityAdaptor(Node, Facet, FacetType);
	Mesh_EntityToEntityAdaptor(Node, Element, ElementType);

	template<class EdgeType, class ElementType, class FacetType = void>
	class Mesh_NodeAdaptor
		: public Mesh_NodeToEdgeAdaptor<EdgeType>
		, public Mesh_NodeToFacetAdaptor<FacetType>
		, public Mesh_NodeToElementAdaptor<ElementType>
	{

		/*Private Data*/

	public:

		typedef Mesh_NodeToEdgeAdaptor<EdgeType> edgeAdaptor;
		typedef Mesh_NodeToFacetAdaptor<FacetType> facetAdaptor;
		typedef Mesh_NodeToElementAdaptor<ElementType> elementAdaptor;

		Mesh_NodeAdaptor()
		{}
	};

	template<class EdgeType, class FacetType>
	class Mesh_NodeAdaptor<EdgeType, void, FacetType>
		: public Mesh_NodeToBoundaryEdgeAdaptor<EdgeType>
		, public Mesh_NodeToBoundaryFacetAdaptor<FacetType>
	{

		/*Private Data*/

	public:

		typedef Mesh_NodeToBoundaryEdgeAdaptor<EdgeType> edgeAdaptor;
		typedef Mesh_NodeToBoundaryFacetAdaptor<FacetType> facetAdaptor;

		Mesh_NodeAdaptor()
		{}
	};

	template<class EdgeType, class ElementType>
	class Mesh_NodeAdaptor<EdgeType, ElementType, void>
		: public Mesh_NodeToEdgeAdaptor<EdgeType>
		, public Mesh_NodeToElementAdaptor<ElementType>
	{

		/*Private Data*/

	public:

		typedef Mesh_NodeToEdgeAdaptor<EdgeType> edgeAdaptor;
		typedef Mesh_NodeToElementAdaptor<ElementType> elementAdaptor;

		Mesh_NodeAdaptor()
		{}
	};

	template<class EdgeType>
	class Mesh_NodeAdaptor<EdgeType, void, void>
		: public Mesh_NodeToBoundaryEdgeAdaptor<EdgeType>
	{

		/*Private Data*/

	public:

		typedef Mesh_NodeToBoundaryEdgeAdaptor<EdgeType> edgeAdaptor;

		Mesh_NodeAdaptor()
		{}
	};
}

#endif // !_Mesh_NodeAdaptor_Header
