#pragma once
#ifndef _Mesh2d_ElementTraits_Header
#define _Mesh2d_ElementTraits_Header

#include <Mesh2d_ElementFwd.hxx>
#include <Mesh2d_EdgeFwd.hxx>
#include <Mesh2d_NodeFwd.hxx>
#include <Entity_Connectivity.hxx>

namespace tnbLib
{

	struct Mesh2d_ElementTraits
	{

		typedef Mesh2d_Element elementType;
		typedef void facetType;
		typedef Mesh2d_Edge edgeType;
		typedef Mesh2d_Node nodeType;

		typedef connectivity::triple connectType;
	};
}

#endif // !_Mesh2d_ElementTraits_Header