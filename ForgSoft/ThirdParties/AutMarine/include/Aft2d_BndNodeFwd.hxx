#pragma once
#ifndef _Aft2d_BndNodeFwd_Header
#define _Aft2d_BndNodeFwd_Header

namespace AutLib
{

	// Forward Declarations
	template<class BndNodeTraits>
	class Aft_BndNode;

	struct Aft2d_BndNodeTraits;

	typedef Aft_BndNode<Aft2d_BndNodeTraits>
		Aft2d_BndNode;
}

#endif // !_Aft2d_BndNodeFwd_Header