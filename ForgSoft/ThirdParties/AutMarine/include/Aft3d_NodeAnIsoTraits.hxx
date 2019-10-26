#pragma once
#ifndef _Aft3d_NodeAnIsoTraits_Header
#define _Aft3d_NodeAnIsoTraits_Header

#include <Pnt3d.hxx>
#include <Aft3d_EdgeAnIsoFwd.hxx>
#include <Aft3d_ElementAnIsoFwd.hxx>
#include <Aft3d_FacetFwd.hxx>
#include <Aft_NodeType.hxx>

namespace AutLib
{

	struct Aft3d_NodeAnIsoTraits
	{

		typedef Aft3d_EdgeAnIso edgeType;
		typedef Aft3d_ElementAnIso elementType;
		typedef Aft3d_Facet facetType;

		static const Aft_NodeType nType = Aft_NodeType_AnIso;

		typedef Pnt3d ptType;
	};
}

#endif // !_Aft3d_NodeAnIsoTraits_Header
