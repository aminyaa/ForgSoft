#pragma once
#ifndef _Aft3d_ElementTraits_Header
#define _Aft3d_ElementTraits_Header

#include <Entity_Connectivity.hxx>
#include <Aft3d_NodeFwd.hxx>
#include <Aft3d_EdgeFwd.hxx>
#include <Aft3d_FacetFwd.hxx>
#include <Aft3d_ElementFwd.hxx>

namespace tnbLib
{

	struct Aft3d_ElementTraits
	{

		typedef Aft3d_Node nodeType;
		typedef Aft3d_Edge edgeType;
		typedef Aft3d_Facet facetType;
		typedef Aft3d_Element elementType;

		typedef connectivity::quadruple connectType;
	};
}

#endif // !_Aft3d_ElementTraits_Header