#pragma once
#ifndef _Aft2d_BndNodeAnIsoTraits_Header
#define _Aft2d_BndNodeAnIsoTraits_Header

#include <Aft2d_BndEdgeAnIsoFwd.hxx>
#include <Aft2d_NodeAnIso.hxx>

namespace tnbLib
{

	struct Aft2d_BndNodeAnIsoTraits
	{
		typedef Aft2d_BndEdgeAnIso edgeType;
		typedef Aft2d_NodeAnIso nodeType;
		typedef void facetType;
	};
}

#endif // !_Aft2d_BndNodeAnIsoTraits_Header