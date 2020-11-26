#pragma once
#ifndef _Aft3d_ElementAnIsoTraits_Header
#define _Aft3d_ElementAnIsoTraits_Header

#include <Entity_Connectivity.hxx>
#include <Aft3d_NodeAnIsoFwd.hxx>
#include <Aft3d_EdgeAnIsoFwd.hxx>
#include <Aft3d_FacetAnIsoFwd.hxx>
#include <Aft3d_ElementAnIsoFwd.hxx>

namespace tnbLib
{

	struct Aft3d_ElementAnIsoTraits
	{

		typedef Aft3d_NodeAnIso nodeType;
		typedef Aft3d_EdgeAnIso edgeType;
		typedef Aft3d_FacetAnIso facetType;
		typedef Aft3d_ElementAnIso elementType;

		typedef connectivity::quadruple connectType;
	};
}

#endif // !_Aft3d_ElementAnIsoTraits_Header