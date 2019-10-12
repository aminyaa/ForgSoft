#pragma once
#ifndef _Aft_FrontTraits_Header
#define _Aft_FrontTraits_Header

#include <Aft2d_NodeFwd.hxx>
#include <Aft2d_EdgeFwd.hxx>
#include <Aft2d_ElementFwd.hxx>
#include <Aft2d_NodeAnIsoFwd.hxx>
#include <Aft2d_EdgeAnIsoFwd.hxx>
#include <Aft2d_ElementAnIsoFwd.hxx>
#include <Aft2d_NodeSurfaceFwd.hxx>
#include <Aft2d_EdgeSurfaceFwd.hxx>
#include <Aft2d_ElementSurfaceFwd.hxx>
#include <Aft3d_NodeFwd.hxx>
#include <Aft3d_EdgeFwd.hxx>
#include <Aft3d_FacetFwd.hxx>
#include <Aft3d_ElementFwd.hxx>
#include <Aft3d_NodeAnIsoFwd.hxx>
#include <Aft3d_EdgeAnIsoFwd.hxx>
#include <Aft3d_FacetAnIsoFwd.hxx>
#include <Aft3d_ElementAnIsoFwd.hxx>

namespace AutLib
{

	// Forward Declarations

	template<class FrontType>
	struct Aft_FrontTraits
	{};

	template<>
	struct Aft_FrontTraits<Aft2d_Edge>
	{
		typedef Aft2d_Node nodeType;
		typedef Aft2d_Edge edgeType;
		typedef Aft2d_Element elementType;
	};

	template<>
	struct Aft_FrontTraits<Aft2d_EdgeAnIso>
	{
		typedef Aft2d_NodeAnIso nodeType;
		typedef Aft2d_EdgeAnIso edgeType;
		typedef Aft2d_ElementAnIso elementType;
	};

	template<>
	struct Aft_FrontTraits<Aft2d_EdgeSurface>
	{
		typedef Aft2d_NodeSurface nodeType;
		typedef Aft2d_EdgeSurface edgeType;
		typedef Aft2d_ElementSurface elementType;
	};

	template<>
	struct Aft_FrontTraits<Aft3d_Facet>
	{
		typedef Aft3d_Node nodeType;
		typedef Aft3d_Edge edgeType;
		typedef Aft3d_Facet facetType;
		typedef Aft3d_Element elementType;
	};

	template<>
	struct Aft_FrontTraits<Aft3d_FacetAnIso>
	{
		typedef Aft3d_NodeAnIso nodeType;
		typedef Aft3d_EdgeAnIso edgeType;
		typedef Aft3d_FacetAnIso facetType;
		typedef Aft3d_ElementAnIso elementType;
	};
}

#endif // !_Aft_FrontTraits_Header