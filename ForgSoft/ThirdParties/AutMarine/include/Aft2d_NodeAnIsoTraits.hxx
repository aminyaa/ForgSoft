#pragma once
#ifndef _Aft2d_NodeAnIsoTraits_Header
#define _Aft2d_NodeAnIsoTraits_Header

#include <Pnt2d.hxx>
#include <Aft2d_EdgeAnIsoFwd.hxx>
#include <Aft2d_ElementAnIsoFwd.hxx>
#include <Aft_NodeType.hxx>

namespace AutLib
{

	struct Aft2d_NodeAnIsoTraits
	{

		typedef Aft2d_EdgeAnIso edgeType;
		typedef Aft2d_ElementAnIso elementType;
		typedef void facetType;

		static const Aft_NodeType nType = Aft_NodeType_AnIso;

		typedef Pnt2d ptType;
	};
}

#endif // !_Aft2d_NodeAnIsoTraits_Header