#pragma once
#ifndef _Aft3d_EdgeFwd_Header
#define _Aft3d_EdgeFwd_Header

namespace tnbLib
{

	// Forward Declarations

	struct Aft3d_EdgeTraits;

	template<class EdgeTraits>
	class Aft_Edge;

	typedef Aft_Edge<Aft3d_EdgeTraits> Aft3d_Edge;
}

#endif // !_Aft3d_EdgeFwd_Header