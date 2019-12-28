#pragma once
#ifndef _Aft3d_EdgeAnIsoFwd_Header
#define _Aft3d_EdgeAnIsoFwd_Header

namespace AutLib
{

	// Forward Declarations

	struct Aft3d_EdgeAnIsoTraits;

	template<class EdgeTraits>
	class Aft_Edge;

	typedef Aft_Edge<Aft3d_EdgeAnIsoTraits> Aft3d_EdgeAnIso;
}

#endif // !_Aft3d_EdgeAnIsoFwd_Header