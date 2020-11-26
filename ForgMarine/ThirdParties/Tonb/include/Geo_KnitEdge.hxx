#pragma once
#ifndef _Geo_KnitEdge_Header
#define _Geo_KnitEdge_Header

#include <Geo_GraphEdge.hxx>

namespace tnbLib
{

	template<class EdgeTraits>
	using Geo_KnitEdge = Geo_GraphEdge<EdgeTraits>;
}

#endif // !_Geo_KnitEdge_Header
