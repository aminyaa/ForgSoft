#pragma once
#ifndef _Aft3d_EdgeTraits_Header
#define _Aft3d_EdgeTraits_Header

#include <Aft3d_Node.hxx>
#include <Aft3d_FacetFwd.hxx>
#include <Aft3d_ElementFwd.hxx>

namespace tnbLib
{

	struct Aft3d_EdgeTraits
	{

		typedef Aft3d_Node nodeType;
		typedef Aft3d_Facet facetType;
		typedef Aft3d_Element elementType;

		static constexpr bool geomInfo = false;
	};
}

#endif // !_Aft3d_EdgeTraits_Header