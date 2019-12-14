#pragma once
#ifndef _Aft2d_ElementTraits_Header
#define _Aft2d_ElementTraits_Header

#include <Entity_Connectivity.hxx>
#include <Aft2d_NodeFwd.hxx>
#include <Aft2d_EdgeFwd.hxx>
#include <Aft2d_ElementFwd.hxx>

namespace AutLib
{

	struct Aft2d_ElementTraits
	{

		typedef Aft2d_Node nodeType;
		typedef Aft2d_Edge edgeType;
		typedef void facetType;
		typedef Aft2d_Element elementType;

		typedef connectivity::triple connectType;
	};
}

#endif // !_Aft2d_ElementTraits_Header