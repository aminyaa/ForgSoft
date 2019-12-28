#pragma once
#ifndef _Aft2d_NodeTraits_Header
#define _Aft2d_NodeTraits_Header

#include <Pnt2d.hxx>
#include <Aft2d_EdgeFwd.hxx>
#include <Aft2d_ElementFwd.hxx>
#include <Aft_NodeType.hxx>

namespace AutLib
{

	struct Aft2d_NodeTraits
	{

		typedef Aft2d_Edge edgeType;
		typedef Aft2d_Element elementType;
		typedef void facetType;

		static const Aft_NodeType nType = Aft_NodeType_Iso;

		typedef Pnt2d ptType;
	};
}

#endif // !_Aft2d_NodeTraits_Header