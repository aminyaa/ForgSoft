#pragma once
#ifndef _Mesh2d_KnitChain_Header
#define _Mesh2d_KnitChain_Header

#include <Knit_Chain.hxx>
#include <Mesh2d_KnitTraits.hxx>
#include <Mesh2d_KnitNode.hxx>
#include <Mesh2d_KnitEdge.hxx>

namespace AutLib
{

	typedef Knit_Chain<Mesh2d_KnitTraits>
		Mesh2d_KnitChain;
}

#endif // !_Mesh2d_KnitChain_Header
