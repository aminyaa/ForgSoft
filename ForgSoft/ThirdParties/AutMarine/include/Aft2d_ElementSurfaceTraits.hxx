#pragma once
#ifndef _Aft2d_ElementSurfaceTraits_Header
#define _Aft2d_ElementSurfaceTraits_Header

#include <Entity_Connectivity.hxx>
#include <Aft2d_NodeSurfaceFwd.hxx>
#include <Aft2d_EdgeSurfaceFwd.hxx>
#include <Aft2d_ElementSurfaceFwd.hxx>

namespace AutLib
{

	struct Aft2d_ElementSurfaceTraits
	{

		typedef Aft2d_NodeSurface nodeType;
		typedef Aft2d_EdgeSurface edgeType;
		typedef void facetType;
		typedef Aft2d_ElementSurface elementTypa;

		typedef connectivity::triple connectType;
	};
}

#endif // !_Aft2d_ElementSurfaceTraits_Header