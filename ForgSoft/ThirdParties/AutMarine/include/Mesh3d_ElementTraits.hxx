#pragma once
#ifndef _Mesh3d_ElementTraits_Header
#define _Mesh3d_ElementTraits_Header

#include <Mesh3d_ElementFwd.hxx>
#include <Mesh3d_FacetFwd.hxx>
#include <Mesh3d_EdgeFwd.hxx>
#include <Mesh3d_NodeFwd.hxx>
#include <Entity_Connectivity.hxx>

namespace AutLib
{

	struct Mesh3d_ElementTraits
	{

		typedef Mesh3d_Element elementType;
		typedef Mesh3d_Facet facetType;
		typedef Mesh3d_Edge edgeType;
		typedef Mesh3d_Node nodeType;

		typedef connectivity::quadruple connectType;
	};
}

#endif // !_Mesh3d_ElementTraits_Header
