#pragma once
#ifndef _Mesh2d_EdgeTraits_Header
#define _Mesh2d_EdgeTraits_Header

#include <Mesh2d_Node.hxx>
#include <Mesh2d_ElementFwd.hxx>

namespace AutLib
{

	struct Mesh2d_EdgeTraits
	{

		typedef Mesh2d_Node nodeType;
		typedef void facetType;
		typedef Mesh2d_Element elementType;
	};
}

#endif // !_Mesh2d_EdgeTraits_Header
