#pragma once
#ifndef _Aft3d_FacetTraits_Header
#define _Aft3d_FacetTraits_Header

#include <Aft3d_NodeFwd.hxx>
#include <Aft3d_EdgeFwd.hxx>
#include <Aft3d_FacetFwd.hxx>
#include <Aft3d_ElementFwd.hxx>

namespace AutLib
{

	struct Aft3d_FacetTraits
	{

		typedef Aft3d_Node nodeType;
		typedef Aft3d_Edge edgeType;
		typedef Aft3d_Facet facetType;
		typedef Aft3d_Element elementType;
	};
}

#endif // !_Aft3d_FacetTraits_Header