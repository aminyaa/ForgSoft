#pragma once
#ifndef _Aft2d_BndEdgeTraits_Header
#define _Aft2d_BndEdgeTraits_Header

#include <Aft2d_Edge.hxx>
#include <Aft2d_BndNode.hxx>

namespace AutLib
{

	struct Aft2d_BndEdgeTraits
	{
		typedef Aft2d_BndNode nodeType;
		typedef Aft2d_Edge edgeType;
		typedef void facetType;
	};
}

#endif // !_Aft2d_BndEdgeTraits_Header
