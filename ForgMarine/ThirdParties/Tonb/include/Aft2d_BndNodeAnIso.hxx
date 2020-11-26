#pragma once
#ifndef _Aft2d_BndNodeAnIso_Header
#define _Aft2d_BndNodeAnIso_Header

#include <Mesh_BndNode.hxx>
#include <Aft2d_BndNodeAnIsoTraits.hxx>

namespace tnbLib
{

	typedef Mesh_BndNode<Aft2d_BndNodeAnIsoTraits>
		Aft2d_BndNodeAnIso;
}

#endif // !_Aft2d_BndNodeAnIso_Header