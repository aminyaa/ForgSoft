#pragma once
#ifndef _Aft3d_NodeTraits_Header
#define _Aft3d_NodeTraits_Header

#include <Pnt3d.hxx>
#include <Aft3d_EdgeFwd.hxx>
#include <Aft3d_ElementFwd.hxx>
#include <Aft3d_FacetFwd.hxx>
#include <Aft_NodeType.hxx>

namespace AutLib
{

	struct Aft3d_NodeTraits
	{

		typedef Aft3d_Edge edgeType;
		typedef Aft3d_Element elementType;
		typedef Aft3d_Facet facetType;

		static const Aft_NodeType nType = Aft_NodeType_Iso;

		typedef Pnt3d ptType;
	};
}

#endif // !_Aft3d_NodeTraits_Header