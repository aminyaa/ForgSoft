#pragma once
#ifndef _Aft2d_ElementAnIsoTraits_Header
#define _Aft2d_ElementAnIsoTraits_Header

#include <Entity_Connectivity.hxx>
#include <Aft2d_NodeAnIsoFwd.hxx>
#include <Aft2d_EdgeAnIsoFwd.hxx>
#include <Aft2d_ElementAnIsoFwd.hxx>

namespace tnbLib
{

	struct Aft2d_ElementAnIsoTraits
	{

		typedef Aft2d_NodeAnIso nodeType;
		typedef Aft2d_EdgeAnIso edgeType;
		typedef void facetType;
		typedef Aft2d_ElementAnIso elementType;

		typedef connectivity::triple connectType;
	};
}

#endif // !_Aft2d_ElementAnIsoTraits_Header