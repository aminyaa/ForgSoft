#pragma once
#ifndef _Mesh3d_EdgeTraits_Header
#define _Mesh3d_EdgeTraits_Header

#include <Mesh3d_Node.hxx>
#include <Mesh3d_FacetFwd.hxx>
#include <Mesh3d_ElementFwd.hxx>

namespace AutLib
{

	struct Mesh3d_EdgeTraits
	{

		typedef Mesh3d_Node nodeType;
		typedef Mesh3d_Facet facetType;
		typedef Mesh3d_Element elementType;
	};
}

#endif // !_Mesh3d_EdgeTraits_Header
