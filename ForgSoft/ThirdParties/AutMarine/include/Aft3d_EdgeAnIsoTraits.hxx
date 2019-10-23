#pragma once
#ifndef _Aft3d_EdgeAnIsoTraits_Header
#define _Aft3d_EdgeAnIsoTraits_Header

#include <Aft3d_NodeAnIso.hxx>
#include <Aft3d_FacetAnIsoFwd.hxx>
#include <Aft3d_ElementAnIsoFwd.hxx>

namespace AutLib
{

	struct Aft3d_EdgeAnIsoTraits
	{

		typedef Aft3d_NodeAnIso nodeType;
		typedef Aft3d_Facet facetType;
		typedef Aft3d_ElementAnIso elementType;

		static constexpr bool geomInfo = false;
	};
}

#endif // !_Aft3d_EdgeAnIsoTraits_Header