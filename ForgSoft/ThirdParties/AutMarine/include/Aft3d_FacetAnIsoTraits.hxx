#pragma once
#ifndef _Aft3d_FacetAnIsoTraits_Header
#define _Aft3d_FacetAnIsoTraits_Header

#include <Aft3d_NodeAnIsoFwd.hxx>
#include <Aft3d_EdgeAnIsoFwd.hxx>
#include <Aft3d_FacetAnIsoFwd.hxx>
#include <Aft3d_ElementAnIsoFwd.hxx>

namespace AutLib
{

	struct Aft3d_FacetAnIsoTraits
	{

		typedef Aft3d_NodeAnIso nodeType;
		typedef Aft3d_EdgeAnIso edgeType;
		typedef Aft3d_FacetAnIso facetType;
		typedef Aft3d_ElementAnIso elementType;
	};
}

#endif // !_Aft3d_FacetAnIsoTraits_Header
