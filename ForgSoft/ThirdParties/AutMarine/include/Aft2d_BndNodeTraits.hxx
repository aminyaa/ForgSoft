#pragma once
#ifndef _Aft2d_BndNodeTraits_Header
#define _Aft2d_BndNodeTraits_Header

#include <Aft2d_BndEdgeFwd.hxx>
#include <Aft2d_Node.hxx>

namespace AutLib
{

	struct Aft2d_BndNodeTraits
	{
		typedef Aft2d_BndEdge edgeType;
		typedef Aft2d_Node nodeType;
		typedef void facetType;
	};
}

#endif // !_Aft2d_BndNodeTraits_Header
