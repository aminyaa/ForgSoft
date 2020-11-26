#pragma once
#ifndef _Aft2d_EdgeTraits_Header
#define _Aft2d_EdgeTraits_Header

#include <Aft2d_Node.hxx>
#include <Aft2d_ElementFwd.hxx>

namespace tnbLib
{

	struct Aft2d_EdgeTraits
	{

		typedef Aft2d_Node nodeType;
		typedef void facetType;
		typedef Aft2d_Element elementType;

		static constexpr bool geomInfo = true;
	};
}

#endif // !_Aft2d_EdgeTraits_Header