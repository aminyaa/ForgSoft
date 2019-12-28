#pragma once
#ifndef _Mesh2d_KnitChainFwd_Header
#define _Mesh2d_KnitChainFwd_Header

#include <Mesh2d_KnitTraits.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class KnitTraits>
	class Knit_Chain;

	typedef Knit_Chain<Mesh2d_KnitTraits>
		Mesh2d_KnitChain;
}

#endif // !_Mesh2d_KnitChainFwd_Header
