#pragma once
#ifndef _Aft2d_EdgeAnIsoTraits_Header
#define _Aft2d_EdgeAnIsoTraits_Header

#include <Aft2d_NodeAnIso.hxx>
#include <Aft2d_ElementAnIsoFwd.hxx>

namespace AutLib
{

	struct Aft2d_EdgeAnIsoTraits
	{

		typedef Aft2d_NodeAnIso nodeType;
		typedef void facetType;
		typedef Aft2d_ElementAnIso elementType;

		static constexpr bool geomInfo = true;
	};
}

#endif // !_Aft2d_EdgeAnIsoTraits_Header