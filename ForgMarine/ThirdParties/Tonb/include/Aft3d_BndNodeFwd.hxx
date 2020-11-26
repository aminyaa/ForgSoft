#pragma once
#ifndef _Aft3d_BndNodeFwd_Header
#define _Aft3d_BndNodeFwd_Header

namespace tnbLib
{

	// Forward Declarations
	template<class BndNodeTraits>
	class Aft_BndNode;

	struct Aft3d_BndNodeTraits;

	typedef Aft_BndNode<Aft3d_BndNodeTraits>
		Aft3d_BndNode;
}

#endif // !_Aft3d_BndNodeFwd_Header