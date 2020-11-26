#pragma once
#ifndef _Aft2d_BndNodeAnIsoFwd_Header
#define _Aft2d_BndNodeAnIsoFwd_Header

namespace tnbLib
{

	// Forward Declaration
	template<class BndNodeTraits>
	class Aft_BndNode;

	struct Aft2d_BndNodeAnIsoTraits;

	typedef Aft_BndNode<Aft2d_BndNodeAnIsoTraits>
		Aft2d_BndNodeAnIso;
}

#endif // !_Aft2d_BndNodeAnIsoFwd_Header