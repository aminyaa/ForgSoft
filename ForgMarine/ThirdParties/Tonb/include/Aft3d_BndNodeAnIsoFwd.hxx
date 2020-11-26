#pragma once
#ifndef _Aft3d_BndNodeAnIsoFwd_Header
#define _Aft3d_BndNodeAnIsoFwd_Header

namespace tnbLib
{

	// Forward Declaration
	template<class BndNodeTraits>
	class Aft_BndNode;

	struct Aft3d_BndNodeAnIsoTraits;

	typedef Aft_BndNode<Aft3d_BndNodeAnIsoTraits>
		Aft3d_BndNodeAnIso;
}

#endif // !_Aft3d_BndNodeAnIsoFwd_Header