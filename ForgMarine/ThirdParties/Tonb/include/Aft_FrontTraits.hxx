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

namespace tnbLib
{

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
}

#endif // !_Aft_FrontTraits_Header
