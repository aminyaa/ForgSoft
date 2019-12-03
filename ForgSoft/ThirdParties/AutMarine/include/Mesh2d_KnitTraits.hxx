#pragma once
#ifndef _Mesh2d_KnitTraits_Header
#define _Mesh2d_KnitTraits_Header

#include <Mesh2d_KnitNodeFwd.hxx>
#include <Mesh2d_KnitEdgeFwd.hxx>

namespace AutLib
{

	struct Mesh2d_KnitTraits
	{

		typedef Mesh2d_KnitNode nodeType;
		typedef Mesh2d_KnitEdge edgeType;

	};
}

#endif // !_Mesh2d_KnitTraits_Header
