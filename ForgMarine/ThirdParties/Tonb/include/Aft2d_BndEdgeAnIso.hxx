#pragma once
#ifndef _Aft2d_BndEdgeAnIso_Header
#define _Aft2d_BndEdgeAnIso_Header

#include <Mesh_BndEdge.hxx>
#include <Aft2d_BndEdgeAnIsoTraits.hxx>

namespace tnbLib
{
	typedef Mesh_BndEdge<Aft2d_BndEdgeAnIsoTraits>
		Aft2d_BndEdgeAnIso;
}

#endif // !_Aft2d_BndEdgeAnIso_Header