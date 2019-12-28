#pragma once
#ifndef _Aft2d_BndEdgeAnIsoTraits_Header
#define _Aft2d_BndEdgeAnIsoTraits_Header

#include <Aft2d_EdgeAnIso.hxx>
#include <Aft2d_BndNodeAnIso.hxx>

namespace AutLib
{

	struct Aft2d_BndEdgeAnIsoTraits
	{
		typedef Aft2d_BndNodeAnIso nodeType;
		typedef Aft2d_EdgeAnIso edgeType;
		typedef void facetType;
	};
}

#endif // !_Aft2d_BndEdgeAnIsoTraits_Header
