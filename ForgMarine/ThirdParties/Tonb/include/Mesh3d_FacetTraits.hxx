#pragma once
#ifndef _Mesh3d_FacetTraits_Header
#define _Mesh3d_FacetTraits_Header

#include <Mesh3d_ElementFwd.hxx>
#include <Mesh3d_FacetFwd.hxx>
#include <Mesh3d_EdgeFwd.hxx>
#include <Mesh3d_NodeFwd.hxx>
#include <Entity_Connectivity.hxx>

namespace tnbLib
{

	struct Mesh3d_FacetTraits
	{

		typedef Mesh3d_Element elementType;
		typedef Mesh3d_Facet facetType;
		typedef Mesh3d_Edge edgeType;
		typedef Mesh3d_Node nodeType;

		typedef connectivity::triple connectType;
	};
}

#endif // !_Mesh3d_FacetTraits_Header